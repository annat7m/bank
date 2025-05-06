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
#include "../include/CurrencyMismatchException.h"
#include <fstream>
#include <sstream>
#include <iostream>

//***************************************************************************
// Constructor: TXTAccountReader
//
// Description: Open the file for reading
//
// Parameters:  rcFileName - name of the file to open
//
// Returned:    None
//***************************************************************************

TXTAccountReader::TXTAccountReader (const std::string& rcFileName) {
	mcAccountsFile.open (rcFileName);
	if (!mcAccountsFile.is_open ()) {
		throw std::system_error (errno, std::system_category (),
			"Error: Could not open file: " + rcFileName + "\n");
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
	std::string currencyString;
	long long initialBalance;

	std::shared_ptr<Account> account;
	std::shared_ptr<Interest> interest;

	if (!mcAccountsFile.is_open ()) {
		return nullptr;
	}

	mcAccountsFile >> accountType;
	mcAccountsFile >> accountNumber >> currencyString >> initialBalance >> interestType;

	if (mcAccountsFile.fail ()) {
		return nullptr;
	}

	Currency cCurrency (currencyString);
	Money cInitialBalance (initialBalance, cCurrency);

	if (accountType == SAVINGS) {
		if (interestType == FLAT) {
			double rate;
			mcAccountsFile >> rate;
			interest = std::make_shared<FlatInterest> (rate);

			std::string monthlyFeeCurrency, minBalanceCurrency;
			long long monthlyFeeAmount, minBalanceAmount;

			mcAccountsFile >> monthlyFeeCurrency >> monthlyFeeAmount
				>> minBalanceCurrency >> minBalanceAmount;

			Money monthlyFee (monthlyFeeAmount, Currency (monthlyFeeCurrency));
			Money minMonthlyBalance (minBalanceAmount, Currency (minBalanceCurrency));

			account = std::make_shared<SavingsAccount> (accountNumber, cInitialBalance,
				interest, minMonthlyBalance, monthlyFee);
		}
		else if (interestType == TIERED) {
			interest = std::make_shared<TieredInterest> ();
			mcAccountsFile >> interest;

			std::string monthlyFeeCurrency, minBalanceCurrency;
			long long monthlyFeeAmount, minBalanceAmount;

			mcAccountsFile >> monthlyFeeCurrency >> monthlyFeeAmount
				>> minBalanceCurrency >> minBalanceAmount;

			Money monthlyFee (monthlyFeeAmount, Currency (monthlyFeeCurrency));
			Money minMonthlyBalance (minBalanceAmount, Currency (minBalanceCurrency));

			account = std::make_shared<SavingsAccount> (accountNumber, cInitialBalance,
				interest, minMonthlyBalance, monthlyFee);
		}
	}
	else if (accountType == CHECKING) {
		if (interestType == FLAT) {
			double rate;
			mcAccountsFile >> rate;
			interest = std::make_shared<FlatInterest> (rate);

			std::string minBalanceCurrency, feeCurrency;
			long long minBalanceAmount, feeAmount;

			mcAccountsFile >> minBalanceCurrency >> minBalanceAmount
				>> feeCurrency >> feeAmount;

			Money minBalance (minBalanceAmount, Currency (minBalanceCurrency));
			Money fee (feeAmount, Currency (feeCurrency));

			account = std::make_shared<CheckingAccount> (accountNumber, cInitialBalance,
				interest, minBalance, fee);
		}
		else if (interestType == TIERED) {
			interest = std::make_shared<TieredInterest> ();
			mcAccountsFile >> interest;

			std::string minBalanceCurrency, feeCurrency;
			long long minBalanceAmount, feeAmount;

			mcAccountsFile >> minBalanceCurrency >> minBalanceAmount
				>> feeCurrency >> feeAmount;

			Money minBalance (minBalanceAmount, Currency (minBalanceCurrency));
			Money fee (feeAmount, Currency (feeCurrency));

			account = std::make_shared<CheckingAccount> (accountNumber, cInitialBalance,
				interest, minBalance, fee);
		}
	}

	if (mcAccountsFile.fail ()) {
		return nullptr;
	}

	return account;

}
