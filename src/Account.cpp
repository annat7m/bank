//***************************************************************************
// File name:   Account.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Account.h"
#include "../include/Interest.h"
#include "../include/FlatInterest.h"
#include "../include/TieredInterest.h"
#include "../include/Money.h"
#include <iostream>
#include <iomanip>

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

Account::Account (unsigned int accountNumber, const Money& balance,
	const Interest& interestRate) {
	mAccountNumber = accountNumber;
	mBalance = balance;
	if (dynamic_cast<const FlatInterest*>(&interestRate)) {
		mInterestRate = std::make_shared<FlatInterest> (
			*dynamic_cast<const FlatInterest*>(&interestRate));
	}
	else if (dynamic_cast<const TieredInterest*>(&interestRate)) {
		mInterestRate = std::make_shared<TieredInterest> (
			*dynamic_cast<const TieredInterest*>(&interestRate));
	}
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

void Account::deposit (const Money& amount) {
	mBalance += amount;
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

void Account::withdraw (const Money& amount) {
	// accounts are allowed to be negative
	mBalance -= amount;
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
	mBalance = mInterestRate->generate (mBalance);
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

// void Account::addTransaction (TransactionType transactionType,
// 	const Money& amount) {
// 	mTransactions.emplace_back (transactionType, amount);
// }

//***************************************************************************
// Function:    getBalance
//
// Description: getter function for balance
//
// Parameters:  none
//
// Returned:    amount of money that is on the balance
//***************************************************************************

Money Account::getBalance () const {
	return mBalance;
}

//***************************************************************************
// Function:    getAccountNumber
//
// Description: getter function for account number
//
// Parameters:  none
//
// Returned:    amount of money that is on the balance
//***************************************************************************

unsigned int Account::getAccountNumber () const {
	return mAccountNumber;
}

//***************************************************************************
// Function:    operaotr==
//
// Description: compare if accounts are the same 
//
// Parameters:  accountNum - number of account
//
// Returned:    true if equal, false otherwise
//***************************************************************************

bool Account::operator== (unsigned int accountNum) const {
	return mAccountNumber == accountNum;
}

//***************************************************************************
// Function:    display
//
// Description: display account info to the stream 
//
// Parameters:  rcOutStream - stream to output to
//
// Returned:    none
//***************************************************************************

void Account::display (std::ostream& rcOutStream) const {
	rcOutStream << std::fixed << std::setprecision (2) << mAccountNumber
		<< ", " << mBalance << ", " << mInterestRate << ", ";
}

//***************************************************************************
// Function:    read
//
// Description: read account info from the stream 
//
// Parameters:  rcInStream - stream to input from
//
// Returned:    none
//***************************************************************************

void Account::read (std::istream& rcInStream) {
	const char FLAT = 'F';
	const char TIERED = 'T';
	char interestType;

	rcInStream >> mAccountNumber >> mBalance >> interestType;
	if (interestType == FLAT) {
		mInterestRate = std::make_shared<FlatInterest> ();
	}
	else if (interestType == TIERED) {
		mInterestRate = std::make_shared<TieredInterest> ();
	}
	rcInStream >> *mInterestRate;
}

//***************************************************************************
// Function:    operator<<
//
// Description: display account info to the screen 
//
// Parameters:  rcOutStream	- steam to output to
//							account			- account to output
//
// Returned:    none
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOutStream,
	const Account& account) {
	account.display (rcOutStream);
	return rcOutStream;
}

//***************************************************************************
// Function:    operator>>
//
// Description: read account info from the stream 
//
// Parameters:  rcOutStream - steam to input from
//							account			- account to input
//
// Returned:    none
//***************************************************************************

std::istream& operator>> (std::istream& rcInStream, Account& account) {
	account.read (rcInStream);
	return rcInStream;
}