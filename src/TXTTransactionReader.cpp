//***************************************************************************
// File name:   TXTTransactionReader.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/TXTTransactionReader.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include <fstream>
#include <sstream>
#include <iostream>

//***************************************************************************
// Constructor: TXTTransactionReader
//
// Description: Open the file for reading
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

TXTTransactionReader::TXTTransactionReader(const std::string& fileName) {
	mcCommandsFile.open(fileName);
	if (!mcCommandsFile.is_open()) {
		throw std::system_error (errno, std::system_category (),
			"Error: Could not open file: " + fileName + "\n");
	}
}

//***************************************************************************
// Destructor:  TXTTransactionReader
//
// Description: Makes sure file is closed
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TXTTransactionReader::~TXTTransactionReader () {
	if (mcCommandsFile.is_open ()) {
		mcCommandsFile.close ();
	}
}

//***************************************************************************
// Function:    readAccounts
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void TXTTransactionReader::readTransactions(Bank& bank) {
	const char WITHDRAW = 'W';
	const char DEPOSIT = 'D';
	const char PRINT = 'P';
	const char CHARGE = 'M';

	std::string line;
	char command;
	int accountNumber;
	long long amount;

	std::shared_ptr<Account> account;

	if (!mcCommandsFile.is_open()) {
		return;
	}

	while (mcCommandsFile >> command) {
		if (command == WITHDRAW) {
			mcCommandsFile >> accountNumber >> amount;
			account = bank.findAccount(accountNumber);
			account->withdraw(amount);
		} else if (command == DEPOSIT) {
			mcCommandsFile >> accountNumber >> amount;
			account = bank.findAccount(accountNumber);
			account->deposit(amount);
		} else if (command == PRINT) {
			bank.display ();
		} else if (command == CHARGE) {
			bank.applyMonthlyUpdates();
		}
	}
}
