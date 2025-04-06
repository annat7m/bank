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
	Bank (std::shared_ptr<IContainer> pcContainer);
	Bank (IAccountReader& rcAccountReader, std::shared_ptr<IContainer> pcContainer);
	virtual ~Bank ();

	void deposit (unsigned int accNumber, const Money& rcAmount);
	void withdraw (unsigned int accNumber, const Money& rcAmount);

	void applyMonthlyUpdates ();
	void display (std::ostream& rcOutStream) const;

private:
	std::shared_ptr<IContainer> mpAccounts;

};