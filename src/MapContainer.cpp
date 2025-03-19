//***************************************************************************
// File name:   MapContainer.cpp
// Author:      Anna Tymoshenko
// Date:        03/18/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include "../include/Account.h"
#include "../include/IContainer.h"
#include "../include/MapContainer.h"
#include <memory>
#include <algorithm>
#include <iostream>

//***************************************************************************
// Constructor: MapContainer
//
// Description: Initializes the container backed by map data structure
//
// Parameters:  none
//
// Returned:    None
//***************************************************************************

MapContainer::MapContainer () {
	mIterator = mAccounts.begin ();
}

//***************************************************************************
// Destructor:  MapContainer
//
// Description: Default destructor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

MapContainer::~MapContainer () {}

//***************************************************************************
// Function:    addAccount
//
// Description: add account to the map
//
// Parameters:  account - account object to put into a map
//
// Returned:    none
//***************************************************************************

void MapContainer::addAccount (unsigned int accNumber,
	std::shared_ptr<Account> account) {
	mAccounts.insert ({ accNumber, account });
}

//***************************************************************************
// Function:    removeAccount
//
// Description: remove account from the map
//
// Parameters:  accountNumber - account number to look up account
//
// Returned:    none
//***************************************************************************

void MapContainer::removeAccount (unsigned int accountNumber) {
	if (bAccountExists (accountNumber)) {
		mAccounts.erase (accountNumber);
	}
}

//***************************************************************************
// Function:    getFirst
//
// Description: get the first account object from the map
//
// Parameters:  none
//
// Returned:    account object
//***************************************************************************

std::shared_ptr<Account> MapContainer::getFirst () {
	if (mAccounts.empty ()) {
		return nullptr;
	}
	mIterator = mAccounts.begin ();
	return mIterator->second;
}

//***************************************************************************
// Function:    getNext
//
// Description: get next account object from the map
//
// Parameters:  none
//
// Returned:    account object
//***************************************************************************

std::shared_ptr<Account> MapContainer::getNext () {
	if (mAccounts.empty ()) {
		return nullptr;
	}
	++mIterator;
	if (mIterator != mAccounts.end ()) {
		return mIterator->second;
	}
	return nullptr;
}

//***************************************************************************
// Function:    bAccountExists
//
// Description: look up and check if account exists in the map
//
// Parameters:  accountNumber - account number to look up account
//
// Returned:    true if exists, false otherwise
//***************************************************************************

bool MapContainer::bAccountExists (unsigned int accountNumber) {
	return mAccounts.find (accountNumber) != mAccounts.end ();
}

//***************************************************************************
// Function:    getAccount
//
// Description: get account that was found in the map
//
// Parameters:  accountNumber - account number to look up account
//
// Returned:    found account object
//***************************************************************************

std::shared_ptr<Account> MapContainer::getAccount (unsigned int accountNumber) {
	auto toFind = mAccounts.find (accountNumber);
	if (toFind != mAccounts.end ()) {
		return toFind->second;
	}
	return nullptr;
}

//***************************************************************************
// Function:    print
//
// Description: print accounts in ascending order of account number
//
// Parameters:  rcOutStream
//
// Returned:    found account object
//***************************************************************************

void MapContainer::print (std::ostream& rcOutStream) const {
	for (const auto& pair : mAccounts) {
		pair.second->display (rcOutStream);
		rcOutStream << std::endl;
	}
}