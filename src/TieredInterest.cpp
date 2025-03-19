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
#include <iomanip>

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
// Returned:    balance with applied interest
//***************************************************************************

Money TieredInterest::generate (const Money& balance) const {
	if (balance < Money (0)) {
		return Money (0);
	}

	for (int i = mInterestRates.size () - 1; i >= 0; --i) {
		if (balance >= mInterestRates[i].first) {
			return balance + (balance * mInterestRates[i].second);
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
	const char TIERED = 'T';
	rcOutStream << TIERED;

	rcOutStream << std::fixed << std::setprecision (2);

	for (const auto& tier : mInterestRates) {
		rcOutStream << " " << tier.first;
	}
	if (mInterestRates.size () > 0) {
		rcOutStream << ",";
	}
	for (const auto& tier : mInterestRates) {
		rcOutStream << " " << tier.second * 100 << "%";
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
	long long minBalance;
	double interestRate;

	std::vector<long long> minBalances;
	std::vector<double> interestRates;

	rcInStream >> mNumberOfTieres;
	mInterestRates.clear ();

	for (unsigned int i = 0; i < mNumberOfTieres; ++i) {
		rcInStream >> minBalance;
		minBalances.push_back (minBalance);
	}

	for (unsigned int i = 0; i < mNumberOfTieres; ++i) {
		rcInStream >> interestRate;
		interestRates.push_back (interestRate);
	}

	for (unsigned int i = 0; i < mNumberOfTieres; ++i) {
		mInterestRates.emplace_back (minBalances[i], interestRates[i]);
	}

	minBalances.clear ();
	interestRates.clear ();
}

//***************************************************************************
// Function:    addTier
//
// Description: add tier that consist of balance and rate to the vector of pairs
//
// Parameters:  amount		- min balance to have to apply interest rate
//							interest	- interest rate for that balance
//
// Returned:    none
//***************************************************************************

void TieredInterest::addTier (const Money& amount, double interest) {
	mInterestRates.push_back ({ amount, interest });
	std::sort (mInterestRates.begin (), mInterestRates.end ());
}