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
// Description: Default constructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

FlatInterest::FlatInterest () {}

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
// Parameters:  rcBalance - balance used to generate interest on
//
// Returned:    balance with applied interest
//***************************************************************************

Money FlatInterest::generate (const Money& rcBalance) const {
	if (rcBalance < Money (0, rcBalance.getCurrency ())) {
		return rcBalance;
	}
	return rcBalance + (rcBalance * mInterest);
}

//***************************************************************************
// Function:    displayConverted
//
// Description: display converted to a given currency interest to the stream 
//
// Parameters:  rcOutStream - reference to the stream to output to
//							rcCurrency	- reference to the currency account needs to be
//														converted to
//
// Returned:    none
//***************************************************************************
void FlatInterest::displayConverted (std::ostream& rcOutStream,
	const Currency& rcCurrency) const {
	display (rcOutStream);
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