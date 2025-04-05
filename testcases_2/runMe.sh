TEST_DIR=testcases_2
VAL_FLAGS='-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all'


echo LOOKING FOR TAG v2.0:
git log --decorate=full | grep tags/v2.0
echo Was the tag found?
echo

#git checkout v2.0
make clean
make
ulimit -c 0 -t 300 -f 10000
mkdir -p data

counter=1
while [ $counter -ne 5 ]
do
	#cp ${TEST_DIR}/Accounts_Test${counter}.txt data/Accounts.txt
	#cp ${TEST_DIR}/Commands_Test${counter}.txt data/Commands.txt

	echo
	echo " ----- TEST ${counter} ------ "

	bin/main ${TEST_DIR}/Accounts_Test${counter}.txt ${TEST_DIR}/Commands_Test${counter}.txt > data/test${counter}.out

	diff -NBw data/test${counter}.out ${TEST_DIR}/Test${counter}_ExpectedOutput.txt > diff_test_${counter}.diff 2>&1

	counter=$(( counter + 1 )) 
	#exit
done


cp ${TEST_DIR}/Accounts_Test4.txt data/Accounts.txt
cp ${TEST_DIR}/Commands_Test4.txt data/Commands.txt
valgrind ${VAL_FLAGS} bin/main data/Accounts.txt data/Commands.txt  > V_main.out 2>&1 

echo " --------------- "
pwd
grep "ERROR" V*.out
grep "lost:" V*.out
grep "reachable:" V*.out
ls -al diff_*
echo " --------------- "