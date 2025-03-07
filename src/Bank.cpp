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
// Parameters:  accounts - vector of smart pointers to Account objects
//
// Returned:    None
//***************************************************************************

Bank::Bank () {}

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
// Function:    addAccount
//
// Description: Adds an Account to the Bank
//
// Parameters:  account - smart pointer to an Account object
//
// Returned:    none
//***************************************************************************

void Bank::addAccount (std::shared_ptr<Account> account) {
	mAccounts.push_back (account);
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

//***************************************************************************
// Function:    findAccount
//
// Description: look up account in the bank
//
// Parameters:  accountNumber - account number
//
// Returned:    none
//***************************************************************************

std::shared_ptr<Account> Bank::findAccount (int accountNumber) {
	for (auto& account : mAccounts) {
		if (account->getAccountNumber () == accountNumber) {
			return account;
		}
	}
	return nullptr;
}

