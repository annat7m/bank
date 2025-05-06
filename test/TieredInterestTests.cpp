//***************************************************************************
// File name:   TieredInterestTests.cpp
// Author:      Anna Tymoshenko
// Date:        04/07/25
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
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

TEST (TieredInterestTests, Constructor) {
	TieredInterest tieredInterest (3);
	std::stringstream stream;
	tieredInterest.display (stream);
	EXPECT_EQ (stream.str (), "T");
}

// ***************************************************************************
// Test:        GenerateInterest_NoTiers

// Description: Testing if can generate tiered interest with no tieres
// ***************************************************************************

TEST (TieredInterestTests, GenerateInterest_NoTiers) {
	TieredInterest tieredInterest (0);
	Money original (10000, Currency (CurrencyType::USD));
	EXPECT_EQ (tieredInterest.generate (original), original);
}

// ***************************************************************************
// Test:        GenerateInterest_AssignmentExample

// Description: Tests the generate function of TieredInterest to ensure it
//              calculates interest correctly for different tiers
// ***************************************************************************

TEST (TieredInterestTests, GenerateInterest_AssignmentExample) {
	TieredInterest tieredInterest (2);
	tieredInterest.addTier (Money (10000, Currency (CurrencyType::USD)), 0.01);
	tieredInterest.addTier (Money (20000, Currency (CurrencyType::USD)), 0.02);

	Money generated1 = tieredInterest.generate (Money (10500,
		Currency (CurrencyType::USD)));
	EXPECT_EQ (generated1, Money (10605, Currency (CurrencyType::USD)));

	Money generated2 = tieredInterest.generate (Money (20100,
		Currency (CurrencyType::USD)));
	EXPECT_EQ (generated2, Money (20502, Currency (CurrencyType::USD)));
}

// ***************************************************************************
// Test:        GenerateInterest_Other

// Description: Tests the generate function of TieredInterest to ensure it
//              calculates interest correctly for different tiers
// ***************************************************************************

TEST (TieredInterestTests, GenerateInterest_Other) {
	TieredInterest tieredInterest (4);
	tieredInterest.addTier (Money (10000, Currency (CurrencyType::EUR)), 0.01);
	tieredInterest.addTier (Money (20000, Currency (CurrencyType::EUR)), 0.02);
	tieredInterest.addTier (Money (30000, Currency (CurrencyType::EUR)), 0.03);
	tieredInterest.addTier (Money (40000, Currency (CurrencyType::EUR)), 0.04);

	Money generated1 = tieredInterest.generate (Money (20000,
		Currency (CurrencyType::EUR)));
	EXPECT_EQ (generated1, Money (20400, Currency (CurrencyType::EUR)));

	Money generated2 = tieredInterest.generate (Money (30000,
		Currency (CurrencyType::EUR)));
	EXPECT_EQ (generated2, Money (30900, Currency (CurrencyType::EUR)));

	Money generated3 = tieredInterest.generate (Money (50000,
		Currency (CurrencyType::EUR)));
	EXPECT_EQ (generated3, Money (52000, Currency (CurrencyType::EUR)));
}

// ***************************************************************************
// Test:        GenerateInterest_BelowAllTiers

// Description: Tesing if interest below all tieres is generated correcly
// ***************************************************************************

TEST (TieredInterestTests, GenerateInterest_BelowAllTiers) {
	TieredInterest tieredInterest (2);
	tieredInterest.addTier (Money (10000, Currency (CurrencyType::USD)), 0.01);
	tieredInterest.addTier (Money (20000, Currency (CurrencyType::USD)), 0.02);

	Money result = tieredInterest.generate (Money (5000,
		Currency (CurrencyType::USD)));
	EXPECT_EQ (result, Money (5000, Currency (CurrencyType::USD)));
}

// ***************************************************************************
// Test:        GenerateInterest_DescendingTiers

// Description: Testing if logic is maintained if tieres are added in a
//							different order
// ***************************************************************************

TEST (TieredInterestTests, GenerateInterest_DescendingTiers) {
	TieredInterest tieredInterest (3);
	tieredInterest.addTier (Money (30000, Currency (CurrencyType::USD)), 0.03);
	tieredInterest.addTier (Money (10000, Currency (CurrencyType::USD)), 0.01);
	tieredInterest.addTier (Money (20000, Currency (CurrencyType::USD)), 0.02);

	Money result = tieredInterest.generate (Money (25000, Currency (CurrencyType::USD)));
	EXPECT_EQ (result, Money (25500, Currency (CurrencyType::USD)));
}

// ***************************************************************************
// Test:        Display

// Description: Testing if tiered interest is outputted correctly
// ***************************************************************************

TEST (TieredInterestTests, Display) {
	TieredInterest tieredInterest (4);
	tieredInterest.addTier (Money (10000, Currency (CurrencyType::GBP)), 0.01);
	tieredInterest.addTier (Money (20000, Currency (CurrencyType::GBP)), 0.02);
	tieredInterest.addTier (Money (30000, Currency (CurrencyType::GBP)), 0.03);
	tieredInterest.addTier (Money (40000, Currency (CurrencyType::GBP)), 0.04);
	std::stringstream stream;
	tieredInterest.display (stream);
	EXPECT_EQ (stream.str (),
		"T GBP100.00 GBP200.00 GBP300.00 GBP400.00 1.00% 2.00% 3.00% 4.00%");
}

// ***************************************************************************
// Test:        Read

// Description: Tests the read function of TieredInterest to ensure it
//              reads and parses input correctly
// ***************************************************************************

TEST (TieredInterestTests, Read) {
	std::stringstream inputStream;
	std::stringstream outputStream;
	TieredInterest tieredInterest1 (0);

	inputStream.str ("2 YEN 10000 YEN 20000 0.01 0.02");
	tieredInterest1.read (inputStream);
	tieredInterest1.display (outputStream);

	EXPECT_EQ (outputStream.str (), "T YEN100.00 YEN200.00 1.00% 2.00%");
}