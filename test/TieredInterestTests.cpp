//***************************************************************************
// File name:   TieredInterestTests.cpp
// Author:      Anna Tymoshenko
// Date:        03/16/25
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Provide unit testing for Money
//***************************************************************************

#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <sstream>

#include "../include/TieredInterest.h"

//***************************************************************************
// Test:        Constructor
//
// Description: Tests the constructor of TieredInterest to ensure it initializes
//              correctly.
//***************************************************************************

TEST(TieredInterestTests, Constructor) {
	TieredInterest tieredInterest(3);
	std::stringstream stream;
	tieredInterest.display(stream);
	EXPECT_EQ(stream.str(), "T 3");
}

//***************************************************************************
// Test:        GenerateInterest_AssignmentExample
//
// Description: Tests the generate function of TieredInterest to ensure it
//              calculates interest correctly for different tiers
//***************************************************************************

TEST(TieredInterestTests, GenerateInterest_AssignmentExample) {
	TieredInterest tieredInterest(2);
	tieredInterest.addTier(Money(10000), 0.01);
	tieredInterest.addTier(Money(20000), 0.02);

	Money generated1 = tieredInterest.generate(Money(10500));
	EXPECT_EQ(generated1, Money(10395));

	Money generated2 = tieredInterest.generate(Money(20500));
	EXPECT_EQ(generated2, Money(20090));
}

//***************************************************************************
// Test:        GenerateInterest
//
// Description: Tests the generate function of TieredInterest to ensure it
//              calculates interest correctly for different tiers
//***************************************************************************

TEST(TieredInterestTests, GenerateInterest) {
	TieredInterest tieredInterest(2);
	tieredInterest.addTier(Money(10000), 0.01);
	tieredInterest.addTier(Money(20000), 0.02);

	Money generated1 = tieredInterest.generate(Money(10500));
	EXPECT_EQ(generated1, Money(10395));

	Money generated2 = tieredInterest.generate(Money(20500));
	EXPECT_EQ(generated2, Money(20090));
}