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
	YEN
};

class Currency {

public:
	Currency (CurrencyType eType);
	Currency (std::string type);
	virtual ~Currency ();

	bool operator== (const Currency& rcOtherCurrency) const;
	bool operator!= (const Currency& rcOtherCurrency) const;

	void display (std::ostream& rcOutStream) const;
	void read (std::istream& rcInStream);

	friend std::ostream& operator<<(std::ostream& rcOutStream, 
		const Currency& rcCurrency);
	friend std::istream& operator>>(std::istream& rcInStream, 
		Currency& rcCurrency);

private:
	CurrencyType mCurrencyType;

};