//***************************************************************************
// File name:   FlatInterest.cpp
// Author:      Anna Tymoshenko
// Date:        03/16/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/FlatInterest.h"
#include <iostream>
#include <iomanip>

//***************************************************************************
// Constructor: FlatInterest
//
// Description: Initializes Flat Interest object
//
// Parameters:  rate - wanted interest rate
//
// Returned:    None
//***************************************************************************

FlatInterest::FlatInterest (double rate) {
	mInterest = rate;
}

//***************************************************************************
// Destructor:  FlatInterest
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

FlatInterest::~FlatInterest () {}

//***************************************************************************
// Function:    generate
//
// Description: apply flat interest rate on balance
//
// Parameters:  none
//
// Returned:    balance with applied interest
//***************************************************************************

Money FlatInterest::generate (const Money& balance) const {
	if (balance < Money (0)) {
		return Money (0);
	}
	return balance + (balance * mInterest);
}

//***************************************************************************
// Function:    display
//
// Description: display flat interest rate to the stream
//
// Parameters:  rcOutStream - stream to write to
//
// Returned:    none
//***************************************************************************

void FlatInterest::display (std::ostream& rcOutStream) const {
	const char FLAT = 'F';
	rcOutStream << std::setprecision (2) << FLAT << " " << mInterest * 100 << "%";
}

//***************************************************************************
// Function:    read
//
// Description: read flat interest rate from the stream
//
// Parameters:  rcInStream - stream to read from
//
// Returned:    none
//***************************************************************************

void FlatInterest::read (std::istream& rcInStream) {
	rcInStream >> mInterest;
}