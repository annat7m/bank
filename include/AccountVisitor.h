//***************************************************************************
// File name:   AccountVisitor.h
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include <iostream>

#pragma once

class AccountVisitor {

public:
	AccountVisitor ();
	virtual ~AccountVisitor ();

	virtual void visit (CheckingAccount& rcCheckingAccount) = 0;
	virtual void visit (SavingsAccount& rcSavingsAccount) = 0;

};