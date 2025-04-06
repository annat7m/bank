//***************************************************************************
// File name:   CSVTransactionReader.cpp
// Author:      Anna Tymoshenko
// Date:        04/05/2025
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CSVTransactionReader.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include <fstream>
#include <sstream>
#include <iostream>

//***************************************************************************
// Constructor: CSVTransactionReader
//
// Description: Open the file for reading
//
// Parameters:  rcFileName - name of the file to open
//
// Returned:    None
//***************************************************************************

CSVTransactionReader::CSVTransactionReader (const std::string& rcFileName) {
	mcCommandsFile.open (rcFileName);
	if (!mcCommandsFile.is_open ()) {
		throw std::system_error (errno, std::system_category (),
			"Error: Could not open file: " + rcFileName + "\n");
	}
}

//***************************************************************************
// Destructor:  CSVTransactionReader
//
// Description: Makes sure file is closed
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

CSVTransactionReader::~CSVTransactionReader () {
	if (mcCommandsFile.is_open ()) {
		mcCommandsFile.close ();
	}
}

//***************************************************************************
// Function:    readTransactions
//
// Description: read file with commands amd process the data according to it
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CSVTransactionReader::readTransactions (std::ostream& rcOutStream,
	Bank& rcBank) {
	// const char WITHDRAW = 'W';
	// const char DEPOSIT = 'D';
	// const char PRINT = 'P';
	// const char CHARGE = 'M';

	// char command;
	// int accountNumber;
	// long long amount;
	// std::string currencyString;

	// if (!mcCommandsFile.is_open ()) {
	// 	return;
	// }

	// while (mcCommandsFile >> command) {
	// 	if (command == WITHDRAW) {
	// 		mcCommandsFile >> accountNumber >> currencyString >> amount;
	// 		Currency cCurrency(currencyString);
	// 		rcBank.withdraw (accountNumber, Money (amount, cCurrency));
	// 	}
	// 	else if (command == DEPOSIT) {
	// 		mcCommandsFile >> accountNumber >> currencyString >> amount;
	// 		Currency cCurrency(currencyString);
	// 		rcBank.deposit (accountNumber, Money (amount, cCurrency));
	// 	}
	// 	else if (command == PRINT) {
	// 		rcOutStream << "-------------" << std::endl;
	// 		rcBank.display (rcOutStream);
	// 		rcOutStream << "-------------" << std::endl;
	// 	}
	// 	else if (command == CHARGE) {
	// 		rcBank.applyMonthlyUpdates ();
	// 	}
	// }
}
