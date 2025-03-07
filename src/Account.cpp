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
// Parameters:  accountNumber - account number
//							balance				- initial balance of the account
//							interestRate	- interest rate
//
// Returned:    None
//***************************************************************************

Account::Account (int accountNumber, long long balance, double interestRate) {
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
// Description: apply deposit operation on account
//
// Parameters:  amount - amount deposited
//
// Returned:    none
//***************************************************************************

void Account::deposit (long long amount) {
	mBalance += amount;
	addTransaction (TransactionType::deposit, amount);
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from account
//
// Parameters:  amount - amount withdrawn
//
// Returned:    none
//***************************************************************************

void Account::withdraw (long long amount) {
	// accounts are allowed to be negative
	mBalance -= amount;
	addTransaction (TransactionType::withdrawal, amount);
}

//***************************************************************************
// Function:    chargeMonthlyFee
//
// Description: charge banking account the monthly fee
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
// Description: accrue interest on a banking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Account::accrueInterest () {
	long long interest = static_cast<long long>(mBalance * mInterestRate);
	mBalance += interest;
	addTransaction (TransactionType::interest, interest);
}

//***************************************************************************
// Function:    addTransaction
//
// Description: add a transaction that was made using banking account
//
// Parameters:  TransactionType	- type of transaction that was made
//							amount					- amount of the transaction
//
// Returned:    none
//***************************************************************************

void Account::addTransaction (TransactionType transactionType,
	long long amount) {
	mTransactions.emplace_back (transactionType, amount);
}

//***************************************************************************
// Function:    getAccountNumber
//
// Description: getter function for account number
//
// Parameters:  none
//
// Returned:    number identidying banking account
//***************************************************************************

int Account::getAccountNumber () const {
	return mAccountNumber;
}

//***************************************************************************
// Function:    getBalance
//
// Description: getter function for balance
//
// Parameters:  none
//
// Returned:    amount of money that is on the balance
//***************************************************************************

long long Account::getBalance () const {
	return mBalance;
}

//***************************************************************************
// Function:    getInterestRate
//
// Description: getter function for the interest rate
//
// Parameters:  none
//
// Returned:    the interest rate
//***************************************************************************

double Account::getInterestRate () const {
	return mInterestRate;
}

//***************************************************************************
// Function:    adjustBalance
//
// Description: protected function to change or adjust the account balance based
//							on the amount
//
// Parameters:  amount - how much would the balance change 
//
// Returned:    none
//***************************************************************************

void Account::adjustBalance (long long amount) {
	mBalance += amount;
}