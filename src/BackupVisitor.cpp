//***************************************************************************
// File name:   BackupVisitor.cpp
// Author:      Anna Tymoshenko
// Date:        04/28/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/BackupVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"

#include <iostream>

//***************************************************************************
// Constructor: BackupVisitor
//
// Description: Set the streams
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

BackupVisitor::BackupVisitor (std::ostream& rcOutStream_S, 
	std::ostream& rcOutStream_C)
	: mrcOutStream_S (rcOutStream_S), mrcOutStream_C (rcOutStream_C) {
}

//***************************************************************************
// Destructor:  BackupVisitor
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

BackupVisitor::~BackupVisitor () {}

//***************************************************************************
// Function:    visit
//
// Description: print checking account
//
// Parameters:  rcCheckingAccount - checking account to print
//
// Returned:    none
//***************************************************************************

void BackupVisitor::visit (CheckingAccount& rcCheckingAccount) {
	mrcOutStream_C << rcCheckingAccount << std::endl;
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

void BackupVisitor::visit (SavingsAccount& rcSavingsAccount) {
	mrcOutStream_S << rcSavingsAccount << std::endl;
}