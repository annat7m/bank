//***************************************************************************
// File name:   CurrencyConversionTable.cpp
// Author:      Anna Tymoshenko
// Date:        04/29/2025
// Class:       CS485
// Assignment:  Assignment 6 - Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************
#include "../include/CurrencyConversionTable.h"
#include "../include/CurrencyMismatchException.h"
#include <fstream>

//***************************************************************************
// Constructor: CurrencyConversionTable
//
// Description: Initialize Singleton
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CurrencyConversionTable::CurrencyConversionTable () {}

//***************************************************************************
// Destructor:  CurrencyConversionTable
//
// Description: Default Destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CurrencyConversionTable::~CurrencyConversionTable () {}

//***************************************************************************
// Function:    getInstance
//
// Description: static method to retreive a reference to a 
//							CurrencyConversionTable
//
// Parameters:  None
//
// Returned:    reference to a static CurrencyConversionTable
//***************************************************************************
CurrencyConversionTable& CurrencyConversionTable::getInstance () {
	static CurrencyConversionTable cTheCurrencyConversionTable;
	return cTheCurrencyConversionTable;
}

//***************************************************************************
// Function:    getRate
//
// Description: Returns the rate between two currencies from the map
//
// Parameters:  rcFromCurrency	- currency object that appears first
//							rcToCurrency		- currency object that appears second
//
// Returned:    rate between two currencies
//***************************************************************************
double CurrencyConversionTable::getRate (const Currency& rcFromCurrency,
	const Currency& rcToCurrency) const {

	auto it = mcRates.find ({ rcFromCurrency, rcToCurrency });
	if (it != mcRates.end ()) {
		return it->second;
	}
	throw CurrencyMismatchException (rcFromCurrency, rcToCurrency);
}

//***************************************************************************
// Function:    readConversions
//
// Description: read conversion from the provided file and fill the map
//
// Parameters:  rcFileName - file name to read from 
//
// Returned:    None
//***************************************************************************
void CurrencyConversionTable::readConversions (std::string& rcFileName) {
	std::ifstream inFile (rcFileName);
	if (!inFile.is_open ()) {
		throw std::runtime_error ("Failed to open currency conversion file");
	}

	std::string fromCurrencyString, toCurrencyString;
	double rate;

	while (inFile >> fromCurrencyString >> toCurrencyString >> rate) {
		Currency fromCurrency (fromCurrencyString), toCurrency (toCurrencyString);
		mcRates[{fromCurrency, toCurrency}] = rate;
		mcRates[{toCurrency, fromCurrency}] = 1 / rate;
	}
}

//***************************************************************************
// Function:    bConversionExists
//
// Description: Checks if conversion exists in the map
//
// Parameters:  rcFromCurrency	- currency object that appears first
//							rcToCurrency		- currency object that appears second
//
// Returned:    true if conversion exists, false otherwise
//***************************************************************************
bool CurrencyConversionTable::bConversionExists (const Currency& rcFromCurrency,
	const Currency& rcToCurrency) {

	return mcRates.find ({ rcFromCurrency, rcToCurrency }) != mcRates.end ();
}