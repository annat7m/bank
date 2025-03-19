//***************************************************************************
// File name:   Bank.cpp
// Author:      Anna Tymoshenko
// Date:        03/18/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"
#include <iostream>
#include <fstream>

//***************************************************************************
// Constructor: Bank
//
// Description: Default constructor
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

Bank::Bank () {}

//***************************************************************************
// Constructor: Bank
//
// Description: 
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

Bank::Bank (IAccountReader& accountReader) {

}

//***************************************************************************
// Destructor:  Bank
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

Bank::~Bank () {}

//***************************************************************************
// Function:    deposit
//
// Description: 
//
// Parameters:  amount - amount to deposit to account
//
// Returned:    none
//***************************************************************************

void Bank::deposit (const Money& amount) {
	
}

//***************************************************************************
// Function:    withdraw
//
// Description: 
//
// Parameters:  amount - amount to withdraw from account
//
// Returned:    none
//***************************************************************************

void Bank::withdraw (const Money& amount) {

}

//***************************************************************************
// Function:    applyMonthlyUpdates
//
// Description: Applies monthly updates to all accounts in the Bank
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Bank::applyMonthlyUpdates () {

	for (auto& account : mAccounts) {
		account->chargeMonthlyFee ();
		account->accrueInterest ();
	}
}

//***************************************************************************
// Function:    display
//
// Description: Displays information for all accounts that are in the bank
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Bank::display (std::ostream& rcOutStream) const {
	mAccounts->print(rcOutStream);
}
