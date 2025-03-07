//***************************************************************************
// File name:   CheckingAccount.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CheckingAccount.h"
#include "../include/Account.h"
#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: CheckingAccount
//
// Description: Initializes Checking Account object in Banking system
//
// Parameters:  accountNumber - account number
//              balance       - initial balance
//              interestRate  - annual interest rate
//              minBalance    - minimum balance allowed
//              minBalanceFee - fee charged if the balance falls below the 
//															minimum
//
// Returned:    None
//***************************************************************************

CheckingAccount::CheckingAccount (int accountNumber, long long balance,
	double interestRate, long long minBalance, long long minBalanceFee)
	: Account (accountNumber, balance, interestRate) {
	mMinBalance = minBalance;
	mMinBalanceFee = minBalanceFee;
}

//***************************************************************************
// Destructor:  CheckingAccount
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

CheckingAccount::~CheckingAccount () {}

//***************************************************************************
// Function:    deposit
//
// Description: apply deposit operation on checking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::deposit (long long amount) {
	Account::deposit (amount);
}

//***************************************************************************
// Function:    withdraw
//
// Description: withdraw money from checking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::withdraw (long long amount) {
	Account::withdraw (amount);
	applyMinBalanceFee ();
	if (Account::getBalance () < 0) {
		adjustBalance (-Account::getBalance ());
	}
}

//***************************************************************************
// Function:    applyMinBalanceFee
//
// Description: fee is charged if the balance falls below the minimum
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

bool CheckingAccount::applyMinBalanceFee () {
	if (Account::getBalance () < mMinBalance) {
		adjustBalance (-mMinBalanceFee);
		addTransaction (TransactionType::fee, mMinBalanceFee);
		if (Account::getBalance () < 0) {
			adjustBalance (-Account::getBalance ());
		}
		return true;
	}
	return false;
}

//***************************************************************************
// Function:    displayAccount
//
// Description: display checking account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CheckingAccount::displayAccount () const {
	std::cout << std::fixed << std::setprecision (2) << Account::getAccountNumber ()
		<< ", $" << Account::getBalance () * Account::getInterestRate ()
		<< ", " << Account::getInterestRate () * 100 << "%, ";
	std::cout << mMinBalance << ", " << mMinBalanceFee;
}