//***************************************************************************
// File name:   CheckingAccount.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include "../include/Account.h"
#include "../include/Interest.h"

#pragma once

class CheckingAccount : public Account {

public:
	CheckingAccount (unsigned int accNumber, const Money& accBalance,
		const Interest& accInterestRate,
		const Money& minBalance, const Money& minBalanceFee);
	virtual ~CheckingAccount ();

	virtual void deposit (const Money& amount) override;
	virtual void withdraw (const Money& amount) override;

	virtual void displayAccount (std::ostream& rcOutStream) const override;
	virtual void read (std::istream& rcInStream) const override;

private:
	Money mMinBalance;
	Money mMinBalanceFee;

	bool applyMinBalanceFee ();

};