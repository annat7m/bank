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
// Description: Initializes Transaction object in Banking system
//
// Parameters:  transactionType - type of transaction that was made
//              amount       		- amount of transaction
//
// Returned:    None
//***************************************************************************

Transaction::Transaction (TransactionType transactionType, const Money& amount) {
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
// Description: Getter for transaction type
//
// Parameters:  none
//
// Returned:    type of transaction
//***************************************************************************

TransactionType Transaction::getType () {
	return mType;
}

//***************************************************************************
// Function:    getAmount
//
// Description: Getter for amount of transaction
//
// Parameters:  none
//
// Returned:    amount of money that was proccessed during transaction
//***************************************************************************

long long Transaction::getAmount () {
	return mAmount;
}