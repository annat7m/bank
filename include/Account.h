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
		Account (int number, long long balance, double interestRate);
		virtual ~Account();

		virtual void deposit (long long amount) = 0;
		virtual void withdraw (long long amount) = 0;
		virtual void chargeMonthlyFee () = 0;
		virtual void accrueInterest () = 0;

		void displayAccount ();

	private:
		int mNumber;
		long long mBalance;
		double mInterestRate;
		std::vector<Transaction> mTransactions;

};