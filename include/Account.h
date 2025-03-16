//***************************************************************************
// File name:   Account.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include <memory>
#include "../include/Transaction.h"
#include "../include/Interest.h"
#include "../include/Money.h"

#pragma once

class Account {

public:
	Account (unsigned int accountNumber, const Money& balance,
		const Interest& interestRate);
	virtual ~Account ();

	virtual void deposit (const Money& amount) = 0;
	virtual void withdraw (const Money& amount) = 0;
	virtual void chargeMonthlyFee ();
	virtual void generateInterest ();
	virtual void addTransaction (TransactionType transactionType,
		const Money& amount);

	virtual void accrueInterest ();

	Money getBalance () const;
	bool operator== (unsigned int accountNum) const;
	virtual void display (std::ostream& rcOutStream) const = 0;
	virtual void read (std::istream& rcInStream) const;

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Account& account);
	friend std::istream& operator>> (std::istream& rcOutStream,
		const Account& account);

private:
	unsigned int mAccountNumber;
	Money mBalance;
	std::shared_ptr<Interest> mInterestRate;
	std::vector<Transaction> mTransactions;

};