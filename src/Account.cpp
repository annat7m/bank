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
#include "../include/CurrencyMismatchException.h"
#include <iostream>
#include <iomanip>
#include <memory>

//***************************************************************************
// Constructor: Account
//
// Description: Initializes Bank Account object
//
// Parameters:  accountNumber - account number
//							rcBalance				- initial balance of the account
//							rpcInterestRate	- interest rate
//
// Returned:    None
//***************************************************************************

Account::Account (unsigned int accountNumber, const Money& rcBalance,
	std::shared_ptr<Interest>& rpcInterestRate) : mBalance(rcBalance) {
	mAccountNumber = accountNumber;
	mpInterestRate = std::move (rpcInterestRate);
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
// Parameters:  rcAmount - amount deposited
//
// Returned:    none
//***************************************************************************

void Account::deposit (const Money& rcAmount) {
	// try {
		mBalance += rcAmount;
	// } catch (const CurrencyMismatchException&) {}
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from account
//
// Parameters:  cAmount - amount withdrawn
//
// Returned:    none
//***************************************************************************

void Account::withdraw (const Money& rcAmount) {
	// try {
		// accounts are allowed to be negative
		mBalance -= rcAmount;
	// } catch (const CurrencyMismatchException&) {}
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

void Account::chargeMonthlyFee () {}

//***************************************************************************
// Function:    generateInterest
//
// Description: apply interest rate to banking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Account::generateInterest () {
	// try {
		mBalance = mpInterestRate->generate (mBalance);
	// } catch (const CurrencyMismatchException&) {}
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
		<< ", " << mBalance << ", " << *mpInterestRate << ", ";
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
		mpInterestRate = std::make_shared<FlatInterest> ();
	}
	else if (interestType == TIERED) {
		mpInterestRate = std::make_shared<TieredInterest> ();
	}
	rcInStream >> mpInterestRate;
}

//***************************************************************************
// Function:    operator<<
//
// Description: display account info to the screen 
//
// Parameters:  rcOutStream	- steam to output to
//							cAccount			- account to output
//
// Returned:    none
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOutStream,
	const Account& cAccount) {
	cAccount.display (rcOutStream);
	return rcOutStream;
}

//***************************************************************************
// Function:    operator>>
//
// Description: read account info from the stream 
//
// Parameters:  rcOutStream - steam to input from
//							cAccount			- account to input
//
// Returned:    none
//***************************************************************************

std::istream& operator>> (std::istream& rcInStream, Account& cAccount) {
	cAccount.read (rcInStream);
	return rcInStream;
}