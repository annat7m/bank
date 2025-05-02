//***************************************************************************
// File name:   FlatInterest.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Interest.h"
#include "../include/Money.h"
#include <iostream>

#pragma once

class FlatInterest : public Interest {
public:
	FlatInterest ();
	FlatInterest (double rate);
	virtual ~FlatInterest () override;

	virtual Money generate (const Money& rcBalance) const override;
	virtual void displayConverted (std::ostream& rcOutStream,
		const Currency& rcCurrency) const override;
	virtual void display (std::ostream& rcOutStream) const override;
	virtual void read (std::istream& rcInStream) override;

private:
	double mInterest;
};