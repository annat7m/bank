//***************************************************************************
// File name:   Account.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include "../include/Transaction.h"

#pragma once

class Account {

public:
	Account (int accountNumber, long long balance, double interestRate);
	virtual ~Account ();

	virtual void deposit (long long amount) = 0;
	virtual void withdraw (long long amount) = 0;
	virtual void chargeMonthlyFee ();
	virtual void accrueInterest ();
	virtual void addTransaction (TransactionType transactionType,
		long long amount);

	virtual void displayAccount () const = 0;

	int getAccountNumber () const;
	long long getBalance () const;
	double getInterestRate () const;

private:
	int mAccountNumber;
	long long mBalance;
	double mInterestRate;
	std::vector<Transaction> mTransactions;

protected:
	void adjustBalance (long long amount);

};