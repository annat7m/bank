//***************************************************************************
// File name:   Money.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>

#pragma once

class Money {

public:
	Money (const Money& amount);
	Money (long long amount);
	virtual ~Money ();

	Money& operator= (Money amount);
	Money& operator+= (const Money& amount);
	Money& operator-= (const Money& amount);
	Money& operator*= (const Money& amount);
	Money operator* (double multiplier) const;

	bool operator==(const Money& other) const;
	bool operator< (const Money& amount) const;
	bool operator>= (const Money& amount) const;

	long long operator () () const;

	void display (std::ostream& rcOutStream) const;
	void read (std::istream& rcInStream);

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Money& amount);
	friend std::istream& operator>> (std::istream& rcInStream,
		Money& amount);

private:
	long long mAmount;

};

// non-member, non-friend operators
Money operator+(Money amount1, const Money& amount2);
Money operator-(Money amount1, const Money& amount2);