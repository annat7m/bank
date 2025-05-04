//***************************************************************************
// File name:   CurrencyConversionTableTests.cpp
// Author:      Anna Tymoshenko
// Date:        05/01/25
// Class:       CS485
// Assignment:  Assignment 6 - Bank 4
// Purpose:     Provide unit testing for CurrencyConversionTable
//***************************************************************************

#include <gtest/gtest.h>
#include <sstream>

#include "../include/CurrencyConversionTable.h"
#include "../include/Currency.h"
#include "../include/CurrencyMismatchException.h"

namespace {
	struct ConversionTableInitializer {
		ConversionTableInitializer () {
			std::string cFileName = "data/CurrencyConversions.txt";
			CurrencyConversionTable::getInstance ().readConversions (cFileName);
		}
	} conversionInitializer;
}

//***************************************************************************
// Test: 				DirectRate_USDtoGBP
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, DirectRate_USDtoGBP) {
	double rate = CurrencyConversionTable::getInstance ().getRate (Currency
	(CurrencyType::USD), Currency (CurrencyType::GBP));
	EXPECT_EQ (rate, 0.76);
}

//***************************************************************************
// Test: 				DirectRate_YENtoEUR
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, DirectRate_YENtoEUR) {
	double rate = CurrencyConversionTable::getInstance ().getRate (Currency
	(CurrencyType::YEN), Currency (CurrencyType::EUR));
	EXPECT_EQ (rate, 0.69);
}

//***************************************************************************
// Test: 				DirectRate_CHFtoUSD
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, DirectRate_CHFtoUSD) {
	double rate = CurrencyConversionTable::getInstance ().getRate (Currency
	(CurrencyType::CHF), Currency (CurrencyType::USD));
	EXPECT_EQ (rate, 0.75);
}

//***************************************************************************
// Test: 				ReverseRate_USDtoCHF
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, ReverseRate_USDtoCHF) {
	double rate = CurrencyConversionTable::getInstance ().getRate (Currency
	(CurrencyType::USD), Currency (CurrencyType::CHF));
	EXPECT_EQ (rate, 1 / 0.75);
}

//***************************************************************************
// Test: 				ReverseRate_EURtoUSD
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, ReverseRate_EURtoUSD) {
	double rate = CurrencyConversionTable::getInstance ().getRate (Currency
	(CurrencyType::EUR), Currency (CurrencyType::USD));
	EXPECT_EQ (rate, 1 / 0.92);
}

//***************************************************************************
// Test: 				ReverseRate_GBPtoYEN
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, ReverseRate_GBPtoYEN) {
	double rate = CurrencyConversionTable::getInstance ().getRate (Currency
	(CurrencyType::GBP), Currency (CurrencyType::YEN));
	EXPECT_EQ (rate, 1 / 0.58);
}

//***************************************************************************
// Test: 				GetRate_Throw
//
// Description: testing singleton's getRate function 
//***************************************************************************

TEST (CurrencyConversionTableTests, GetRate_Throw) {
	EXPECT_THROW (CurrencyConversionTable::getInstance ()
		.getRate (Currency (CurrencyType::USD), Currency (CurrencyType::YEN)),
		CurrencyMismatchException);
}

//***************************************************************************
// Test: 				RateExists_Real
//
// Description: testing singleton's bConversionExists function 
//***************************************************************************

TEST (CurrencyConversionTableTests, RateExists_Real) {
	EXPECT_TRUE (CurrencyConversionTable::getInstance ().bConversionExists
	(Currency (CurrencyType::EUR), Currency (CurrencyType::GBP)));
}

//***************************************************************************
// Test: 				RateExists_Real_CHFtoUSD
//
// Description: testing singleton's bConversionExists function 
//***************************************************************************

TEST (CurrencyConversionTableTests, RateExists_Real_CHFtoUSD) {
	EXPECT_TRUE (CurrencyConversionTable::getInstance ().bConversionExists
	(Currency (CurrencyType::CHF), Currency (CurrencyType::USD)));
}

//***************************************************************************
// Test: 				RateExists_NonExistant_CHFtoYEN
//
// Description: testing singleton's bConversionExists function 
//***************************************************************************

TEST (CurrencyConversionTableTests, RateExists_NonExistant_CHFtoYEN) {
	EXPECT_FALSE (CurrencyConversionTable::getInstance ().bConversionExists
	(Currency (CurrencyType::CHF), Currency (CurrencyType::YEN)));
}

//***************************************************************************
// Test: 				RateExists_NonExistant
//
// Description: testing singleton's bConversionExists function 
//***************************************************************************

TEST (CurrencyConversionTableTests, RateExists_NonExistant) {
	EXPECT_FALSE (CurrencyConversionTable::getInstance ().bConversionExists
	(Currency (CurrencyType::USD), Currency (CurrencyType::YEN)));
}
