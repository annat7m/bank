// ***************************************************************************
// File name:   CheckingAccountTests.cpp
// Author:      Anna Tymoshenko
// Date:        04/06/25
// Class:       CS 485
// Assignment:  Assignment 5
// Purpose:     Provide unit testing for CheckingAccount
// ***************************************************************************

#include <gtest/gtest.h>
#include <memory>

#include "../include/CheckingAccount.h"
#include "../include/Money.h"
#include "../include/FlatInterest.h"

// ***************************************************************************
// Test:        Constructor

// Description: Tests the constructor of CheckingAccount to ensure it initializes
//              correctly
// ***************************************************************************

TEST (CheckingAccountTests, Constructor) {
	Money initialBalance (1000, Currency (CurrencyType::USD));
	Money minBalance (500, Currency (CurrencyType::USD));
	Money minBalanceFee (50, Currency (CurrencyType::USD));
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest> ();

	CheckingAccount account (12345, initialBalance, interest,
		minBalance, minBalanceFee);

	EXPECT_EQ (account.getBalance (), initialBalance);
	EXPECT_TRUE (account == 12345);
}

// ***************************************************************************
// Test:        Deposit

// Description: Ensures deposits correctly increase balance
// ***************************************************************************

TEST (CheckingAccountTests, Deposit) {
	Money initialBalance (1000, Currency (CurrencyType::EUR));
	Money depositAmount (500, Currency (CurrencyType::EUR));
	Money minBalance (500, Currency (CurrencyType::EUR));
	Money minBalanceFee (50, Currency (CurrencyType::EUR));
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest> ();

	CheckingAccount account (12345, initialBalance, interest, minBalance, minBalanceFee);
	account.deposit (depositAmount);

	EXPECT_EQ (account.getBalance (), initialBalance + depositAmount);
}

// ***************************************************************************
// Test:        Withdraw

// Description: Ensures withdrawal works correctly when above min balance
// ***************************************************************************

TEST (CheckingAccountTests, Withdraw) {
	Money initialBalance (1000, Currency (CurrencyType::GBP));
	Money withdrawAmount (400, Currency (CurrencyType::GBP));
	Money minBalance (500, Currency (CurrencyType::GBP));
	Money minBalanceFee (50, Currency (CurrencyType::GBP));
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest> ();

	CheckingAccount account (12345, initialBalance, interest, minBalance, minBalanceFee);
	account.withdraw (withdrawAmount);

	EXPECT_EQ (account.getBalance (), initialBalance - withdrawAmount);
}
