//***************************************************************************
// File name:   TXTAccountReader.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/TXTAccountReader.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include "../include/FlatInterest.h"
#include "../include/TieredInterest.h"
#include <fstream>
#include <sstream>
#include <iostream>

//***************************************************************************
// Constructor: TXTAccountReader
//
// Description: Open the file for reading
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

TXTAccountReader::TXTAccountReader (const std::string& fileName) {
	mcAccountsFile.open (fileName);
	if (!mcAccountsFile.is_open ()) {
		throw std::system_error (errno, std::system_category (),
			"Error: Could not open file: " + fileName + "\n");
	}
}

//***************************************************************************
// Destructor:  TXTAccountReader
//
// Description: Makes sure file is closed
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TXTAccountReader::~TXTAccountReader () {
	if (mcAccountsFile.is_open ()) {
		mcAccountsFile.close ();
	}
}

//***************************************************************************
// Function:    readAccounts
//
// Description: read file with accounts amd add them to the bank
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

std::shared_ptr<Account> TXTAccountReader::readAccount () {
	const char SAVINGS = 'S';
	const char CHECKING = 'C';
	const char FLAT = 'F';
	const char TIERED = 'T';

	char accountType = '\0';
	char interestType = '\0';

	int accountNumber;
	Money initialBalance;
	Money monthlyFee, minMonthlyBalance;
	Money MinBalance, MinBalanceFee;
	double rate;

	std::shared_ptr<Account> account;
	std::shared_ptr<Interest> interest;

	if (!mcAccountsFile.is_open ()) {
		return nullptr;
	}

	mcAccountsFile >> accountType;

	mcAccountsFile >> accountNumber >> initialBalance >> interestType;

	if (mcAccountsFile.fail ()) {
		return nullptr;
	}

	if (accountType == SAVINGS) {
		if (interestType == FLAT) {
			mcAccountsFile >> rate;
			mcAccountsFile >> monthlyFee >> minMonthlyBalance;
			account = std::make_shared<SavingsAccount> (accountNumber, initialBalance,
				FlatInterest (rate), monthlyFee, minMonthlyBalance);
		}

		else if (interestType == TIERED) {
			interest = std::make_shared<TieredInterest>();
			interest->read (mcAccountsFile);
			mcAccountsFile >> monthlyFee >> minMonthlyBalance;
			account = std::make_shared<SavingsAccount> (accountNumber, initialBalance,
				TieredInterest (), monthlyFee, minMonthlyBalance);
		}
	}
	else if (accountType == CHECKING) {
		if (interestType == FLAT) {
			mcAccountsFile >> rate;
			mcAccountsFile >> MinBalance >> MinBalanceFee;
			account = std::make_shared<CheckingAccount> (accountNumber, initialBalance,
				FlatInterest (rate), MinBalance, MinBalanceFee);
		}

		else if (interestType == TIERED) {
			interest = std::make_shared<TieredInterest>();
			interest->read (mcAccountsFile);
			mcAccountsFile >> MinBalance >> MinBalanceFee;
			account = std::make_shared<SavingsAccount> (accountNumber, initialBalance,
				TieredInterest (), MinBalance, MinBalanceFee);
		}
	}

	if (mcAccountsFile.fail ()) {
		return nullptr;
	}

	return account;

}
