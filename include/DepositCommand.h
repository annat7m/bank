//***************************************************************************
// File name:   DepositCommand.h
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

class DepositCommand : public ICommand {

public:
	DepositCommand (std::shared_ptr<Bank> cpBank, unsigned int accountNumber,
		Money cAmount);
	virtual ~DepositCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;
	unsigned int mAccountNumber;
	Money mcAmount;

};