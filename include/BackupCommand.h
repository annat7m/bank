//***************************************************************************
// File name:   BackupCommand.h
// Author:      Anna Tymoshenko
// Date:        04/28/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <memory>
#include "../include/ICommand.h"
#include "../include/Bank.h"

#pragma once

class BackupCommand : public ICommand {

public:
	BackupCommand (std::shared_ptr<Bank> cpBank, std::ostream& rcOutStream_S,
		std::ostream& rcOutStream_C);
	virtual ~BackupCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;
	std::ostream& mrcOutStream_S;
	std::ostream& mrcOutStream_C;

};