//***************************************************************************
// File name:   IAccountReader.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <memory>

#pragma once

class IAccountReader {

public:
	IAccountReader ();
	virtual ~IAccountReader ();

	virtual std::shared_ptr<Account> readAccount (std::ostream& rcOutStream) = 0;

};