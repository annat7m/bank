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
#include "../include/Account.h"
#include "../include/CheckingAccount.h"
#include "../include/FlatInterest.h"
#include "../include/TXTAccountReader.h"
#include "../include/TXTTransactionReader.h"
#include "../include/CSVTransactionReader.h"
#include "../include/MapContainer.h"

//***************************************************************************
// Function:    main
//
// Description: Make Bank functional
//
// Parameters:  argc - number of command-line arguments
//              argv - an array of C-style strings representing command-line
//                     arguments:
//                     argv[1] should be the path to the Accounts file
//                     argv[2] should be the path to the Commands file
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main (int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " accountsFile commandsFile\n";
		return EXIT_FAILURE;
	}

	std::string accountsFileName = argv[1];
	std::string commandsFileName = argv[2];

	TXTAccountReader accountReader (accountsFileName);

	std::shared_ptr<ITransactionReader> commandsReader;

	if (commandsFileName.ends_with (".csv")) {
		commandsReader = std::make_shared<CSVTransactionReader> (commandsFileName);
	}
	else if (commandsFileName.ends_with (".txt")) {
		commandsReader = std::make_shared<TXTTransactionReader> (commandsFileName);
	}

	std::shared_ptr<IContainer> mapContainer = std::make_shared<MapContainer> ();
	Bank firstBank (accountReader, mapContainer);

	commandsReader->readTransactions (std::cout, firstBank);

	return EXIT_SUCCESS;
}
