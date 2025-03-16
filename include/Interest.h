//***************************************************************************
// File name:   Interest.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>

#pragma once

class Interest {
public:
	Interest ();
	virtual ~Interest ();

	virtual Money generate (const Money& amount) = 0;
	virtual void display (std::ostream& rcOutStream) const;
	virtual void read (std::istream& rcInStream) const;

	friend std::ostream& operator<< (std::ostream& rcOutStream,
		const Interest& interest);
	friend std::istream& operator>> (std::istream& rcOutStream,
		const Interest& interest);

private:
	
};