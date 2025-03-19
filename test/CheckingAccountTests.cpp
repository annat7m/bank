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
	FlatInterest interest(0.02);

	CheckingAccount account(12345, initialBalance, interest, minBalance, minBalanceFee);
	account.deposit(depositAmount);

	EXPECT_EQ(account.getBalance(), initialBalance + depositAmount);
}

//***************************************************************************
// Test:        WithdrawAboveMinBalance
//
// Description: Ensures withdrawal works correctly when above min balance
//***************************************************************************

TEST (CheckingAccountTests, WithdrawAboveMinBalance) {
	Money initialBalance(1000);
	Money withdrawAmount(400);
	Money minBalance(500);
	Money minBalanceFee(50);
	FlatInterest interest(0.02);

	CheckingAccount account(12345, initialBalance, interest, minBalance, minBalanceFee);
	account.withdraw(withdrawAmount);

	EXPECT_EQ(account.getBalance(), initialBalance - withdrawAmount);
}

//***************************************************************************
// Test:        WithdrawBelowMinBalance
//
// Description: Ensures minimum balance fee is applied when needed
//***************************************************************************

TEST (CheckingAccountTests, WithdrawBelowMinBalance) {
	Money initialBalance(600);
	Money withdrawAmount(200);
	Money minBalance(500);
	Money minBalanceFee(50);
	FlatInterest interest(0.02);

	CheckingAccount account(12345, initialBalance, interest, 
		minBalance, minBalanceFee);
	account.withdraw(withdrawAmount);

	EXPECT_EQ(account.getBalance(), 
		initialBalance - withdrawAmount - minBalanceFee);
}

//***************************************************************************
// Test:        WithdrawMultipleTimes
//
// Description: Ensures multiple transactions behave correctly
//***************************************************************************

TEST (CheckingAccountTests, WithdrawMultipleTimes) {
	Money initialBalance(1000);
	Money withdraw1(200);
	Money withdraw2(350);
	Money minBalance(500);
	Money minBalanceFee(50);
	FlatInterest interest(0.02);

	CheckingAccount account(12345, initialBalance, interest, 
		minBalance, minBalanceFee);
	account.withdraw(withdraw1);
	account.withdraw(withdraw2);

	EXPECT_EQ(account.getBalance(), 
		initialBalance - withdraw1 - withdraw2 - minBalanceFee);
}

//***************************************************************************
// Test:        ChargeMonthlyFee
//
// Description: Ensures interest is applied correctly
//***************************************************************************

TEST (CheckingAccountTests, ChargeMonthlyFee) {
	Money initialBalance(1000);
	Money minBalance(500);
	Money minBalanceFee(50);
	FlatInterest interest(0.02);

	CheckingAccount account(12345, initialBalance, interest, 
		minBalance, minBalanceFee);
	account.chargeMonthlyFee();

	EXPECT_EQ(account.getBalance(), interest.generate(initialBalance));
}