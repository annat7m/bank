//***************************************************************************
// File name:   IContainer.cpp
// Author:      Anna Tymoshenko
// Date:        03/18/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/IContainer.h"
#include <memory>
#include <algorithm>
#include <iostream>

//***************************************************************************
// Constructor: IContainer
//
// Description: Default constructor
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

IContainer::IContainer () {}

//***************************************************************************
// Destructor:  IContainer
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

IContainer::~IContainer () {}

//***************************************************************************
// Function:    applyVisitor
//
// Description: Apply a visitor on all accounts
//
// Parameters:  rcVisitor - type of visitor to accept
//
// Returned:    none
//***************************************************************************

void IContainer::applyVisitor (AccountVisitor& rcVisitor) {
	std::shared_ptr<Account> pcAccount = getFirst ();
	while (pcAccount) {
		pcAccount->accept (rcVisitor);
		pcAccount = getNext ();
	}
}