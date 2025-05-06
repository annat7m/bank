//***************************************************************************
// File name:   CurrencyCommand.h
// Author:      Anna Tymoshenko
// Date:        05/01/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <memory>
#include <string>
#include "../include/ICommand.h"
#include "../include/Bank.h"

#pragma once

class CurrencyCommand : public ICommand {

public:
	CurrencyCommand (std::shared_ptr<Bank> cpBank, std::ostream& rcOutStream, 
		Currency cCurrency);
	virtual ~CurrencyCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;
	std::ostream& mrcOutStream;
	Currency mcCurrency;

};