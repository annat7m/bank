//***************************************************************************
// File name:   SavingAccount.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include "../include/Account.h"

#pragma once

class SavingAccount : public Account {

	public:
		SavingAccount (int accNumber, long long accBalance, double accInterestRate,
			long long minBalance, long long monthlyFee);
		virtual ~SavingAccount();

		virtual void deposit (long long amount);
		virtual void withdraw (long long amount);
		virtual void chargeMonthlyFee ();
		virtual void accrueInterest ();

	private:
		long long mMinBalance;
		long long mMonthlyFee;

};