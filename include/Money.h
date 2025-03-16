//***************************************************************************
// File name:   Money.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

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

	bool operator< (const Money& amount);
	bool operator>= (const Money& amount);

	void display (std::ostream& rcOutStream);
	void read (std::istream& rcInStream);

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Money& amount);
	friend std::istream& operator>> (std::istream& rcOutStream,
		const Money& amount);

private:
	long long mAmount;

};