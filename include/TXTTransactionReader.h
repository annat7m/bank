//***************************************************************************
// File name:   TXTTransactionReader.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"
#include "../include/ITransactionReader.h"
#include <fstream>

#pragma once

class TXTTransactionReader : public ITransactionReader {

public:
	TXTTransactionReader (const std::string& fileName);
	virtual ~TXTTransactionReader ();

	virtual void readTransactions (Bank& bank) override;

private:
	std::ifstream mcCommandsFile;

};