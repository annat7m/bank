//***************************************************************************
// File name:   TransferCommand.h
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

class TransferCommand : public ICommand {

public:
	TransferCommand (std::shared_ptr<Bank> cpBank, unsigned int fromAccountNumber,
		unsigned int toAccountNumber, Money cAmount);
	virtual ~TransferCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;
	unsigned int mFromAccountNumber;
	unsigned int mToAccountNumber;
	Money mcAmount;

};