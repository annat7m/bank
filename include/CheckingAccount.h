//***************************************************************************
// File name:   CheckingAccount.h
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

class CheckingAccount : public Account {

public:
	CheckingAccount (unsigned int accNumber, const Money& rcBalance,
		std::shared_ptr<Interest>& rpcInterestRate,
		const Money& rcMinBalance, const Money& rcMinBalanceFee);
	virtual ~CheckingAccount () override;

	virtual void deposit (const Money& rcAmount) override;
	virtual void withdraw (const Money& rcAmount) override;
	virtual void chargeMonthlyFee () override;
	virtual void generateInterest () override;

	virtual void display (std::ostream& rcOutStream) const override;
	virtual void read (std::istream& rcInStream) override;

private:
	Money mcMinBalance;
	Money mcMinBalanceFee;
	bool mbIsBelowMinBalance = false;
	
	void applyMinBalanceFee ();

};