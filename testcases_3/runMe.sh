TEST_DIR=testcases_3
VAL_FLAGS='-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all'


echo LOOKING FOR TAG v3.0:
git log --decorate=full | grep tags/v3.0
echo Was the tag found?
echo

#git checkout v3.0
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

bin/main ${TEST_DIR}/Accounts_Test1.txt ${TEST_DIR}/Commands_Test1.csv > data/test1_CSV.out
diff -NBw data/test1_CSV.out ${TEST_DIR}/Test1_ExpectedOutput.txt > diff_test_1_CSV.diff 2>&1

bin/main ${TEST_DIR}/Accounts_Test5.txt ${TEST_DIR}/Commands_Test5.txt > data/test5.out
diff -NBw data/test5.out ${TEST_DIR}/Test5_ExpectedOutput.txt > diff_test_5.diff 2>&1

valgrind ${VAL_FLAGS} bin/main ${TEST_DIR}/Accounts_Test1.txt ${TEST_DIR}/Commands_Test1.txt > V_main.out 2>&1 


echo " --------------- "
pwd
grep "ERROR" V*.out
grep "lost:" V*.out
grep "reachable:" V*.out
ls -al diff_*
echo " --------------- "
cat data/test5.out