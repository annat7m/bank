//***************************************************************************
// File name:   BackupCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/28/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/BackupCommand.h"
#include "../include/BackupVisitor.h"
#include "../include/Bank.h"

#include <iostream>
#include <memory>
#include <fstream>

//***************************************************************************
// Constructor: BackupCommand
//
// Description: Initializes BackupCommand with Bank pointer and two streams
//
// Parameters:  cpBank    		- pointer to the Bank object
//							rcFileName_C	- file to store all checking accounts
//							rcFileName_S	- file to store all savings accounts
//
// Returned:    None
//***************************************************************************

BackupCommand::BackupCommand (std::shared_ptr<Bank> cpBank,
	const std::string& rcFileName_C, const std::string& rcFileName_S)
	: mpcBank (cpBank), mcFileName_C (rcFileName_C),
	mcFileName_S (rcFileName_S) {
}

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
	std::ofstream cOut_C (mcFileName_C);
	std::ofstream cOut_S (mcFileName_S);

	if (!cOut_C.is_open () || !cOut_S.is_open ()) {
		throw std::system_error (errno, std::system_category (),
			"Error: Could not open backup files.");
	}

	mpcBank->backupAccounts (cOut_C, cOut_S);

	cOut_C.close ();
	cOut_S.close ();
}
