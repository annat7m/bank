//***************************************************************************
// File name:   ITransactionReader.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"

#pragma once

class ITransactionReader {

	public:
		ITransactionReader ();
		virtual ~ITransactionReader();

		virtual void readTransactions (Bank bank) = 0;

};