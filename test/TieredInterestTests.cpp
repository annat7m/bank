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
	EXPECT_EQ(stream.str(), "T");
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
	EXPECT_EQ(generated1, Money(10605));

	Money generated2 = tieredInterest.generate(Money(20100));
	EXPECT_EQ(generated2, Money(20502));
}

//***************************************************************************
// Test:        GenerateInterest_Other
//
// Description: Tests the generate function of TieredInterest to ensure it
//              calculates interest correctly for different tiers
//***************************************************************************

TEST(TieredInterestTests, GenerateInterest_Other) {
	TieredInterest tieredInterest(4);
	tieredInterest.addTier(Money(10000), 0.01);
	tieredInterest.addTier(Money(20000), 0.02);
	tieredInterest.addTier(Money(30000), 0.03);
	tieredInterest.addTier(Money(40000), 0.04);

	Money generated1 = tieredInterest.generate(Money(20000));
	EXPECT_EQ(generated1, Money(20400));

	Money generated2 = tieredInterest.generate(Money(30000));
	EXPECT_EQ(generated2, Money(30900));

	Money generated3 = tieredInterest.generate(Money(50000));
	EXPECT_EQ(generated3, Money(52000));
}

//***************************************************************************
// Test:        Display
//
// Description: 
//***************************************************************************

TEST(TieredInterestTests, Display) {
	TieredInterest tieredInterest(4);
	tieredInterest.addTier(Money(10000), 0.01);
	tieredInterest.addTier(Money(20000), 0.02);
	tieredInterest.addTier(Money(30000), 0.03);
	tieredInterest.addTier(Money(40000), 0.04);
	std::stringstream stream;
	tieredInterest.display(stream);
	EXPECT_EQ(stream.str(), "T $100.00 $200.00 $300.00 $400.00, 1.00% 2.00% 3.00% 4.00%");
}

//***************************************************************************
// Test:        Read
//
// Description: Tests the read function of TieredInterest to ensure it
//              reads and parses input correctly
//***************************************************************************

TEST(TieredInterestTests, Read) {
	std::stringstream inputStream;
	std::stringstream outputStream;
	TieredInterest tieredInterest1(0);

	inputStream.str("2 10000 20000 0.01 0.02");
	tieredInterest1.read(inputStream);
	tieredInterest1.display(outputStream);

	EXPECT_EQ(outputStream.str(), "T $100.00 $200.00, 1.00% 2.00%");
}