//***************************************************************************
// File name:   BackupVisitor.h
// Author:      Anna Tymoshenko
// Date:        04/28/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/AccountVisitor.h"
#include "../include/CheckingAccount.h"
#include "../include/SavingsAccount.h"
#include <iostream>

#pragma once

class BackupVisitor : public AccountVisitor {

public:
	BackupVisitor (std::ostream& rcOutStream_C, std::ostream& rcOutStream_S);
	virtual ~BackupVisitor ();

	virtual void visit (CheckingAccount& rcCheckingAccount) override;
	virtual void visit (SavingsAccount& rcSavingsAccount) override;

private:
	std::ostream& mrcOutStream_C;
	std::ostream& mrcOutStream_S;

};