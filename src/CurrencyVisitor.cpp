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
// Description: print converted checking account
//
// Parameters:  rcCheckingAccount - checking account to print
//
// Returned:    none
//***************************************************************************
void CurrencyVisitor::visit (CheckingAccount& rcCheckingAccount) {
	rcCheckingAccount.displayConverted (mrcOutStream, mcCurrency);
	mrcOutStream << std::endl;
}

//***************************************************************************
// Function:    visit
//
// Description: print converted checking account
//
// Parameters:  rcSavingsAccount - savings account to print
//
// Returned:    none
//***************************************************************************
void CurrencyVisitor::visit (SavingsAccount& rcSavingsAccount) {
	rcSavingsAccount.displayConverted (mrcOutStream, mcCurrency);
	mrcOutStream << std::endl;
}