//***************************************************************************
// File name:   Money.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include "../include/Currency.h"

#pragma once

class Money {

public:
	Money (const Money& rcMoney);
	Money (long long amount, Currency cCurrency);
	virtual ~Money ();

	Money& operator= (Money other);
	Money& operator+= (const Money& rcOther);
	Money& operator-= (const Money& rcOther);
	Money operator* (double multiplier) const;

	bool operator==(const Money& rcOther) const;
	bool operator< (const Money& rcOther) const;
	bool operator>= (const Money& rcOther) const;

	long long operator () () const;

	Currency getCurrency() const;

	void display (std::ostream& rcOutStream) const;
	void read (std::istream& rcInStream);

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Money& rcAmount);
	friend std::istream& operator>> (std::istream& rcInStream,
		Money& rcAmount);

	Money convertTo (const Currency& rcCurrency) const;

private:
	long long mAmount;
	Currency mcCurrency;

};

// non-member, non-friend operators
Money operator+(const Money& rcAmount1, const Money& rcAmount2);
Money operator-(const Money& rcAmount1, const Money& rcAmount2);