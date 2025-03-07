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

void TXTAccountReader::readAccounts (Bank& bank) {
	const char SAVINGS = 'S';
	const char CHECKING = 'C';
	std::string line;
	int accountNumber;
	long long balance;
	double interestRate;
	double minBalanceFee;
	long long minBalance;
	long long monthlyFee;
	char accountType;
	std::shared_ptr<Account> account;

	if (!mcAccountsFile.is_open ()) {
		return;
	}

	while (mcAccountsFile >> accountType >> accountNumber >> balance >> interestRate) {
		if (accountType == SAVINGS) {
			mcAccountsFile >> monthlyFee >> minBalance;
			account = std::make_shared<SavingsAccount> (accountNumber, balance,
				interestRate, minBalance, monthlyFee);
		}
		else if (accountType == CHECKING) {
			mcAccountsFile >> minBalance >> minBalanceFee;
			account = std::make_shared<CheckingAccount> (accountNumber, balance,
				interestRate, minBalance, minBalanceFee);
		}

		if (account) {
			bank.addAccount (account);
		}
	}
}
