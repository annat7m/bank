//***************************************************************************
// File name:   PrintVisitor.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/PrintVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"

#include <iostream>

//***************************************************************************
// Constructor: PrintVisitor
//
// Description: Set the stream
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

PrintVisitor::PrintVisitor (std::ostream& rcOutStream)
	: mrcOutStream (rcOutStream) {
}

//***************************************************************************
// Destructor:  PrintVisitor
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

PrintVisitor::~PrintVisitor () {}

//***************************************************************************
// Function:    visit
//
// Description: print checking account
//
// Parameters:  rcCheckingAccount - checking account to print
//
// Returned:    none
//***************************************************************************

void PrintVisitor::visit (CheckingAccount& rcCheckingAccount) {
	mrcOutStream << rcCheckingAccount << std::endl;
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

void PrintVisitor::visit (SavingsAccount& rcSavingsAccount) {
	mrcOutStream << rcSavingsAccount << std::endl;
}