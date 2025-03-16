//***************************************************************************
// File name:   SavingAccount.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <vector>
#include "../include/Account.h"
#include "../include/Interest.h"

#pragma once

class SavingsAccount : public Account {

public:
	SavingsAccount (unsigned int accNumber, const Money& accBalance,
		const Interest& accInterestRate,
		const Money& minBalance, const Money& monthlyFee);
	virtual ~SavingsAccount ();

	virtual void deposit (const Money& amount) override;
	virtual void withdraw (const Money& amount) override;
	virtual void chargeMonthlyFee () override;

	virtual void display (std::ostream& rcOutStream) const override;
	virtual void read (std::istream& rcInStream) const override;

private:
	Money mMinBalance;
	Money mMonthlyFee;
	bool mbIsBelowMinBalance;

};