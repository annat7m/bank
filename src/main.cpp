//***************************************************************************
// File name:   main.cpp
// Author:      Anna Tymoshenko
// Date:        03/06/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <memory>
#include <fstream>

#include "../include/Bank.h"
#include "../include/TXTAccountReader.h"
#include "../include/TXTTransactionReader.h"
#include "../include/MapContainer.h"

//***************************************************************************
// Function:    main
//
// Description: Make Bank functional
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main () {
	const std::string ACCOUNTS_FILENAME = "data/Accounts.txt";
	const std::string TRANSACTIONS_FILENAME = "data/Commands.txt";

	TXTAccountReader accountReader (ACCOUNTS_FILENAME);
	TXTTransactionReader commandsReader (TRANSACTIONS_FILENAME);

	std::shared_ptr<IContainer> mapContainer = std::make_shared<MapContainer> ();

	Bank firstBank (accountReader, mapContainer);

	commandsReader.readTransactions (std::cout, firstBank);

	return EXIT_SUCCESS;

}
