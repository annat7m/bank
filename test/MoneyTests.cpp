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

TEST (MoneyConstructorTests, Constructor_LongLong_Positive) {
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

TEST (MoneyConstructorTests, Constructor_LongLong_Negative) {
	Money amount(-100);
	std::ostringstream stream;
  stream << amount;
  EXPECT_EQ(stream.str(), "-100");
}

//***************************************************************************
// Test: 				CopyConstructor
//
// Description: testing the assignment operator of the Money object 
//***************************************************************************

TEST(MoneyConstructorTests, CopyConstructor) {
  Money original(250);
  Money copy = original;
	std::ostringstream stream;
	stream << copy;
  EXPECT_EQ(stream.str(), "250");
}

//***************************************************************************
// Test: 				SimpleAddition
//
// Description: testing the addition operator 
//***************************************************************************

TEST(MoneyArithmeticTests, SimpleAddition) {
  Money value1(250);
	Money value2(50);
	std::ostringstream stream;
	stream << value1 + value2;
  EXPECT_EQ(stream.str(), "300");
}

//***************************************************************************
// Test: 				ShortenedAddition
//
// Description: testing operator+= 
//***************************************************************************

TEST(MoneyArithmeticTests, ShortenedAddition) {
  Money value1(250);
	Money value2(50);
	std::ostringstream stream;
	value1 += value2;
	stream << value1;
  EXPECT_EQ(stream.str(), "300");
}

//***************************************************************************
// Test: 				SimpleSubtraction
//
// Description: testing the subtraction operator 
//***************************************************************************

TEST(MoneyArithmeticTests, SimpleSubtraction) {
  Money value1(250);
	Money value2(50);
	std::ostringstream stream;
	stream << value1 - value2;
  EXPECT_EQ(stream.str(), "200");
}

//***************************************************************************
// Test: 				ShortenedSubtraction
//
// Description: testing operator-= 
//***************************************************************************

TEST(MoneyArithmeticTests, ShortenedSubtraction) {
  Money value1(250);
	Money value2(50);
	std::ostringstream stream;
	value1 -= value2;
	stream << value1;
  EXPECT_EQ(stream.str(), "200");
}

//***************************************************************************
// Test: 				SimpleMultiplication
//
// Description: testing the multiplication operator 
//***************************************************************************

TEST(MoneyArithmeticTests, SimpleMultiplication) {
  Money value1(250);
	double value2 = 2.0;
	std::ostringstream stream;
	stream << value1 * value2;
  EXPECT_EQ(stream.str(), "500");
}

//***************************************************************************
// Test: 				ShortenedMultiplication
//
// Description: testing operator*= 
//***************************************************************************

TEST(MoneyArithmeticTests, ShortenedMultiplication) {
  Money value1(250);
	double value2 = 2.0;
	std::ostringstream stream;
	value1 *= value2;
	stream << value1;
  EXPECT_EQ(stream.str(), "500");
}

//***************************************************************************
// Test: 				LessThan_Appropriate
//
// Description: testing operator<
//***************************************************************************

TEST(MoneyComparisonTests, LessThan_Appropriate) {
  Money value1(250);
	Money value2(300);
	EXPECT_TRUE (value1 < value2);
}

//***************************************************************************
// Test: 				LessThan_Inappropriate
//
// Description: testing operator<
//***************************************************************************

TEST(MoneyComparisonTests, LessThan_Inappropriate) {
  Money value1(250);
	Money value2(200);
	EXPECT_FALSE (value1 < value2);
}

//***************************************************************************
// Test: 				GraterThanOrEqual_Appropriate_Grater
//
// Description: testing operator>=
//***************************************************************************

TEST(MoneyComparisonTests, GraterThanOrEqual_Appropriate_Grater) {
  Money value1(250);
	Money value2(200);
	EXPECT_TRUE (value1 >= value2);
}

//***************************************************************************
// Test: 				GraterThanOrEqual_Appropriate_Equal
//
// Description: testing operator>=
//***************************************************************************

TEST(MoneyComparisonTests, GraterThanOrEqual_Appropriate_Equal) {
  Money value1(250);
	Money value2(250);
	EXPECT_TRUE (value1 >= value2);
}

//***************************************************************************
// Test: 				GraterThanOrEqual_Inappropriate
//
// Description: testing operator>=
//***************************************************************************

TEST(MoneyComparisonTests, GraterThanOrEqual_Inappropriate) {
  Money value1(250);
	Money value2(300);
	EXPECT_FALSE (value1 >= value2);
}

//***************************************************************************
// Test: 				FunctionCall
//
// Description: testing operator ()
//***************************************************************************

TEST(MoneyTests, FunctionCall) {
	Money value1(250);
	Money value2(50);
	Money value3(30);
	std::ostringstream stream;
	value1 -= value2;
	value1 = value1 () + value3;
	stream << value1 ();
  EXPECT_EQ(stream.str(), "230");
}

//***************************************************************************
// Test: 				Input
//
// Description: testing operator>>
//***************************************************************************

TEST(MoneyIOTests, Input) {
	Money value(0);
	std::ostringstream outStream;
	std::istringstream inStream("20000");
	inStream >> value;
	outStream << value;
  EXPECT_EQ(outStream.str(), "20000");
}

//***************************************************************************
// Test: 				Output
//
// Description: testing operator<<
//***************************************************************************

TEST(MoneyIOTests, Output) {
	Money value(0);
	std::ostringstream outStream;
	outStream << value;
  EXPECT_EQ(outStream.str(), "0");
}