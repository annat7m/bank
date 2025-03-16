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
	FlatInterest (double inteerst);
	virtual ~FlatInterest ();

	virtual Money generate (const Money& amount) override;
	virtual void display (std::ostream& rcOutStream) const override;
	virtual void read (std::istream& rcInStream) const override;

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Interest& interest);
	friend std::istream& operator>> (std::istream& rcOutStream,
		const Interest& interest);

private:
	double mInterest;
};