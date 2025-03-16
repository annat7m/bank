//***************************************************************************
// File name:   TXTAccountReader.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/IAccountReader.h"
#include <iostream>
#include <fstream>

#pragma once

class TXTAccountReader : public IAccountReader {

public:
	TXTAccountReader (const std::string& fileName);
	virtual ~TXTAccountReader ();

	virtual std::shared_ptr<Account> readAccount (std::ostream&
		rcOutStream) override;

private:
	std::ifstream mcAccountsFile;

};