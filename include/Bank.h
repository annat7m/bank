//***************************************************************************
// File name:   Bank.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include <memory>
#include "../include/Account.h"

#pragma once

class Bank {

	public:
		Bank ();
		virtual ~Bank();

		void addAccount (std::shared_ptr<Account> account);
		void applyMonthlyUpdates();
		std::shared_ptr<Account> findAccount (int accountNumber);

		void display ();

	private:
		std::vector<std::shared_ptr<Account>> mAccounts;

};