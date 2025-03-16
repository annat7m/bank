//***************************************************************************
// File name:   MoneyTests.cpp
// Author:      Anna Tymoshenko
// Date:        03/16/25
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Provide unit testing for Money
//***************************************************************************

#include <gtest/gtest.h>
#include <sstream>

#include "../include/Money.h"

//***************************************************************************
// Test: 				Constructor_LongLong_Positive
//
// Description: testing the constructor of the Money class that initializes
//							Money object with 
//***************************************************************************

TEST (MoneyTests, Constructor_LongLong_Positive) {
	Money amount(100);
	std::ostringstream stream;
  stream << amount;
  EXPECT_EQ(stream.str(), "100");
}

//***************************************************************************
// Test: 				Constructor_LongLong_Negative
//
// Description: testing the constructor of the Money class that initializes
//							Money object with 
//***************************************************************************

TEST (MoneyTests, Constructor_LongLong_Negative) {
	Money amount(-100);
	std::ostringstream stream;
  stream << amount;
  EXPECT_EQ(stream.str(), "-100");
}

//***************************************************************************
// Test: 				CopyConstructor
//
// Description: testing the constructor of the Money class that initializes
//							Money object with 
//***************************************************************************

TEST(MoneyConstructorTests, CopyConstructor) {
  Money original(250);
	std::ostringstream stream;
  Money copy = original;
	stream << copy;
  EXPECT_EQ(stream.str(), 250);
}