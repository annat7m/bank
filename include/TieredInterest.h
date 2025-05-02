//***************************************************************************
// File name:   TieredInterest.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include "../include/Interest.h"
#include "../include/Money.h"
#include <iostream>
#include <vector>

#pragma once

class TieredInterest : public Interest {
public:
	TieredInterest ();
	TieredInterest (unsigned int numOfTieres);
	virtual ~TieredInterest () override;

	virtual Money generate (const Money& rcBalance) const override;

	virtual void displayConverted (std::ostream& rcOutStream, 
		const Currency& rcCurrency) const override;

	virtual void display (std::ostream& rcOutStream) const override;
	virtual void read (std::istream& rcInStream) override;

	void addTier (const Money& rcAmount, double interest);

private:
	unsigned int mNumberOfTieres;
	std::vector<std::pair<Money, double>> mInterestRates;

};