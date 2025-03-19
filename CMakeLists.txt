# CMakeLists.txt at the root of the project

cmake_minimum_required(VERSION 3.5)

# Name SampleClass needs to match one of the Source names in Sources.
set(This TestSuite)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
# https://cmake.org/cmake/help/latest/prop_tgt/CXX_STANDARD.html#prop_tgt:CXX_STANDARD
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)


enable_testing()
add_subdirectory(googletest)

set (Headers
    include/placeholder.h
		include/Money.h
		include/TieredInterest.h
		include/Interest.h
		include/FlatInterest.h
		include/Account.h
		include/CheckingAccount.h
		include/SavingsAccount.h
)

set (Sources
		src/Money.cpp
		src/TieredInterest.cpp
		src/Interest.cpp
		src/FlatInterest.cpp
		src/Account.cpp
		src/CheckingAccount.cpp
		src/SavingsAccount.cpp
		)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
