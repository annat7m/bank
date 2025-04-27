//***************************************************************************
// File name:   MonthlyCommand.h
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <memory>
#include "../include/ICommand.h"
#include "../include/Bank.h"

#pragma once

class MonthlyCommand : public ICommand {

public:
	MonthlyCommand (std::shared_ptr<Bank> cpBank);
	virtual ~MonthlyCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;

};