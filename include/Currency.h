//***************************************************************************
// File name:   Currency.h
// Author:      Anna Tymoshenko
// Date:        04/05/2025
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <string>

#pragma once

enum class CurrencyType : char {
	USD,
	GBP,
	EUR,
	YEN,
	CHF
};

class Currency {

public:
	Currency ();
	Currency (CurrencyType eType);
	Currency (std::string type);
	~Currency ();

	bool operator== (const Currency& rcOther) const;
	bool operator!= (const Currency& rcOther) const;

	bool operator< (const Currency& rcRHS) const;

	void display (std::ostream& rcOutStream) const;
	void read (std::istream& rcInStream);

	friend std::ostream& operator<<(std::ostream& rcOutStream,
		const Currency& rcCurrency);
	friend std::istream& operator>>(std::istream& rcInStream,
		Currency& rcCurrency);

private:
	CurrencyType meCurrencyType;

};