//***************************************************************************
// File name:   CSVTransactionReader.cpp
// Author:      Anna Tymoshenko
// Date:        04/06/2025
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
// Parameters:  rcOutStream	- stream to output account to when command is P
//							rcBank			- Bank object to perform needed operations on
//
// Returned:    
//***************************************************************************

std::shared_ptr<ICommand> CSVTransactionReader::readTransactions (std::ostream& rcOutStream,
	Bank& rcBank) {
	const char WITHDRAW = 'W';
	const char DEPOSIT = 'D';
	const char PRINT = 'P';
	const char CHARGE = 'M';

	std::string line;

	while (std::getline (mcCommandsFile, line)) {
		if (line.empty ()) {
			continue;
		}

		std::stringstream cStrStream (line);
		std::string cLine;
		std::getline (cStrStream, cLine, ',');

		char command = cLine[0];

		if (command == WITHDRAW || command == DEPOSIT) {
			std::getline (cStrStream, cLine, ',');
			int accountNumber = std::stoi (cLine);

			std::getline (cStrStream, cLine, ',');
			std::stringstream currencyStream (cLine);
			std::string currencyStr;
			long long amount;

			currencyStream >> currencyStr >> amount;
			Currency currency (currencyStr);
			Money money (amount, currency);

			if (command == WITHDRAW) {
				rcBank.withdraw (accountNumber, money);
			}
			else {
				rcBank.deposit (accountNumber, money);
			}
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
