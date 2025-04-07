//***************************************************************************
// File name:   SavingsAccount.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/SavingsAccount.h"
#include "../include/CurrencyMismatchException.h"
#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: SavingsAccount
//
// Description: Initializes Savings Account object in Banking system
//
// Parameters:  accountNumber 	- account number
//              rcBalance       - initial balance
//              rpcInterestRate - annual interest rate
//              rcMinBalance    - minimum balance allowed
//              rcMonthlyFee 		- fee charged every month
//
// Returned:    None
//***************************************************************************

SavingsAccount::SavingsAccount (unsigned int accountNumber,
	const Money& rcBalance, std::shared_ptr<Interest>& rpcInterestRate,
	const Money& rcMinBalance, const Money& rcMonthlyFee)
	: Account (accountNumber, rcBalance, rpcInterestRate),
	mMinBalance (rcMinBalance), mMonthlyFee (rcMonthlyFee) {

	if (Account::getBalance () >= rcMinBalance) {
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
// Parameters:  rcAmount - amount deposited
//
// Returned:    none
//***************************************************************************

void SavingsAccount::deposit (const Money& rcAmount) {
	Account::deposit (rcAmount);
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from savings account
//
// Parameters:  rcAmount - amount withdrawn
//
// Returned:    none
//***************************************************************************

void SavingsAccount::withdraw (const Money& rcAmount) {
	Account::withdraw (rcAmount);
	if (Account::getBalance () < mMinBalance) {
		mbIsBelowMinBalance = true;
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
	if (mbIsBelowMinBalance) {
		Account::withdraw (mMonthlyFee);
	}
	if (Account::getBalance () < mMinBalance) {
		mbIsBelowMinBalance = true;
	}
}

//***************************************************************************
// Function:    generateInterest
//
// Description: apply interest rate to banking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void SavingsAccount::generateInterest () {
	if (Account::getBalance () >= Money (0,
		Account::getBalance ().getCurrency ())) {
		Account::generateInterest ();
	}
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
	rcInStream >> mMinBalance >> mMonthlyFee;
}
