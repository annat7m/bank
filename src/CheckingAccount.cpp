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
#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: CheckingAccount
//
// Description: Initializes Checking Account object in Banking system
//
// Parameters:  accountNumber - account number
//              balance       - initial balance
//              interestRate  - annual interest rate
//              minBalance    - minimum balance allowed
//              minBalanceFee - fee charged if the balance falls below the 
//															minimum
//
// Returned:    None
//***************************************************************************

CheckingAccount::CheckingAccount (unsigned int accountNumber,
	const Money& balance, const Interest& interestRate,
	const Money& minBalance, const Money& minBalanceFee)
	: Account (accountNumber, balance, interestRate) {
	mMinBalance = minBalance;
	mMinBalanceFee = minBalanceFee;
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
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::deposit (const Money& amount) {
	Account::deposit (amount);
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from checking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::withdraw (const Money& amount) {
	Account::withdraw (amount);
	applyMinBalanceFee ();
}

//***************************************************************************
// Function:    chargeMonthlyFee
//
// Description: charge the checking account the monthly fee
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::chargeMonthlyFee () {
	Account::chargeMonthlyFee ();
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
	if (Account::getBalance () < mMinBalance) {
		Account::withdraw (mMinBalanceFee);
		// addTransaction (TransactionType::fee, mMinBalanceFee);
	}
}

//***************************************************************************
// Function:    displayAccount
//
// Description: display checking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::display (std::ostream& rcOutStream) const {
	Account::display (rcOutStream);
	rcOutStream << std::fixed << std::setprecision (2);
	rcOutStream << mMinBalance << ", " << mMinBalanceFee;
}

//***************************************************************************
// Function:    read
//
// Description: read checking account info
//
// Parameters:  rcInStream - stream to take input from
//
// Returned:    none
//***************************************************************************

void CheckingAccount::read (std::istream& rcInStream) {
	Account::read (rcInStream);
	rcInStream >> mMinBalance >> mMinBalanceFee;
}