//***************************************************************************
// File name:   MonthlyVisitor.h
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/AccountVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include <iostream>

#pragma once

class MonthlyVisitor : public AccountVisitor {

public:
	MonthlyVisitor ();
	virtual ~MonthlyVisitor ();

	virtual void visit (CheckingAccount& rcCheckingAccount) override;
	virtual void visit (SavingsAccount& rcSavingsAccount) override;

};