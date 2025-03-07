//***************************************************************************
// File name:   CheckingAccount.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include "../include/Account.h"

#pragma once

class CheckingAccount : public Account {

	public:
		CheckingAccount (int accNumber, long long accBalance, double accInterestRate,
			long long minBalance, long long minBalanceFee);
		~CheckingAccount() override = default;

		virtual void deposit (long long amount) override;
		virtual void withdraw (long long amount) override;

	private:
		long long mMinBalance;
		long long mMinBalanceFee;

		bool applyMinBalanceFee();

};