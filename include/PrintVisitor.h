//***************************************************************************
// File name:   PrintVisitor.h
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

class PrintVisitor : public AccountVisitor {

public:
	PrintVisitor (std::ostream& rcOutStream);
	virtual ~PrintVisitor ();

	virtual void visit (CheckingAccount& rcCheckingAccount) override;
	virtual void visit (SavingsAccount& rcSavingsAccount) override;

private:
	std::ostream& mrcOutStream;

};