//***************************************************************************
// File name:   Transaction.cpp
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Account.h"
#include <iostream>

//***************************************************************************
// Constructor: Transaction
//
// Description: Initializes Checking Account object in Banking system
//
// Parameters:  accountNumber - 
//              balance       - 
//
// Returned:    None
//***************************************************************************

Transaction::Transaction (TransactionType transactionType, long long amount) {
	mType = transactionType;
	mAmount = amount;
}

//***************************************************************************
// Destructor:  Transaction
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

Transaction::~Transaction () {}

//***************************************************************************
// Function:    getType
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

TransactionType Transaction::getType () {
	return mType;
}

//***************************************************************************
// Function:    getAmount
//
// Description: 
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************

long long Transaction::getAmount () {
	return mAmount;
}