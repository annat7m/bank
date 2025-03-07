//***************************************************************************
// File name:   SavingsAccount.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/SavingsAccount.h"
#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: SavingsAccount
//
// Description: Initializes Savings Account object in Banking system
//
// Parameters:  accountNumber - account number
//              balance       - initial balance
//              interestRate  - annual interest rate
//              minBalance    - minimum balance allowed
//              monthlyFee 		- fee charged every month
//
// Returned:    None
//***************************************************************************

SavingsAccount::SavingsAccount(int accountNumber, long long balance, 
	double interestRate, long long minBalance, long long monthlyFee)
	: Account(accountNumber, balance, interestRate) {
		mMinBalance = minBalance;
		mMonthlyFee = monthlyFee;
		if (Account::getBalance() >= minBalance) {
			mbIsBelowMinBalance = false;
		} else {
			mbIsBelowMinBalance = true;
			chargeMonthlyFee();
		}
}

//***************************************************************************
// Destructor:  SavingsAccount
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

SavingsAccount::~SavingsAccount () {}

//***************************************************************************
// Function:    deposit
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void SavingsAccount::deposit(long long amount) {
	Account::deposit(amount);
	if (Account::getBalance() >= mMinBalance) {
		mbIsBelowMinBalance = false;
	}
}

//***************************************************************************
// Function:    withdraw
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void SavingsAccount::withdraw(long long amount) {
	Account::withdraw(amount);
	if (Account::getBalance() < mMinBalance) {
		mbIsBelowMinBalance = true;
	}
}

//***************************************************************************
// Function:    chargeMonthlyFee
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void SavingsAccount::chargeMonthlyFee() {
	if (mbIsBelowMinBalance) {
		adjustBalance(-mMonthlyFee);
		addTransaction(TransactionType::fee, mMonthlyFee);
	}
}

//***************************************************************************
// Function:    displayAccount
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void SavingsAccount::displayAccount() const {
	std::cout << std::fixed << std::setprecision(2) << Account::getAccountNumber()  
		<< ", $" << Account::getBalance()*Account::getInterestRate() 
		<< ", " << Account::getInterestRate()*100 << "%, ";
	std::cout << mMonthlyFee << ", " << mMinBalance;
}