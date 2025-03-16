//***************************************************************************
// File name:   TXTTransactionReader.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"
#include "../include/ITransactionReader.h"
#include <iostream>
#include <fstream>

#pragma once

class TXTTransactionReader : public ITransactionReader {

public:
	TXTTransactionReader (const std::string& fileName);
	virtual ~TXTTransactionReader ();

	virtual void readTransactions (std::ostream& rcOutStream, Bank& bank) override;

private:
	std::ifstream mcCommandsFile;

};