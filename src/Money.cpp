//***************************************************************************
// File name:   Mooney.cpp
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Money.h"
#include "../include/CurrencyMismatchException.h"
#include "../include/CurrencyConversionTable.h"
#include <iostream>
#include <fstream>
#include <iomanip>

//***************************************************************************
// Constructor: Money
//
// Description: Initializes a Money object with the value of another Money object
//
// Parameters:  rcMoney - Money object to set amount to
//
// Returned:    None
//***************************************************************************

Money::Money (const Money& rcMoney) {
	mAmount = rcMoney.mAmount;
	mcCurrency = rcMoney.mcCurrency;
}

//***************************************************************************
// Constructor: Money
//
// Description: Initializes a Money object with a long long integer value
//
// Parameters:  amount		- amount as a long long data type to set Money object to
//							cCurrency	- currency object to set money's currency
//
// Returned:    None
//***************************************************************************

Money::Money (long long amount, Currency cCurrency) {
	mAmount = amount;
	mcCurrency = cCurrency;
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
// Parameters:  other - amount to copy
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator= (Money other) {
	std::swap (mAmount, other.mAmount);
	return *this;
}

//***************************************************************************
// Function:    operator+=
//
// Description: add money to some existing Money object
//
// Parameters:  rcOther - amount to add
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator+= (const Money& rcOther) {
	if (mcCurrency != rcOther.mcCurrency) {
		Money converted = rcOther.convertTo (mcCurrency);
		mAmount += converted.mAmount;
	}
	else {
		mAmount += rcOther.mAmount;
	}
	return *this;
}

//***************************************************************************
// Function:    operator-=
//
// Description: subtract money from some existing Money object
//
// Parameters:  rcOther - amount to subtract
//
// Returned:    updated Money object
//***************************************************************************

Money& Money::operator-= (const Money& rcOther) {
	if (mcCurrency != rcOther.mcCurrency) {
		Money converted = rcOther.convertTo (mcCurrency);
		mAmount -= converted.mAmount;
	}
	else {
		mAmount -= rcOther.mAmount;
	}
	return *this;
}

//***************************************************************************
// Function:    operator*
//
// Description: multiply money by a double
//
// Parameters:  multiplier - amount to multiply by
//
// Returned:    updated Money object
//***************************************************************************

Money Money::operator* (double multiplier) const {
	return Money (static_cast<long long>(mAmount * multiplier), mcCurrency);
}

//***************************************************************************
// Function:    operator==
//
// Description: compare two Money objects
//
// Parameters:  rcOther - amount to compare to
//
// Returned:    true or false
//***************************************************************************

bool Money::operator== (const Money& rcOther) const {
	if (mcCurrency != rcOther.mcCurrency) {
		Money converted = rcOther.convertTo (mcCurrency);
		return mAmount == converted.mAmount;
	}
	else return mAmount == rcOther.mAmount;
}

//***************************************************************************
// Function:    operator<
//
// Description: compare two Money objects
//
// Parameters:  rcOther - amount to compare to
//
// Returned:    true or false
//***************************************************************************

bool Money::operator< (const Money& rcOther) const {
	if (mcCurrency != rcOther.mcCurrency) {
		Money converted = rcOther.convertTo (mcCurrency);
		return mAmount < converted.mAmount;
	}
	else return mAmount < rcOther.mAmount;
}

//***************************************************************************
// Function:    operator<
//
// Description: compare two Money objects
//
// Parameters:  rcOther - amount to compare to
//
// Returned:    true or false
//***************************************************************************

bool Money::operator>= (const Money& rcOther) const {
	if (mcCurrency != rcOther.mcCurrency) {
		Money converted = rcOther.convertTo (mcCurrency);
		return mAmount >= converted.mAmount;
	}
	else return mAmount >= rcOther.mAmount;
}

//***************************************************************************
// Function:    operator()
//
// Description: function call operator
//
// Parameters:  none
//
// Returned:    amount (running total logic)
//***************************************************************************

long long Money::operator() () const {
	return mAmount;
}

//***************************************************************************
// Function:    getCurrency
//
// Description: currency getter
//
// Parameters:  none
//
// Returned:    currency of the money object
//***************************************************************************

Currency Money::getCurrency () const {
	return mcCurrency;
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

void Money::display (std::ostream& rcOutStream) const {
	rcOutStream << std::fixed << std::setprecision (2) << mcCurrency
		<< static_cast<double>(mAmount * 0.01);
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
	std::string currencyStr;
	long long amount;
	rcInStream >> currencyStr >> amount;
	mcCurrency = Currency (currencyStr);
	mAmount = amount;
}

//***************************************************************************
// Function:    operator<<
//
// Description: extraction operator
//
// Parameters:  rcOutStream	- user chosen stream
//							rcAmount		- amount to output
//
// Returned:    none
//***************************************************************************

std::ostream& operator<< (std::ostream& rcOutStream, const Money& rcAmount) {
	rcAmount.display (rcOutStream);
	return rcOutStream;
}

//***************************************************************************
// Function:    operator>>
//
// Description: insertion operator
//
// Parameters:  rcInStream	- user chosen stream
//							rcAmount		- amount to input
//
// Returned:    none
//***************************************************************************

std::istream& operator>> (std::istream& rcInStream, Money& rcAmount) {
	rcAmount.read (rcInStream);
	return rcInStream;
}

//***************************************************************************
// Function:    convertTo
//
// Description: convert the currency to another currency using provided table
//							sigleton with rates
//
// Parameters:  rcNewCurrency - currency we are converting to
//
// Returned:    money object with updates currency and value
//***************************************************************************

Money Money::convertTo (const Currency& rcNewCurrency) const {
	if (mcCurrency == rcNewCurrency) {
		return *this;
	}
	CurrencyConversionTable& table = CurrencyConversionTable::getInstance ();

	if (!table.bConversionExists (mcCurrency, rcNewCurrency)) {
		throw CurrencyMismatchException (mcCurrency, rcNewCurrency);
	}

	double rate = table.getRate (mcCurrency, rcNewCurrency);
	long long newValue = static_cast<long long> (mAmount * rate * 100);

	return Money (newValue*0.01, rcNewCurrency);
}

//***************************************************************************
// Function:    operator+
//
// Description: non-friend, non-member operator, performs addition of two
//							Money objects
//
// Parameters:  rcAmount1	- first Money operand
//							rcAmount2	- second Money operand
//
// Returned:    updated Money object
//***************************************************************************

Money operator+ (const Money& rcAmount1, const Money& rcAmount2) {
	if (rcAmount1.getCurrency () != rcAmount2.getCurrency ()) {
		Money cConvertedAmount2 = rcAmount2.convertTo (rcAmount1.getCurrency ());
		return Money (rcAmount1 () + cConvertedAmount2 (), rcAmount1.getCurrency ());
	}
	return Money (rcAmount1 () + rcAmount2 (), rcAmount1.getCurrency ());
}

//***************************************************************************
// Function:    operator-
//
// Description: non-friend, non-member operator, performs subtraction of two
//							Money objects
//
// Parameters:  rcAmount1	- first Money operand
//							rcAmount2	- second Money operand
//
// Returned:    updated Money object
//***************************************************************************

Money operator- (const Money& rcAmount1, const Money& rcAmount2) {
	if (rcAmount1.getCurrency () != rcAmount2.getCurrency ()) {
		Money cConvertedAmount2 = rcAmount2.convertTo (rcAmount1.getCurrency ());
		return Money (rcAmount1 () - cConvertedAmount2 (), rcAmount1.getCurrency ());
	}
	return Money (rcAmount1 () - rcAmount2 (), rcAmount1.getCurrency ());
}