//***************************************************************************
// File name:   SavingsAccountTests.cpp
// Author:      Anna Tymoshenko
// Date:        03/07/25
// Class:       CS 485
// Assignment:  Assignment 3
// Purpose:     Provide unit testing for SavingsAccount
//***************************************************************************

#include <gtest/gtest.h>
#include <memory>

#include "../include/SavingsAccount.h"
#include "../include/Money.h"
#include "../include/FlatInterest.h"

//***************************************************************************
// Test:        Constructor
//
// Description: Tests the constructor of SavingsAccount to ensure it initializes
//              correctly
//***************************************************************************

TEST (SavingsAccountTests, Constructor) {
	Money initialBalance(1000);
	Money minBalance(500);
	Money minBalanceFee(50);
	FlatInterest interest(0.02);

	SavingsAccount account(12345, initialBalance, interest, minBalance, minBalanceFee);

	EXPECT_EQ(account.getBalance(), initialBalance);
	EXPECT_TRUE(account == 12345);
}