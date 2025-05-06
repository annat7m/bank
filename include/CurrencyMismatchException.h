//***************************************************************************
// File name:   CurrencyMismatchException.h
// Author:      Anna Tymoshenko
// Date:        04/05/2025
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <string>
#include "../include/Currency.h"

#pragma once

class CurrencyMismatchException : public std::exception {
public:
	CurrencyMismatchException (Currency cCurrency1, Currency cCurrency2);
	CurrencyMismatchException (const CurrencyMismatchException& rcOther);
	~CurrencyMismatchException ();

	const Currency& getFromCurrency () const;
	const Currency& getToCurrency () const;

	CurrencyMismatchException& operator= (CurrencyMismatchException cOther);

	virtual const char* what () const noexcept override;

private:
	Currency mcCurrency1;
	Currency mcCurrency2;
	std::string mcMessage;

};