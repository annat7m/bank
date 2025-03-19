//***************************************************************************
// File name:   MapContainer.cpp
// Author:      Anna Tymoshenko
// Date:        03/18/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

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

MapContainer::MapContainer () {}

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

void MapContainer::addAccount (std::shared_ptr<Account> account) {

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

}