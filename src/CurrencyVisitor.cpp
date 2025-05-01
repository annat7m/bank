//***************************************************************************
// File name:   CurrencyVisitor.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CurrencyVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include "../include/CurrencyMismatchException.h"

#include <iostream>

//***************************************************************************
// Constructor: CurrencyVisitor
//
// Description: Set the stream and currency
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************
CurrencyVisitor::CurrencyVisitor (std::ostream& rcOutStream, Currency cCurrency)
	: mrcOutStream (rcOutStream), mcCurrency (cCurrency) {
}

//***************************************************************************
// Destructor:  CurrencyVisitor
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
CurrencyVisitor::~CurrencyVisitor () {}

//***************************************************************************
// Function:    visit
//
// Description: print all converted checking accounts
//
// Parameters:  rcCheckingAccount - checking account to print
//
// Returned:    none
//***************************************************************************
void CurrencyVisitor::visit (CheckingAccount& rcCheckingAccount) {
	try {
		// basically reprint account with new values of all balances
		// need a bunch of getters in Account object, like getMinBalance, getFee, getRate
	}
	catch (const CurrencyMismatchException&) {
		rcCheckingAccount.display (mrcOutStream);
	}
}

//***************************************************************************
// Function:    visit
//
// Description: print savings account
//
// Parameters:  rcSavingsAccount - savings account to print
//
// Returned:    none
//***************************************************************************
void CurrencyVisitor::visit (SavingsAccount& rcSavingsAccount) {
	mrcOutStream << rcSavingsAccount << std::endl;
}