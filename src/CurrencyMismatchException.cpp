//***************************************************************************
// File name:   Currency.cpp
// Author:      Anna Tymoshenko
// Date:        04/05/2025
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CurrencyMismatchException.h"

//***************************************************************************
// Constructor: CurrencyMismatchException
//
// Description: Constructor that takes an enum to initialize Currency object
//
// Parameters:  currency1	- the first currency involved
//							currency2	- the second (mismatched) currency involved
//
// Returned:    None
//***************************************************************************

CurrencyMismatchException::CurrencyMismatchException (Currency cCurrency1,
	Currency cCurrency2) {
	mcCurrency1 = cCurrency1;
	mcCurrency2 = cCurrency2;
	mcMessage = "Currency mismatch";
}

//***************************************************************************
// Constructor: CurrencyMismatchException
//
// Description: Copy constructor for CurrencyMismatchException
//
// Parameters:  rcOther	- reference to the exception being copied
//
// Returned:    None
//***************************************************************************

CurrencyMismatchException::CurrencyMismatchException (
	const CurrencyMismatchException& rcOther) {
	mcCurrency1 = rcOther.mcCurrency1;
	mcCurrency2 = rcOther.mcCurrency2;
	mcMessage = rcOther.mcMessage;
}

//***************************************************************************
// Destructor:  CurrencyMismatchException
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

CurrencyMismatchException::~CurrencyMismatchException () {}

//***************************************************************************
// Function:    getFromCurrency
//
// Description: Getter for the first currency
//
// Parameters:  None
//
// Returned:    currency that failed to convert from
//***************************************************************************
const Currency& CurrencyMismatchException::getFromCurrency () const {
	return mcCurrency1;
}

//***************************************************************************
// Function:    getToCurrency
//
// Description: Getter for the second currency
//
// Parameters:  None
//
// Returned:    currency that failed to convert to
//***************************************************************************
const Currency& CurrencyMismatchException::getToCurrency () const {
	return mcCurrency2;
}

//***************************************************************************
// Function:    operator=
//
// Description: Assignment operator for CurrencyMismatchException. Uses
//              copy and swap idiom for exception-safe assignment
//
// Parameters:  cOther - the exception object to assign from
//
// Returned:    A reference to the updated exception object
//***************************************************************************

CurrencyMismatchException& CurrencyMismatchException::operator=(
	CurrencyMismatchException cOther) {
	std::swap (mcCurrency1, cOther.mcCurrency1);
	std::swap (mcCurrency2, cOther.mcCurrency2);
	std::swap (mcMessage, cOther.mcMessage);
	return *this;
}

//***************************************************************************
// Function:    what
//
// Description: Provides a brief description of the exception. Overrides
//              std::exception::what
//
// Parameters:  none
//
// Returned:    description of an error
//***************************************************************************

const char* CurrencyMismatchException::what () const noexcept {
	return mcMessage.c_str ();
}