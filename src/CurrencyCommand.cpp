//***************************************************************************
// File name:   CurrencyCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/28/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CurrencyCommand.h"
#include "../include/Bank.h"

#include <iostream>
#include <memory>
#include <fstream>

//***************************************************************************
// Constructor: CurrencyCommand
//
// Description: Initializes CurrencyCommand with Bank pointer and a Currency
//
// Parameters:  cpBank		- pointer to the Bank object
//							cCurrency	-
//
// Returned:    None
//***************************************************************************

CurrencyCommand::CurrencyCommand (std::shared_ptr<Bank> cpBank,
	std::ostream& rcOutStream, Currency cCurrency) : mpcBank (cpBank),
	mrcOutStream (rcOutStream), mcCurrency (cCurrency) {
}

//***************************************************************************
// Destructor:  CurrencyCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

CurrencyCommand::~CurrencyCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Prints all accounts converted to a particular currency
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void CurrencyCommand::execute () {
	mrcOutStream << "-------------" << std::endl;
	mpcBank->switchToCurrency (mrcOutStream, mcCurrency);
	mrcOutStream << "-------------" << std::endl;
}
