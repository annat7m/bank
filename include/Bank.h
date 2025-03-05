//***************************************************************************
// File name:   Bank.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include "../include/Account.h"

#pragma once

class Bank : public Account {

	public:
		Bank ();
		virtual ~Bank();

		void addAccount (Account& account); // might be virtual
		void applyMonthlyUpdates();					// might be virtual

	private:
		std::vector<Account> mAccounts;

};