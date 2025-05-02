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
#include "../include/CurrencyMismatchException.h"

#include "../include/WithdrawCommand.h"
#include "../include/DepositCommand.h"
#include "../include/PrintCommand.h"
#include "../include/MonthlyCommand.h"
#include "../include/BackupCommand.h"
#include "../include/CurrencyCommand.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: TXTTransactionReader
//
// Description: Open the file for reading
//
// Parameters:  rcFileName - name of the file to open
//
// Returned:    None
//***************************************************************************

TXTTransactionReader::TXTTransactionReader (const std::string& rcFileName) {
	mcCommandsFile.open (rcFileName);
	if (!mcCommandsFile.is_open ()) {
		throw std::system_error (errno, std::system_category (),
			"Error: Could not open file: " + rcFileName + "\n");
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
// Function:    readTransactions
//
// Description: read file with commands amd process the data according to it
//
// Parameters:  rcOutStream	- stream to output account to when command is P
//							rcBank			- Bank object to perform needed operations on
//
// Returned:    a shared_ptr to the created Command
//***************************************************************************

std::shared_ptr<ICommand> TXTTransactionReader::readTransactions (std::ostream&
	rcOutStream, Bank& rcBank) {
	const char WITHDRAW = 'W';
	const char DEPOSIT = 'D';
	const char PRINT = 'P';
	const char CHARGE = 'M';
	const char BACKUP = 'B';
	const char CURRENCY = 'C';

	char command;
	int accountNumber;
	long long amount;
	std::string currencyString;

	if (!mcCommandsFile.is_open ()) {
		return nullptr;
	}

	if (!(mcCommandsFile >> command)) {
		return nullptr;
	}

	if (command == WITHDRAW) {
		mcCommandsFile >> accountNumber >> currencyString >> amount;
		Currency cCurrency (currencyString);
		return std::make_shared<WithdrawCommand> (std::make_shared<Bank> (rcBank),
			accountNumber, Money (amount, cCurrency));
	}
	else if (command == DEPOSIT) {
		mcCommandsFile >> accountNumber >> currencyString >> amount;
		Currency cCurrency (currencyString);
		return std::make_shared<DepositCommand> (std::make_shared<Bank> (rcBank),
			accountNumber, Money (amount, cCurrency));
	}
	else if (command == PRINT) {
		return std::make_shared<PrintCommand> (std::make_shared<Bank> (rcBank),
			rcOutStream);
	}
	else if (command == CHARGE) {
		return std::make_shared<MonthlyCommand> (std::make_shared<Bank> (rcBank));
	}
	else if (command == BACKUP) {
		std::string cCheckingFileName;
		std::string cSavingFileName;
		mcCommandsFile >> cCheckingFileName >> cSavingFileName;
		return std::make_shared<BackupCommand> (std::make_shared<Bank> (rcBank),
			cCheckingFileName, cSavingFileName);
	}
	else if (command == CURRENCY) {
		mcCommandsFile >> currencyString;
		Currency cCurrency (currencyString);
		return std::make_shared<CurrencyCommand> (std::make_shared<Bank> (rcBank),
			rcOutStream, cCurrency);
	}

	return nullptr;
}
