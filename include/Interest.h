//***************************************************************************
// File name:   Interest.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Money.h"
#include <iostream>
#include <memory>

#pragma once

class Interest {
public:
	Interest ();
	virtual ~Interest ();

	virtual Money generate (const Money& rcBalance) const = 0;
	virtual void displayConverted (std::ostream& rcOutStream, 
		const Currency& rcCurrency) const = 0;
	virtual void display (std::ostream& rcOutStream) const = 0;
	virtual void read (std::istream& rcInStream) = 0;

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Interest& rcInterest);
	friend std::istream& operator>> (std::istream& rcInStream,
		std::shared_ptr<Interest>& rpcInterest);

};