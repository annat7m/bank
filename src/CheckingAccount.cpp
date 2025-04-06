//***************************************************************************
// File name:   CheckingAccount.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CheckingAccount.h"
#include "../include/Account.h"
#include "../include/CurrencyMismatchException.h"
#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: CheckingAccount
//
// Description: Initializes Checking Account object in Banking system
//
// Parameters:  accountNumber - account number
//              rcBalance       - initial balance
//              rpcInterestRate  - annual interest rate
//              rcMinBalance    - minimum balance allowed
//              rcMinBalanceFee - fee charged if the balance falls below the 
//															minimum
//
// Returned:    None
//***************************************************************************

CheckingAccount::CheckingAccount (unsigned int accountNumber,
	const Money& rcBalance, std::shared_ptr<Interest>& rpcInterestRate,
	const Money& rcMinBalance, const Money& rcMinBalanceFee)
	: Account (accountNumber, rcBalance, rpcInterestRate) {
	mcMinBalance = rcMinBalance;
	mcMinBalanceFee = rcMinBalanceFee;
	mbIsBelowMinBalance = (rcBalance < mcMinBalance);
}

//***************************************************************************
// Destructor:  CheckingAccount
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

CheckingAccount::~CheckingAccount () {}

//***************************************************************************
// Function:    deposit
//
// Description: apply deposit operation on checking account
//
// Parameters:  rcAmount - amount to deposit
//
// Returned:    none
//***************************************************************************

void CheckingAccount::deposit (const Money& rcAmount) {
	try {
		bool wasBelowMin = Account::getBalance () < mcMinBalance;

		Account::deposit (rcAmount);

		if (wasBelowMin && (Account::getBalance () < mcMinBalance)) {
			Account::withdraw (mcMinBalanceFee);
			mbIsBelowMinBalance = true;
		}

		if (Account::getBalance () >= mcMinBalance) {
			mbIsBelowMinBalance = false;
		}
	}
	catch (const CurrencyMismatchException&) {}
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from checking account
//
// Parameters:  rcAmount -  amount to withdraw
//
// Returned:    none
//***************************************************************************

void CheckingAccount::withdraw (const Money& rcAmount) {
	try {
		bool wasAboveMin = Account::getBalance () >= mcMinBalance;

		Account::withdraw (rcAmount);

		if (wasAboveMin && (Account::getBalance () < mcMinBalance)) {
			Account::withdraw (mcMinBalanceFee);
			mbIsBelowMinBalance = true;
		}
	}
	catch (const CurrencyMismatchException&) {}
}

//***************************************************************************
// Function:    chargeMonthlyFee
//
// Description: charge the account the monthly fee - not applied for checking
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::chargeMonthlyFee () {
	// not applied for checking
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

void CheckingAccount::generateInterest () {
	try {
		if (Account::getBalance () >= Money (0, Account::getBalance ().getCurrency ())) {
			Account::generateInterest ();
		}
	}
	catch (const CurrencyMismatchException&) {}
}

//***************************************************************************
// Function:    applyMinBalanceFee
//
// Description: fee is charged if the balance falls below the minimum
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::applyMinBalanceFee () {
	try {
		if (Account::getBalance () < mcMinBalance && !mbIsBelowMinBalance) {
			Account::withdraw (mcMinBalanceFee);
			mbIsBelowMinBalance = true;
		}
	}
	catch (const CurrencyMismatchException&) {}
}

//***************************************************************************
// Function:    display
//
// Description: display checking account
//
// Parameters:  rcOutStream - stream to write to
//
// Returned:    none
//***************************************************************************

void CheckingAccount::display (std::ostream& rcOutStream) const {
	Account::display (rcOutStream);
	rcOutStream << std::fixed << std::setprecision (2);
	rcOutStream << mcMinBalance << ", " << mcMinBalanceFee;
}

//***************************************************************************
// Function:    read
//
// Description: read checking account info
//
// Parameters:  rcInStream - stream to read from
//
// Returned:    none
//***************************************************************************

void CheckingAccount::read (std::istream& rcInStream) {
	Account::read (rcInStream);
	rcInStream >> mcMinBalance >> mcMinBalanceFee;
}