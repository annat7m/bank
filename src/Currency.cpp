//***************************************************************************
// File name:   Currency.cpp
// Author:      Anna Tymoshenko
// Date:        04/05/2025
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Currency.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//***************************************************************************
// Constructor: Currency
//
// Description: Constructor that takes an enum to initialize Currency object
//
// Parameters:  eType - currency type as a scoped enum object
//
// Returned:    None
//***************************************************************************

Currency::Currency (CurrencyType eType) {
	meCurrencyType = eType;
}

//***************************************************************************
// Constructor: Currency
//
// Description: Constructor that takes a string to initialize Currency object
//
// Parameters:  type - currency type of type string
//
// Returned:    None
//***************************************************************************

Currency::Currency (std::string type) {
	if (type == "USD") {
		meCurrencyType = CurrencyType::USD;
	}
	else if (type == "GBP") {
		meCurrencyType = CurrencyType::GBP;
	}
	else if (type == "EUR") {
		meCurrencyType = CurrencyType::EUR;
	}
	else if (type == "YEN") {
		meCurrencyType = CurrencyType::YEN;
	}
	else {
		throw std::invalid_argument ("Invalid currency type string: " + type);
	}
}

//***************************************************************************
// Destructor:  Currency
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

Currency::~Currency () {}

//***************************************************************************
// Function:    operator==
//
// Description: compare two Currency objects
//
// Parameters:  rcOther - Currency object to compare to
//
// Returned:    true or false
//***************************************************************************

bool Currency::operator== (const Currency& rcOther) const {
	return meCurrencyType == rcOther.meCurrencyType;
}

//***************************************************************************
// Function:    operator!=
//
// Description: compare two Currency objects
//
// Parameters:  rcOther - Currency object to compare to
//
// Returned:    true or false
//***************************************************************************

bool Currency::operator!= (const Currency& rcOther) const {
	return meCurrencyType != rcOther.meCurrencyType;
}

//***************************************************************************
// Function:    display
//
// Description: display the Currency object to the stream
//
// Parameters:  rcOutStream - user chosen stream
//
// Returned:    none
//***************************************************************************

void Currency::display (std::ostream& rcOutStream) const {
	switch (meCurrencyType) {
	case CurrencyType::USD:
		rcOutStream << "USD";
		break;
	case CurrencyType::GBP:
		rcOutStream << "GBP";
		break;
	case CurrencyType::EUR:
		rcOutStream << "EUR";
		break;
	case CurrencyType::YEN:
		rcOutStream << "YEN";
		break;
	}
}

//***************************************************************************
// Function:    read
//
// Description: read the Currency object from the stream
//
// Parameters:  rcInStream - user chosen stream
//
// Returned:    none
//***************************************************************************

void Currency::read (std::istream& rcInStream) {
	std::string type;
	rcInStream >> type;

	*this = Currency (type);
}

//***************************************************************************
// Function:    operator<<
//
// Description: extraction operator
//
// Parameters:  rcOutStream	- user chosen stream
//							rcCurrency	- currency to output
//
// Returned:    none
//***************************************************************************

std::ostream& operator<<(std::ostream& rcOutStream, const Currency& rcCurrency) {
	rcCurrency.display (rcOutStream);
	return rcOutStream;
}

//***************************************************************************
// Function:    operator>>
//
// Description: insertion operator
//
// Parameters:  rcInStream	- user chosen stream
//							rcCurrency	- currency to input
//
// Returned:    none
//***************************************************************************

std::istream& operator>>(std::istream& rcInStream, Currency& rcCurrency) {
	rcCurrency.read (rcInStream);
	return rcInStream;
}