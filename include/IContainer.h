//***************************************************************************
// File name:   IContainer.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Account.h"
#include <memory>
#include <iostream>

#pragma once

class IContainer {
public:
	IContainer ();
	virtual ~IContainer ();

	virtual void addAccount (unsigned int accNumber, 
		std::shared_ptr<Account> account) = 0;
	virtual void removeAccount (unsigned int accountNumber) = 0;
	virtual std::shared_ptr<Account> getFirst () = 0;
	virtual std::shared_ptr<Account> getNext () = 0;

	virtual bool bAccountExists (unsigned int accountNumber) = 0;
	virtual std::shared_ptr<Account> getAccount (unsigned int accountNumber) = 0;

	virtual void print (std::ostream& rcOutStream) const = 0;

private:

};