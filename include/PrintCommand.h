//***************************************************************************
// File name:   PrintCommand.h
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

class PrintCommand : public ICommand {

public:
	PrintCommand (std::shared_ptr<Bank> cpBank, std::ostream& rcOutStream);
	virtual ~PrintCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;
	std::ostream& mrcOutStream;

};