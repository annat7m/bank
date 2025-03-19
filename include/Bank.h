//***************************************************************************
// File name:   Bank.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <vector>
#include <memory>
#include "../include/Account.h"
#include "../include/IAccountReader.h"
#include "../include/IContainer.h"

#pragma once

class Bank {

public:
	Bank ();
	Bank (IAccountReader& accountReader);
	virtual ~Bank ();

	void deposit (const Money& amount);
	void withdraw (const Money& amount);

	void applyMonthlyUpdates ();
	void display (std::ostream& rcOutStream) const;

private:
	std::shared_ptr<IContainer> mAccounts;

};