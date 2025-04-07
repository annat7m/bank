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
	mCurrency1 = cCurrency1;
	mCurrency2 = cCurrency2;
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
	mCurrency1 = rcOther.mCurrency1;
	mCurrency2 = rcOther.mCurrency2;
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
	std::swap (mCurrency1, cOther.mCurrency1);
	std::swap (mCurrency2, cOther.mCurrency2);
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