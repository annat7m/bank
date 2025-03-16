//***************************************************************************
// File name:   Mooney.cpp
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Money.h"
#include <iostream>
#include <fstream>

//***************************************************************************
// Constructor: Money
//
// Description: Constructs Money object out of passed in Money
//
// Parameters:  amount - Money object to set amount to
//
// Returned:    None
//***************************************************************************

Money::Money (const Money& amount) {
	mAmount = amount.mAmount;
}

//***************************************************************************
// Constructor: Money
//
// Description: Constructs Money object out of passed in Money
//
// Parameters:  amount - amount as a long long data type to set Money object to
//
// Returned:    None
//***************************************************************************

Money::Money (long long amount) {
	mAmount = amount;
}

//***************************************************************************
// Destructor:  Money
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

Money::~Money () {}

//***************************************************************************
// Function:    operator=
//
// Description: copy and swap Money object
//
// Parameters:  amount - amount to copy
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator= (Money amount) {

}

//***************************************************************************
// Function:    operator+=
//
// Description: add money to some existing Money object
//
// Parameters:  amount - amount to add
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator+= (const Money& amount) {

}

//***************************************************************************
// Function:    operator-=
//
// Description: subtract money from some existing Money object
//
// Parameters:  amount - amount to subtract
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator-= (const Money& amount) {

}

//***************************************************************************
// Function:    operator*=
//
// Description: multiply money to some existing Money object
//
// Parameters:  amount - amount to multiply
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator*= (const Money& amount) {

}

//***************************************************************************
// Function:    operator<
//
// Description: compare two Money objects
//
// Parameters:  amount - amount to compare to
//
// Returned:    true or false
//***************************************************************************

bool Money::operator< (const Money& amount) {

}

//***************************************************************************
// Function:    operator<
//
// Description: compare two Money objects
//
// Parameters:  amount - amount to compare to
//
// Returned:    true or false
//***************************************************************************

bool Money::operator>= (const Money& amount) {

}

//***************************************************************************
// Function:    display
//
// Description: display the Money object to the stream
//
// Parameters:  rcOutStream - user chosen stream
//
// Returned:    none
//***************************************************************************

void Money::display (std::ostream& rcOutStream) {

}

//***************************************************************************
// Function:    read
//
// Description: read the Money object from the stream
//
// Parameters:  rcInStream - user chosen stream
//
// Returned:    none
//***************************************************************************

void Money::read (std::istream& rcInStream) {

}

//***************************************************************************
// Function:    operator<<
//
// Description: 
//
// Parameters:  rcOutStream	- user chosen stream
//							amount			- amount to output
//
// Returned:    none
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOutStream,
	const Money& amount) {

}

//***************************************************************************
// Function:    operator<<
//
// Description: 
//
// Parameters:  rcInStream	- user chosen stream
//							amount			- amount to input
//
// Returned:    none
//***************************************************************************

std::istream& operator>> (std::istream& rcOutStream,
	const Money& amount) {

}