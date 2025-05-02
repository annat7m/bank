//***************************************************************************
// File name:   Account.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include <iostream>
#include <memory>
#include "../include/Interest.h"
#include "../include/Money.h"

#pragma once

class AccountVisitor;

class Account {

public:
	Account (unsigned int accountNumber, const Money& rcBalance,
		std::shared_ptr<Interest>& rpcInterestRate);
	virtual ~Account ();

	virtual void deposit (const Money& rcAmount) = 0;
	virtual void withdraw (const Money& rcAmount) = 0;
	virtual void chargeMonthlyFee ();
	virtual void generateInterest ();

	Money getBalance () const;
	unsigned int getAccountNumber () const;
	bool operator== (unsigned int accountNum) const;

	virtual void displayConverted (std::ostream& rcOutStream,
		const Currency& rcCurrency) const;

	virtual void display (std::ostream& rcOutStream) const;
	virtual void read (std::istream& rcInStream);

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Account& rcAccount);
	friend std::istream& operator>> (std::istream& rcInStream, Account& rcAccount);

	virtual void accept (AccountVisitor& rcAccountVisitor) = 0;

private:
	unsigned int mAccountNumber;
	Money mBalance;
	std::shared_ptr<Interest> mpInterestRate;

};