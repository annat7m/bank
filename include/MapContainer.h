//***************************************************************************
// File name:   MapContainer.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/IContainer.h"
#include <map>
#include <iostream>

#pragma once

class MapContainer : public IContainer {
public:
	MapContainer ();
	virtual ~MapContainer ();

	virtual void addAccount (unsigned int accountNumber,
		std::shared_ptr<Account> pcAccount) override;
	virtual void removeAccount (unsigned int accountNumber) override;
	virtual std::shared_ptr<Account> getFirst () override;
	virtual std::shared_ptr<Account> getNext () override;

	virtual bool bAccountExists (unsigned int accountNumber) override;
	virtual std::shared_ptr<Account> getAccount (unsigned int accountNumber)
		override;

	virtual void print (std::ostream& rcOutStream) const override;

private:
	std::map<unsigned int, std::shared_ptr<Account>> mAccounts;
	std::map<unsigned int, std::shared_ptr<Account>>::iterator mIterator;

};