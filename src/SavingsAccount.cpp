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

SavingsAccount::SavingsAccount (unsigned int accountNumber,
	const Money& balance, const Interest& interestRate,
	const Money& minBalance, const Money& monthlyFee)
	: Account (accountNumber, balance, interestRate) {

	mMinBalance = minBalance;
	mMonthlyFee = monthlyFee;
	if (Account::getBalance () >= minBalance) {
		mbIsBelowMinBalance = false;
	}
	else {
		mbIsBelowMinBalance = true;
		Account::withdraw (mMonthlyFee);
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
// Description: apply deposit operation on savings account
//
// Parameters:  amount - amount deposited
//
// Returned:    none
//***************************************************************************

void SavingsAccount::deposit (const Money& amount) {
	Account::deposit (amount);
	if (Account::getBalance () >= mMinBalance) {
		mbIsBelowMinBalance = false;
	}
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from savings account
//
// Parameters:  amount - amount withdrawn
//
// Returned:    none
//***************************************************************************

void SavingsAccount::withdraw (const Money& amount) {
	Account::withdraw (amount);
	if (Account::getBalance () < mMinBalance) {
		mbIsBelowMinBalance = true;
		Account::withdraw (mMonthlyFee);
	}
}

//***************************************************************************
// Function:    chargeMonthlyFee
//
// Description: charge the savings account the monthly fee
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void SavingsAccount::chargeMonthlyFee () {
	Account::chargeMonthlyFee ();
}

//***************************************************************************
// Function:    display
//
// Description: display savings account info
//
// Parameters:  rcOutStream - stream to output to
//
// Returned:    none
//***************************************************************************

void SavingsAccount::display (std::ostream& rcOutStream) const {
	Account::display (rcOutStream);
	rcOutStream << std::fixed << std::setprecision (2);
	rcOutStream << mMonthlyFee << ", " << mMinBalance;
}

//***************************************************************************
// Function:    read
//
// Description: read savings account info
//
// Parameters:  rcInStream - stream to take input from
//
// Returned:    none
//***************************************************************************

void SavingsAccount::read (std::istream& rcInStream) {
	Account::read (rcInStream);
	rcInStream >> mMonthlyFee >> mMinBalance;
}
