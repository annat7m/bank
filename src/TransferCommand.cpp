//***************************************************************************
// File name:   TransferCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/TransferCommand.h"
#include "../include/Bank.h"
#include "../include/CurrencyMismatchException.h"

#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: TransferCommand
//
// Description: Initializes TransferCommand with Bank pointer, 2 account numbers, 
//							and amount
//
// Parameters:  cpBank        		- pointer to the Bank object
//              fromAccountNumber - account number to withdraw from
//							toAccountNumber		- account number to deposit to
//              cAmount       		- amount of money to transfer
//
// Returned:    None
//***************************************************************************

TransferCommand::TransferCommand (std::shared_ptr<Bank> cpBank,
	unsigned int fromAccountNumber, unsigned int toAccountNumber, 
	Money cAmount) : mpcBank (cpBank), mFromAccountNumber (fromAccountNumber), 
	mToAccountNumber(toAccountNumber), mcAmount (cAmount) {
}

//***************************************************************************
// Destructor:  TransferCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

TransferCommand::~TransferCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Transfers the specified amount of money from one account to
//							another by withdrawing from one and transfering to a different
//							one
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void TransferCommand::execute () {
	mpcBank->withdraw (mFromAccountNumber, mcAmount);
	mpcBank->deposit (mToAccountNumber, mcAmount);
}