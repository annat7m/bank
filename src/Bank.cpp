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
#include "../include/CurrencyMismatchException.h"
#include <iostream>
#include <fstream>

//***************************************************************************
// Constructor: Bank
//
// Description: Initializes Bank with a given container to manage accounts
//
// Parameters:  pcContainer - shared pointer to an IContainer object
//
// Returned:    None
//***************************************************************************

Bank::Bank (std::shared_ptr<IContainer> pcContainer) {
	mpAccounts = pcContainer;
}

//***************************************************************************
// Constructor: Bank
//
// Description: Initializes Bank and reads all account data using the given
//              IAccountReader object. Each account is added to the container
//              if it doesn't already exist
//
// Parameters:  rcAccountReader	- a reference to an account reader object
//              pcContainer			- shared pointer to an IContainer object
//
// Returned:    None
//***************************************************************************

Bank::Bank (IAccountReader& rcAccountReader,
	std::shared_ptr<IContainer> pcContainer) {
	unsigned int accNumber;
	std::shared_ptr<Account> account;
	mpAccounts = pcContainer;
	while ((account = rcAccountReader.readAccount ())) {
		accNumber = account->getAccountNumber ();
		if (!mpAccounts->bAccountExists (accNumber)) {
			mpAccounts->addAccount (accNumber, account);
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
// Description: Deposits the specified amount of money into the given account
//
// Parameters:  accNumber	- the account number to deposit into
//              amount		- amount to deposit to account
//
// Returned:    none
//***************************************************************************

void Bank::deposit (unsigned int accNumber, const Money& rcAmount) {
	// std::shared_ptr<Account> account = mpAccounts->getAccount (accNumber);
	// try {
		std::shared_ptr<Account> account = mpAccounts->getAccount (accNumber);
		account->deposit (rcAmount);
	// }
	// catch (const CurrencyMismatchException&) {}
}

//***************************************************************************
// Function:    withdraw
//
// Description: Withdraws the specified amount of money from the given account
//
// Parameters:  accNumber	- the account number to withdraw from
//              amount		- amount to withdraw from account
//
// Returned:    none
//***************************************************************************

void Bank::withdraw (unsigned int accNumber, const Money& rcAmount) {
	// try {
		std::shared_ptr<Account> account = mpAccounts->getAccount (accNumber);
		account->withdraw (rcAmount);
	// }
	// catch (const CurrencyMismatchException&) {}
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
	std::shared_ptr<Account> account = mpAccounts->getFirst ();
	while (account) {
		// try {
			account->chargeMonthlyFee ();
			account->generateInterest ();
		// }
		// catch (const CurrencyMismatchException&) {}
		account = mpAccounts->getNext ();
	}
}

//***************************************************************************
// Function:    display
//
// Description: Displays all accounts stored in the container
//
// Parameters:  rcOutStream - output stream to write to
//
// Returned:    none
//***************************************************************************

void Bank::display (std::ostream& rcOutStream) const {
	mpAccounts->print (rcOutStream);
}
