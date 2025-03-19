//***************************************************************************
// File name:   CheckingAccountTests.cpp
// Author:      Anna Tymoshenko
// Date:        03/18/25
// Class:       CS 485
// Assignment:  Assignment 4
// Purpose:     Provide unit testing for CheckingAccount
//***************************************************************************

#include <gtest/gtest.h>
#include <memory>

#include "../include/CheckingAccount.h"
#include "../include/Money.h"
#include "../include/FlatInterest.h"

//***************************************************************************
// Test:        Constructor
//
// Description: Tests the constructor of CheckingAccount to ensure it initializes
//              correctly
//***************************************************************************

TEST (CheckingAccountTests, Constructor) {
	Money initialBalance(1000);
	Money minBalance(500);
	Money minBalanceFee(50);
	FlatInterest interest(0.02);

	CheckingAccount account(12345, initialBalance, interest, minBalance, minBalanceFee);

	EXPECT_EQ(account.getBalance(), initialBalance);
	EXPECT_TRUE(account == 12345);
}