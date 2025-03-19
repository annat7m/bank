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
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest>();

	CheckingAccount account(12345, initialBalance, interest, 
		minBalance, minBalanceFee);

	EXPECT_EQ(account.getBalance(), initialBalance);
	EXPECT_TRUE(account == 12345);
}

//***************************************************************************
// Test:        Deposit
//
// Description: Ensures deposits correctly increase balance
//***************************************************************************

TEST (CheckingAccountTests, Deposit) {
	Money initialBalance(1000);
	Money depositAmount(500);
	Money minBalance(500);
	Money minBalanceFee(50);
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest>();

	CheckingAccount account(12345, initialBalance, interest, minBalance, minBalanceFee);
	account.deposit(depositAmount);

	EXPECT_EQ(account.getBalance(), initialBalance + depositAmount);
}

//***************************************************************************
// Test:        Withdraw
//
// Description: Ensures withdrawal works correctly when above min balance
//***************************************************************************

TEST (CheckingAccountTests, Withdraw) {
	Money initialBalance(1000);
	Money withdrawAmount(400);
	Money minBalance(500);
	Money minBalanceFee(50);
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest>();

	CheckingAccount account(12345, initialBalance, interest, minBalance, minBalanceFee);
	account.withdraw(withdrawAmount);

	EXPECT_EQ(account.getBalance(), initialBalance - withdrawAmount);
}
