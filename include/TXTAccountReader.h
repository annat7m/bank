//***************************************************************************
// File name:   TXTAccountReader.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"
#include "../include/IAccountReader.h"
#include <fstream>

#pragma once

class TXTAccountReader : public IAccountReader {

public:
	TXTAccountReader (const std::string& fileName);
	virtual ~TXTAccountReader ();

	virtual void readAccounts (Bank& bank) override;

private:
	std::ifstream mcAccountsFile;

};