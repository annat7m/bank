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
#include <fstream>
#include <sstream>
#include <iostream>

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
// Returned:    none
//***************************************************************************

void TXTTransactionReader::readTransactions (std::ostream& rcOutStream,
	Bank& rcBank) {
	const char WITHDRAW = 'W';
	const char DEPOSIT = 'D';
	const char PRINT = 'P';
	const char CHARGE = 'M';

	char command;
	int accountNumber;
	long long amount;
	std::string currencyString;

	if (!mcCommandsFile.is_open ()) {
		return;
	}

	while (mcCommandsFile >> command) {
		if (command == WITHDRAW) {
			mcCommandsFile >> accountNumber >> currencyString >> amount;
			Currency cCurrency (currencyString);
			rcBank.withdraw (accountNumber, Money (amount, cCurrency));
		}
		else if (command == DEPOSIT) {
			mcCommandsFile >> accountNumber >> currencyString >> amount;
			Currency cCurrency (currencyString);
			rcBank.deposit (accountNumber, Money (amount, cCurrency));
		}
		else if (command == PRINT) {
			rcOutStream << "-------------" << std::endl;
			rcBank.display (rcOutStream);
			rcOutStream << "-------------" << std::endl;
		}
		else if (command == CHARGE) {
			rcBank.applyMonthlyUpdates ();
		}
	}
}
