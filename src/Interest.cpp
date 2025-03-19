//***************************************************************************
// File name:   Interest.cpp
// Author:      Anna Tymoshenko
// Date:        03/16/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Interest.h"
#include "../include/FlatInterest.h"
#include "../include/TieredInterest.h"
#include <memory>

//***************************************************************************
// Constructor: Interest
//
// Description: Initializes Interest object
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

Interest::Interest () {}

//***************************************************************************
// Destructor:  Interest
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

Interest::~Interest () {}

//***************************************************************************
// Function:    operator<<
//
// Description: display interest rate to the stream
//
// Parameters:  rcOutStream	- stream to write to
//							interest		- ineterest rate to display
//
// Returned:    none
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOutStream, const Interest& interest) {
	interest.display (rcOutStream);
	return rcOutStream;
}

//***************************************************************************
// Function:    operator>>
//
// Description: read flat interest rate from the stream
//
// Parameters:  rcInStream - stream to read from
//							interest		- ineterest rate to display
//
// Returned:    none
//***************************************************************************

std::istream& operator>>(std::istream& rcInStream, std::shared_ptr<Interest>& interest) {
	interest->read (rcInStream);

	return rcInStream;
}