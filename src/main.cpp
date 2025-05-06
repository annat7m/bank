//***************************************************************************
// File name:   main.cpp
// Author:      Anna Tymoshenko
// Date:        04/07/2025
// Class:       CS485
// Assignment:  Assignment 6 - Bank 4
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
#include "../include/CurrencyConversionTable.h"

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
//                     argv[3] should be the path to the Conversions file
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main (int argc, char* argv[]) {

	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] <<
			" accountsFile commandsFile conversionsFile\n";
		return EXIT_FAILURE;
	}

	std::string accountsFileName = argv[1];
	std::string commandsFileName = argv[2];
	std::string conversionTableFileName = argv[3];

	CurrencyConversionTable::getInstance ().readConversions (conversionTableFileName);

	TXTAccountReader cAccountReader (accountsFileName);

	std::shared_ptr<ITransactionReader> pcCommandsReader;

	if (commandsFileName.ends_with (".csv")) {
		pcCommandsReader = std::make_shared<CSVTransactionReader> (commandsFileName);
	}
	else if (commandsFileName.ends_with (".txt")) {
		pcCommandsReader = std::make_shared<TXTTransactionReader> (commandsFileName);
	}

	std::shared_ptr<IContainer> mapContainer = std::make_shared<MapContainer> ();
	Bank firstBank (cAccountReader, mapContainer);

	try {
		std::shared_ptr<ICommand> pcCommand;

		while ((pcCommand =
			pcCommandsReader->readTransactions (std::cout, firstBank)) != nullptr) {
			pcCommand->execute ();
		}
	}
	catch (const std::range_error& e) {
		std::cerr << e.what () << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

/*

1. To add the ability to handle Swiss Francs, which source files (.h or .cpp) 
did you need to add/modify? List each function you edited or added in an existing 
class.

	Currency.h, 
	Currency.cpp

	Currency::Currency (std::string type)
	Currency::display

2. To add the ability to handle the Transfer Command, which source files 
(.h or .cpp) did you need to add/modify? List each function you edited or added
in an existing class.

	TrahsferCommand.h
	TrahsferCommand.cpp
	TXTTransactionReader.cpp 
	CSVTransactionReader.cpp 

	TXTTransactionReader::readTransactions
	CSVTransactionReader::readTransactions

3. What do these two answers say about your design? Do they indicate a good design? 
Poor design? Explain why you think so. Be sure to reference the notion of 
encapsulation and “isolate what may change.”

	I think this says that my design is good because everythng is loosely coupled
	and adding new functionality to the program affects very few classes. 
	In case of adding new currencies, no matter what changes I make,
	those are isolated because changes in Currency class don't affect any other 
	class -> Currency is encapsulated. 
	The only thing that could have made my amazing design even better is adding
	a factory for commands in the readers, so I wouldn't need to change the readers
	to add the same code to two of them.

*/