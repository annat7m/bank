//***************************************************************************
// File name:   CurrencyVisitor.h
// Author:      Anna Tymoshenko
// Date:        05/01/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/AccountVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include <iostream>

#pragma once

class CurrencyVisitor : public AccountVisitor {

public:
	CurrencyVisitor (std::ostream& rcOutStream, Currency cCurrency);
	virtual ~CurrencyVisitor ();

	virtual void visit (CheckingAccount& rcCheckingAccount) override;
	virtual void visit (SavingsAccount& rcSavingsAccount) override;

private:
	std::ostream& mrcOutStream;
	Currency mcCurrency;

};