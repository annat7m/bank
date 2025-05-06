// ***************************************************************************
// File name:   SavingsAccountTests.cpp
// Author:      Anna Tymoshenko
// Date:        04/06/25
// Class:       CS 485
// Assignment:  Assignment 5
// Purpose:     Provide unit testing for SavingsAccount
// ***************************************************************************

#include <gtest/gtest.h>
#include <memory>

#include "../include/SavingsAccount.h"
#include "../include/Money.h"
#include "../include/FlatInterest.h"

// ***************************************************************************
// Test:        Constructor

// Description: Tests the constructor of SavingsAccount to ensure it initializes
//              correctly
// ***************************************************************************

TEST (SavingsAccountTests, Constructor) {
	Money initialBalance (1000, Currency (CurrencyType::USD));
	Money minBalance (500, Currency (CurrencyType::USD));
	Money monthlyFee (50, Currency (CurrencyType::USD));
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest> ();

	SavingsAccount account (12345, initialBalance, interest, minBalance, monthlyFee);

	EXPECT_EQ (account.getBalance (), initialBalance);
	EXPECT_TRUE (account == 12345);
}

// ***************************************************************************
// Test:        Deposit

// Description: Ensures deposits correctly increase balance
// ***************************************************************************

TEST (SavingsAccountTests, Deposit) {
	Money initialBalance (1000, Currency (CurrencyType::YEN));
	Money depositAmount (500, Currency (CurrencyType::YEN));
	Money minBalance (500, Currency (CurrencyType::YEN));
	Money monthlyFee (20, Currency (CurrencyType::YEN));
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest> ();

	SavingsAccount account (12345, initialBalance, interest, minBalance, monthlyFee);
	account.deposit (depositAmount);

	EXPECT_EQ (account.getBalance (), initialBalance + depositAmount);
}

// ***************************************************************************
// Test:        Withdraw

// Description: Ensures withdrawal works correctly when above min balance
// ***************************************************************************

TEST (SavingsAccountTests, Withdraw) {
	Money initialBalance (1000, Currency (CurrencyType::YEN));
	Money withdrawAmount (400, Currency (CurrencyType::YEN));
	Money minBalance (500, Currency (CurrencyType::YEN));
	Money monthlyFee (20, Currency (CurrencyType::YEN));
	std::shared_ptr<Interest> interest = std::make_shared<FlatInterest> ();

	SavingsAccount account (12345, initialBalance, interest, minBalance, monthlyFee);
	account.withdraw (withdrawAmount);

	EXPECT_EQ (account.getBalance (), initialBalance - withdrawAmount);
}
