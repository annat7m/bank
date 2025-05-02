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
#include "../include/AccountVisitor.h"

#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: CheckingAccount
//
// Description: Initializes Checking Account object in Banking system
//
// Parameters:  accountNumber 	- account number
//              rcBalance       - initial balance
//              rpcInterestRate - annual interest rate
//              rcMinBalance    - minimum balance allowed
//              rcMinBalanceFee - fee charged if the balance falls below the 
//																minimum
//
// Returned:    None
//***************************************************************************

CheckingAccount::CheckingAccount (unsigned int accountNumber,
	const Money& rcBalance, std::shared_ptr<Interest>& rpcInterestRate,
	const Money& rcMinBalance, const Money& rcMinBalanceFee)
	: Account (accountNumber, rcBalance, rpcInterestRate),
	mcMinBalance (rcMinBalance), mcMinBalanceFee (rcMinBalanceFee) {

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
	bool wasAboveMin = Account::getBalance () >= mcMinBalance;

	Account::withdraw (rcAmount);

	if (wasAboveMin && (Account::getBalance () < mcMinBalance)) {
		Account::withdraw (mcMinBalanceFee);
		mbIsBelowMinBalance = true;
	}
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
	if (Account::getBalance () >= Money (0, Account::getBalance ().getCurrency ())) {
		Account::generateInterest ();
	}
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
	if (Account::getBalance () < mcMinBalance && !mbIsBelowMinBalance) {
		Account::withdraw (mcMinBalanceFee);
		mbIsBelowMinBalance = true;
	}
}

//***************************************************************************
// Function:    displayConverted
//
// Description: display converted to a given currency account info to the stream 
//
// Parameters:  rcOutStream - reference to the stream to output to
//							rcCurrency	- reference to the currency account needs to be
//														converted to
//
// Returned:    none
//***************************************************************************

void CheckingAccount::displayConverted (std::ostream& rcOutStream,
	const Currency& rcCurrency) const {
	Account::displayConverted (rcOutStream, rcCurrency);
	try {
		Money cConvertedMinBal = mcMinBalance.convertTo (rcCurrency);
		rcOutStream << std::fixed << std::setprecision (2);
		rcOutStream << cConvertedMinBal << ", ";
	}
	catch (const CurrencyMismatchException&) {
		rcOutStream << std::fixed << std::setprecision (2);
		rcOutStream << mcMinBalance << ", ";
	}
	try {
		Money cConvertedMinBalFee = mcMinBalanceFee.convertTo (rcCurrency);
		rcOutStream << std::fixed << std::setprecision (2);
		rcOutStream << cConvertedMinBalFee;
	}
	catch (const CurrencyMismatchException&) {
		rcOutStream << std::fixed << std::setprecision (2);
		rcOutStream << mcMinBalanceFee;
	}
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

//***************************************************************************
// Function:    accept
//
// Description: Accept a visitor for a checking account
//
// Parameters:  rcAccountVisitor - reference to the visitor
//
// Returned:    none
//***************************************************************************

void CheckingAccount::accept (AccountVisitor& rcAccountVisitor) {
	rcAccountVisitor.visit (*this);
}