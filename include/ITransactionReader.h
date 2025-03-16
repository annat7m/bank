//***************************************************************************
// File name:   ITransactionReader.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"
#include <iostream>

#pragma once

class ITransactionReader {

public:
	ITransactionReader ();
	virtual ~ITransactionReader ();

	virtual void readTransactions (std::ostream& rcOutStream, Bank& bank) = 0;

};