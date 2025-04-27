//***************************************************************************
// File name:   MonthlyVisitor.cpp
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/MonthlyVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"

#include <iostream>

//***************************************************************************
// Constructor: MonthlyVisitor
//
// Description: Set the stream
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

MonthlyVisitor::MonthlyVisitor () {
}

//***************************************************************************
// Destructor:  MonthlyVisitor
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

MonthlyVisitor::~MonthlyVisitor () {}

//***************************************************************************
// Function:    visit
//
// Description: print checking account
//
// Parameters:  rcCheckingAccount - checking account to print
//
// Returned:    none
//***************************************************************************

void MonthlyVisitor::visit (CheckingAccount& rcCheckingAccount) {
	rcCheckingAccount.chargeMonthlyFee ();
	rcCheckingAccount.generateInterest ();
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

void MonthlyVisitor::visit (SavingsAccount& rcSavingsAccount) {
	rcSavingsAccount.chargeMonthlyFee ();
	rcSavingsAccount.generateInterest ();
}