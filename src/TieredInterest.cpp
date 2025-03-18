//***************************************************************************
// File name:   TieredInterest.cpp
// Author:      Anna Tymoshenko
// Date:        03/16/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/TieredInterest.h"
#include "../include/Interest.h"
#include <iostream>
#include <algorithm>

//***************************************************************************
// Constructor: TieredInterest
//
// Description: Initializes Tiered Interest object
//
// Parameters:  numOfTieres - number of tieres of interests
//
// Returned:    None
//***************************************************************************

TieredInterest::TieredInterest (unsigned int numOfTieres) {
	mNumberOfTieres = numOfTieres;
}

//***************************************************************************
// Destructor:  TieredInterest
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TieredInterest::~TieredInterest () {}

//***************************************************************************
// Function:    generate
//
// Description: apply tiered interest rate on balance
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

Money TieredInterest::generate (Money& balance) const {
	if (balance < Money (0)) {
		return Money (0);
	}

	for (int i = mInterestRates.size () - 1; i >= 0; --i) {
		if (balance >= mInterestRates[i].first) {
			return balance * mInterestRates[i].second;
		}
	}

	return Money (0);
}

//***************************************************************************
// Function:    display
//
// Description: display tiered interest rate to the stream
//
// Parameters:  rcOutStream - stream to write to
//
// Returned:    none
//***************************************************************************

void TieredInterest::display (std::ostream& rcOutStream) const {
	rcOutStream << "T " << mNumberOfTieres;
	for (const auto& tier : mInterestRates) {
		rcOutStream << " $" << tier.first;
	}
	for (const auto& tier : mInterestRates) {
		rcOutStream << " " << tier.first << "%";
	}
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

void TieredInterest::read (std::istream& rcInStream) {
	rcInStream >> mNumberOfTieres;
	//mInterestRates.resize (mNumberOfTieres);
	for (unsigned int i = 0; i < mNumberOfTieres; ++i) {
		long long minBalance;
		double rate;
		rcInStream >> minBalance >> rate;
		mInterestRates[i] = std::make_pair (Money (minBalance), rate);
	}
	// Sort tiers in ascending order of minimum balance
	std::sort (mInterestRates.begin (), mInterestRates.end ());
}

//***************************************************************************
// Function:    addTier
//
// Description: add tier that consist of balance and rate to the vector of pairs
//
// Parameters:  rcInStream - stream to read from
//
// Returned:    none
//***************************************************************************

void TieredInterest::addTier (const Money& amount, double interest) {
	mInterestRates.push_back ({ amount, interest });
	std::sort (mInterestRates.begin (), mInterestRates.end ());
}