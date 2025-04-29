//***************************************************************************
// File name:   BackupCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/28/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/BackupCommand.h"
#include "../include/Bank.h"

#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: BackupCommand
//
// Description: Initializes BackupCommand with Bank pointer and two streams
//
// Parameters:  cpBank    		- pointer to the Bank object
//              rcOutStream_S	- reference to the output stream for savings
//															accounts
//							rcOutStream_C	- reference to the output stream for checking
//															accounts
//
// Returned:    None
//***************************************************************************

BackupCommand::BackupCommand (std::shared_ptr<Bank> cpBank, 
	std::ostream& rcOutStream_S, std::ostream& rcOutStream_C) 
	: mpcBank (cpBank), mrcOutStream_S (rcOutStream_S), 
	mrcOutStream_C (rcOutStream_C) {}

//***************************************************************************
// Destructor:  BackupCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

BackupCommand::~BackupCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Prints all savings accounts to the provided output stream
//							and all cheecking accounts to a different output stream
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void BackupCommand::execute () {
	mpcBank->backupAccounts(mrcOutStream_S, mrcOutStream_C);
}