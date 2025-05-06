//***************************************************************************
// File name:   PrintCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/PrintCommand.h"
#include "../include/Bank.h"
#include "../include/CurrencyMismatchException.h"

#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: PrintCommand
//
// Description: Initializes PrintCommand with Bank pointer and a stream
//
// Parameters:  cpBank    	- pointer to the Bank object
//              rcOutStream	- reference to the output stream
//
// Returned:    None
//***************************************************************************

PrintCommand::PrintCommand (std::shared_ptr<Bank> cpBank,
	std::ostream& rcOutStream) : mpcBank (cpBank), mrcOutStream (rcOutStream) {
}

//***************************************************************************
// Destructor:  PrintCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

PrintCommand::~PrintCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Prints all accounts to the provided output stream
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void PrintCommand::execute () {
	mrcOutStream << "-------------" << std::endl;
	mpcBank->display (mrcOutStream);
	mrcOutStream << "-------------" << std::endl;
}