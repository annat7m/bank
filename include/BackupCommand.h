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
#include <string>
#include "../include/ICommand.h"
#include "../include/Bank.h"

#pragma once

class BackupCommand : public ICommand {

public:
	BackupCommand (std::shared_ptr<Bank> cpBank, const std::string& rcFileName_C,
		const std::string& rcFileName_S);
	virtual ~BackupCommand ();

	virtual void execute () override;

private:
	std::shared_ptr<Bank> mpcBank;
	std::string mcFileName_C;
	std::string mcFileName_S;

};