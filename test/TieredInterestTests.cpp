//***************************************************************************
// File name:   TieredInterestTests.cpp
// Author:      Anna Tymoshenko
// Date:        03/16/25
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Provide unit testing for Money
//***************************************************************************

#include <gtest/gtest.h>
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

