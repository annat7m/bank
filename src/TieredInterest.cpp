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
// Description: Default constructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TieredInterest::TieredInterest () {}

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
// Parameters:  rcBalance - to apply ninterest on this balance
//
// Returned:    balance with applied interest
//***************************************************************************

Money TieredInterest::generate (const Money& rcBalance) const {
	Money result = rcBalance;

	if (rcBalance >= Money (0, rcBalance.getCurrency())) {
		for (int i = mInterestRates.size () - 1; i >= 0; --i) {
			if (rcBalance >= mInterestRates[i].first) {
				result = rcBalance + (rcBalance * mInterestRates[i].second);
				break;
			}
		}
	}

	return result;
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
	std::string currencyString;

	std::vector<Money> minBalances;
	double interestRate;

	rcInStream >> mNumberOfTieres;
	mInterestRates.clear();

	for (unsigned int i = 0; i < mNumberOfTieres; ++i) {
		long long balance;
		rcInStream >> currencyString >> balance;
		minBalances.emplace_back(balance, Currency(currencyString));
	}

	for (unsigned int i = 0; i < mNumberOfTieres; ++i) {
		rcInStream >> interestRate;
		addTier(minBalances[i], interestRate);
	}
}

//***************************************************************************
// Function:    addTier
//
// Description: add tier that consist of balance and rate to the vector of pairs
//
// Parameters:  rcAmount		- min balance to have to apply interest rate
//							interest	- interest rate for that balance
//
// Returned:    none
//***************************************************************************

void TieredInterest::addTier (const Money& rcAmount, double interest) {
	mInterestRates.push_back ({ rcAmount, interest });
}