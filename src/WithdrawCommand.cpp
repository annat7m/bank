//***************************************************************************
// File name:   WithdrawCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/WithdrawCommand.h"
#include "../include/Bank.h"
#include "../include/CurrencyMismatchException.h"

#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: WithdrawCommand
//
// Description: Initializes WithdrawCommand with Bank pointer, account number, 
//							and amount
//
// Parameters:  cpBank        - pointer to the Bank object
//              accountNumber - account number to withdraw from
//              cAmount       - amount of money to withdraw
//
// Returned:    None
//***************************************************************************

WithdrawCommand::WithdrawCommand (std::shared_ptr<Bank> cpBank,
	unsigned int accountNumber, Money cAmount) : mpcBank (cpBank),
	mAccountNumber (accountNumber), mcAmount (cAmount) {
}

//***************************************************************************
// Destructor:  WithdrawCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

WithdrawCommand::~WithdrawCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Withdraws the specified amount of money from the given account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void WithdrawCommand::execute () {
	const std::string COMMAND = "W";
	try {
		mpcBank->withdraw (mAccountNumber, mcAmount);
	}
	catch (CurrencyMismatchException& e) {
		mpcBank->logCurrencyException (COMMAND, mAccountNumber, e.getFromCurrency (),
			e.getToCurrency ());
	}
}