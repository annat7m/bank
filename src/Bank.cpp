//***************************************************************************
// File name:   Bank.cpp
// Author:      Anna Tymoshenko
// Date:        03/18/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"
#include "../include/IContainer.h"
#include <iostream>
#include <fstream>

//***************************************************************************
// Constructor: Bank
//
// Description: 
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

Bank::Bank (std::shared_ptr<IContainer> container) {
	mAccounts = container;
}

//***************************************************************************
// Constructor: Bank
//
// Description: 
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

Bank::Bank (IAccountReader& accountReader, 
	std::shared_ptr<IContainer> container) {
	unsigned int accNumber;
	std::shared_ptr<Account> account;
	mAccounts = container;
	while ((account = accountReader.readAccount ())) {
		accNumber = account->getAccountNumber ();
		if (!mAccounts->bAccountExists (accNumber)) {
			mAccounts->addAccount (accNumber, account);
		}
	}
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

void Bank::deposit (unsigned int accNumber, const Money& amount) {
	std::shared_ptr<Account> account = mAccounts->getAccount (accNumber);
	if (account) {
		account->deposit (amount);
	}
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

void Bank::withdraw (unsigned int accNumber, const Money& amount) {
	std::shared_ptr<Account> account = mAccounts->getAccount (accNumber);
	if (account) {
		account->withdraw (amount);
	}
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
	std::shared_ptr<Account> account = mAccounts->getFirst ();
	while (account) {
		account->chargeMonthlyFee ();
		account = mAccounts->getNext ();
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
	mAccounts->print (rcOutStream);
}
