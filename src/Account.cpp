//***************************************************************************
// File name:   Account.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Account.h"
#include <iostream>

//***************************************************************************
// Constructor: Account
//
// Description: Initializes Bank Account object
//
// Parameters:  accountNumber -
//							balance				-
//							interestRate	-
//
// Returned:    None
//***************************************************************************

Account::Account(int accountNumber, long long balance, double interestRate) {
	mAccountNumber = accountNumber;
	mBalance = balance;
	mInterestRate = interestRate;
}

//***************************************************************************
// Destructor:  Account
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

Account::~Account () {}

//***************************************************************************
// Function:    deposit
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Account::deposit (long long amount) {
	mBalance += amount;
	addTransaction(TransactionType::deposit, amount);
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

void Account::withdraw (long long amount) {
	// accounts are allowed to be negative
	mBalance -= amount;
	addTransaction(TransactionType::withdrawal, amount);
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

void Account::chargeMonthlyFee () {
	
}

//***************************************************************************
// Function:    accrueInterest
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Account::accrueInterest() {
    long long interest = static_cast<long long>(mBalance * mInterestRate);
    mBalance += interest;
    addTransaction(TransactionType::interest, interest);
}

//***************************************************************************
// Function:    addTransaction
//
// Description: 
//
// Parameters:  TransactionType	-
//							amount					-
//
// Returned:    none
//***************************************************************************

void Account::addTransaction (TransactionType transactionType, 
	long long amount) {
	mTransactions.emplace_back(transactionType, amount);
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

// void Account::displayAccount() const {
    
// }

//***************************************************************************
// Function:    getAccountNumber
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

int Account::getAccountNumber() const {
    return mAccountNumber;
}

//***************************************************************************
// Function:    getBalance
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

long long Account::getBalance() const {
    return mBalance;
}

//***************************************************************************
// Function:    getInterestRate
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

double Account::getInterestRate() const {
	return mInterestRate;
}

//***************************************************************************
// Function:    adjustBalance
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Account::adjustBalance(long long amount) {
	mBalance += amount;
}
