//***************************************************************************
// File name:   DepositCommand.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/DepositCommand.h"
#include "../include/Bank.h"
#include "../include/CurrencyMismatchException.h"

#include <iostream>
#include <memory>

//***************************************************************************
// Constructor: DepositCommand
//
// Description: Initializes DepositCommand with Bank pointer, account number, 
//							and amount
//
// Parameters:  cpBank        - pointer to the Bank object
//              accountNumber - account number to deposit to
//              cAmount       - amount of money to deposit
//
// Returned:    None
//***************************************************************************

DepositCommand::DepositCommand (std::shared_ptr<Bank> cpBank,
	unsigned int accountNumber, Money cAmount) : mpcBank (cpBank),
	mAccountNumber (accountNumber), mcAmount (cAmount) {
}

//***************************************************************************
// Destructor:  DepositCommand
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

DepositCommand::~DepositCommand () {}

//***************************************************************************
// Function:    execute
//
// Description: Deposits the specified amount of money to the given account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

void DepositCommand::execute () {
	const std::string COMMAND = "D";
	try {
		mpcBank->deposit (mAccountNumber, mcAmount);
	}
	catch (CurrencyMismatchException& e) {
		mpcBank->logCurrencyException (COMMAND, mAccountNumber, e.getFromCurrency (),
			e.getToCurrency ());
	}
}