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

#include "../include/PrintVisitor.h"
#include "../include/MonthlyVisitor.h"
#include "../include/BackupVisitor.h"
#include "../include/CurrencyVisitor.h"

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
	mpCommands = nullptr;

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
//              pcAccount	- amount to deposit to account
//
// Returned:    none
//***************************************************************************
void Bank::deposit (unsigned int accNumber, const Money& rcAmount) {
	std::shared_ptr<Account> pcAccount = mpAccounts->getAccount (accNumber);
	pcAccount->deposit (rcAmount);
}

//***************************************************************************
// Function:    withdraw
//
// Description: Withdraws the specified amount of money from the given account
//
// Parameters:  accNumber	- the account number to withdraw from
//              pcAccount	- amount to withdraw from account
//
// Returned:    none
//***************************************************************************
void Bank::withdraw (unsigned int accNumber, const Money& rcAmount) {
	std::shared_ptr<Account> pcAccount = mpAccounts->getAccount (accNumber);
	pcAccount->withdraw (rcAmount);
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
	MonthlyVisitor cMonthlyVisitor;
	mpAccounts->applyVisitor (cMonthlyVisitor);
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
	PrintVisitor cPrintVisitor (rcOutStream);
	mpAccounts->applyVisitor (cPrintVisitor);
}

//***************************************************************************
// Function:    backupAccounts
//
// Description: Displays all savings to its assigned file and checking accounts
//							to its
//
// Parameters:  rcOutStream_S	- reference to the output stream for savings
//															accounts
//							rcOutStream_C	- reference to the output stream for checking
//															accounts
//
// Returned:    none
//***************************************************************************
void Bank::backupAccounts (std::ostream& rcOutStream_S,
	std::ostream& rcOutStream_C) {
	BackupVisitor cBackupVisitor (rcOutStream_S, rcOutStream_C);
	mpAccounts->applyVisitor (cBackupVisitor);
}

//***************************************************************************
// Function:    switchToCurrency
//
// Description: Switch all accounts to a particular currency
//
// Parameters:  rcOutStream	- reference to the output stream
//							cCurrency		- currency to convert all accounts monetary values to
//
// Returned:    none
//***************************************************************************
void Bank::switchToCurrency (std::ostream& rcOutStream, Currency cCurrency) {
	CurrencyVisitor cCurrencyVisitor (rcOutStream, cCurrency);
	mpAccounts->applyVisitor (cCurrencyVisitor);
}

//***************************************************************************
// Function:    logCurrencyException
//
// Description: Logging currency mismatch exception to log file
//
// Parameters:  rcCommand     	- command that triggered the exception
//    					accountNumber		- account number where the mismatch occurred
//    					rcFromCurrency	- source currency
//    					rcToCurrency		- destination currency
//
// Returned:    Reference to the output stream used
//***************************************************************************
std::ostream& Bank::logCurrencyException (const std::string& rcCommand,
	unsigned int accountNumber, const Currency& rcFromCurrency,
	const Currency& rcToCurrency) {

	static std::ofstream cLogFile ("CurrencyExceptions.log");
	if (!cLogFile.is_open ()) {
		throw std::runtime_error ("Failed to open CurrencyExceptions.log");
	}

	cLogFile << "COMMAND: " << rcCommand << " ACCOUNT: " << accountNumber
		<< " CurrencyMismatchException: FROM: " << rcFromCurrency
		<< " TO: " << rcToCurrency << std::endl;

	return cLogFile;
}