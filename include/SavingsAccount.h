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

class SavingsAccount : public Account {

	public:
		SavingsAccount (int accNumber, long long accBalance, double accInterestRate,
			long long minBalance, long long monthlyFee);
		~SavingsAccount() override = default;

		virtual void deposit (long long amount) override;
		virtual void withdraw (long long amount) override;
		virtual void chargeMonthlyFee () override;

	private:
		long long mMinBalance;
		long long mMonthlyFee;
		bool mbIsBelowMinBalance;

};