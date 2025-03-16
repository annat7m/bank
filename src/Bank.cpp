//***************************************************************************
// File name:   Bank.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
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
// Parameters:  amount - 
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
// Parameters:  amount - 
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
// Description: Displays information for all accounts in the bank
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void Bank::display () {
	for (const auto& account : mAccounts) {
		account->displayAccount ();
		std::cout << std::endl;
	}
}
