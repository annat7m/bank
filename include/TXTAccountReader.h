//***************************************************************************
// File name:   TXTAccountReader.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Bank.h"

#pragma once

class TXTAccountReader {

	public:
		TXTAccountReader ();
		virtual ~TXTAccountReader();

		virtual void readAccounts (Bank bank);

};