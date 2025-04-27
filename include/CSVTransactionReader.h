//***************************************************************************
// File name:   CSVTransactionReader.h
// Author:      Anna Tymoshenko
// Date:        04/05/2025
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "../include/ITransactionReader.h"

#pragma once

class CSVTransactionReader : public ITransactionReader {
public:
	CSVTransactionReader (const std::string& rcFileName);
	~CSVTransactionReader ();

	virtual std::shared_ptr<ICommand> readTransactions (std::ostream& rcOutStream, 
		Bank& rcBank) override;

private:
	std::ifstream mcCommandsFile;

};