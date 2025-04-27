//***************************************************************************
// File name:   MonthlyCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/MonthlyCommand.h"
#include "../include/Bank.h"
#include "../include/CurrencyMismatchException.h"

#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: MonthlyCommand
//
// Description: Initializes MonthlyCommand with Bank pointer
//
// Parameters:  cpBank    	- pointer to the Bank object
//
// Returned:    None
//***************************************************************************

MonthlyCommand::MonthlyCommand (std::shared_ptr<Bank> cpBank)
	: mpcBank (cpBank) {
}

//***************************************************************************
// Destructor:  MonthlyCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

MonthlyCommand::~MonthlyCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Applies monthly updates on all the bank accounts
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void MonthlyCommand::execute () {
	mpcBank->applyMonthlyUpdates ();
}