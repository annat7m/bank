//***************************************************************************
// File name:   CurrencyConversionTable.h
// Author:      Anna Tymoshenko
// Date:        04/29/2025
// Class:       CS485
// Assignment:  Assignment 6 - Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************
#include "../include/Currency.h"

#include <iostream>
#include <string>
#include <map>

#pragma once

class CurrencyConversionTable {

public:
	static CurrencyConversionTable& getInstance ();
	double getRate (const Currency& rcFromCurrency,
		const Currency& rcToCurrency) const;

	void readConversions (std::string& rcFileName);
	bool bConversionExists (const Currency& rcFromCurrency,
		const Currency& rcToCurrency);

private:
	CurrencyConversionTable ();
	~CurrencyConversionTable ();
	CurrencyConversionTable (const CurrencyConversionTable& rcTable) = delete;
	CurrencyConversionTable& operator= (const CurrencyConversionTable& rcTable)
		= delete;
	std::map<std::pair<Currency, Currency>, double> mcRates;

};