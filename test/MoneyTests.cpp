//***************************************************************************
// File name:   MoneyTests.cpp
// Author:      Anna Tymoshenko
// Date:        04/06/25
// Class:       CS485
// Assignment:  Assignment 5 - Bank 3
// Purpose:     Provide unit testing for Money - updated with currency
//***************************************************************************

#include <gtest/gtest.h>
#include <sstream>

#include "../include/Money.h"
#include "../include/Currency.h"
#include "../include/CurrencyMismatchException.h"
#include "../include/CurrencyConversionTable.h"

namespace {
	struct ConversionTableInitializer {
		ConversionTableInitializer () {
			std::string cFileName = "data/CurrencyConversions.txt";
			CurrencyConversionTable::getInstance ()
				.readConversions (cFileName);
		}
	} conversionInitializer;
}

//***************************************************************************
// Test: 				Constructor_LongLong_Positive
//
// Description: testing the constructor of the Money class that initializes
//							Money object with 
//***************************************************************************

TEST (MoneyConstructorTests, Constructor_LongLong_Positive) {
	Money amount (100, Currency (CurrencyType::USD));
	std::ostringstream stream;
	stream << amount;
	EXPECT_EQ (stream.str (), "USD1.00");
}

//***************************************************************************
// Test: 				Constructor_LongLong_Negative
//
// Description: testing the constructor of the Money class that initializes
//							Money object with 
//***************************************************************************

TEST (MoneyConstructorTests, Constructor_LongLong_Negative) {
	Money amount (-100, Currency (CurrencyType::YEN));
	std::ostringstream stream;
	stream << amount;
	EXPECT_EQ (stream.str (), "YEN-1.00");
}

//***************************************************************************
// Test: 				Constructor_LongLong_Negative_CHF
//
// Description: testing the constructor of the Money class that initializes
//							Money object with 
//***************************************************************************

TEST (MoneyConstructorTests, Constructor_LongLong_Negative_CHF) {
	Money amount (-100, Currency (CurrencyType::CHF));
	std::ostringstream stream;
	stream << amount;
	EXPECT_EQ (stream.str (), "CHF-1.00");
}

// ***************************************************************************
// Test: 				CopyConstructor
//
// Description: testing the assignment operator of the Money object 
// ***************************************************************************

TEST (MoneyConstructorTests, CopyConstructor) {
	Money original (250, Currency (CurrencyType::EUR));
	Money copy = original;
	std::ostringstream stream;
	stream << copy;
	EXPECT_EQ (stream.str (), "EUR2.50");
}

// ***************************************************************************
// Test: 				SimpleAddition_CurrencyMismatchException
//
// Description: testing if adding two different currencies will throw 
//							an exception 
// ***************************************************************************

TEST (MoneyArithmeticTests, Addition_CurrencyMismatchException) {
	Money usdMoney (100, Currency (CurrencyType::USD));
	Money eurMoney (100, Currency (CurrencyType::YEN));
	EXPECT_THROW ({ Money result = usdMoney + eurMoney; },
		CurrencyMismatchException);
}

// ***************************************************************************
// Test: 				SimpleSubtraction_CurrencyMismatchException
//
// Description: testing if adding two different currencies that do not have 
//							a defined conversion in the file will throw an exception 
// ***************************************************************************

TEST (MoneyArithmeticTests, Subtraction_CurrencyMismatchException) {
	Money usdMoney (100, Currency (CurrencyType::USD));
	Money eurMoney (100, Currency (CurrencyType::YEN));
	EXPECT_THROW ({ Money result = usdMoney - eurMoney; },
		CurrencyMismatchException);
}

// ***************************************************************************
// Test: 				ShortenedAddition_CurrencyMismatchException
//
// Description: testing if adding two different currencies that do not have 
//							a defined conversion in the file will throw an exception 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedAddition_CurrencyMismatchException) {
	Money usdMoney (100, Currency (CurrencyType::USD));
	Money eurMoney (100, Currency (CurrencyType::YEN));
	EXPECT_THROW ({ usdMoney += eurMoney; }, CurrencyMismatchException);
}

// ***************************************************************************
// Test: 				ShortenedSubtraction_CurrencyMismatchException
//
// Description: testing if adding two different currencies that do not have 
//							a defined conversion in the file will throw an exception 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedSubtraction_CurrencyMismatchException) {
	Money usdMoney (100, Currency (CurrencyType::USD));
	Money eurMoney (100, Currency (CurrencyType::YEN));
	EXPECT_THROW ({ usdMoney -= eurMoney; }, CurrencyMismatchException);
}

// ***************************************************************************
// Test: 				SimpleAddition
//
// Description: testing the addition operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleAddition) {
	Money value1 (250, Currency (CurrencyType::USD));
	Money value2 (50, Currency (CurrencyType::USD));
	std::ostringstream stream;
	stream << value1 + value2;
	EXPECT_EQ (stream.str (), "USD3.00");
}

// ***************************************************************************
// Test: 				SimpleAddition_DifferentCurrencies
//
// Description: testing the addition operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleAddition_DifferentCurrencies) {
	Money value1 (1000, Currency (CurrencyType::EUR));
	Money value2 (100, Currency (CurrencyType::USD));
	std::ostringstream stream;
	stream << value1 + value2;
	EXPECT_EQ (stream.str (), "EUR10.92");
}

// ***************************************************************************
// Test: 				SimpleAddition_DifferentCurrencies_CHF
//
// Description: testing the addition operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleAddition_DifferentCurrencies_CHF) {
	Money value1 (1000, Currency (CurrencyType::CHF));
	Money value2 (100, Currency (CurrencyType::USD));
	std::ostringstream stream;
	stream << value1 + value2;
	EXPECT_EQ (stream.str (), "CHF11.33");
}

// ***************************************************************************
// Test: 				ShortenedAddition
//
// Description: testing operator+= 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedAddition) {
	Money value1 (250, Currency (CurrencyType::EUR));
	Money value2 (50, Currency (CurrencyType::EUR));
	std::ostringstream stream;
	value1 += value2;
	stream << value1;
	EXPECT_EQ (stream.str (), "EUR3.00");
}

// ***************************************************************************
// Test: 				ShortenedAddition_DifferentCurrencies
//
// Description: testing operator+= 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedAddition_DifferentCurrencies) {
	Money value1 (1000, Currency (CurrencyType::EUR));
	Money value2 (100, Currency (CurrencyType::USD));
	std::ostringstream stream;
	value1 += value2;
	stream << value1;
	EXPECT_EQ (stream.str (), "EUR10.92");
}

// ***************************************************************************
// Test: 				ShortenedAddition_DifferentCurrencies_CHF
//
// Description: testing operator+= 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedAddition_DifferentCurrencies_CHF) {
	Money value1 (1000, Currency (CurrencyType::USD));
	Money value2 (100, Currency (CurrencyType::CHF));
	std::ostringstream stream;
	value1 += value2;
	stream << value1;
	EXPECT_EQ (stream.str (), "USD10.75");
}

// ***************************************************************************
// Test: 				SimpleSubtraction
//
// Description: testing the subtraction operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleSubtraction) {
	Money value1 (250, Currency (CurrencyType::GBP));
	Money value2 (50, Currency (CurrencyType::GBP));
	std::ostringstream stream;
	stream << value1 - value2;
	EXPECT_EQ (stream.str (), "GBP2.00");
}

// ***************************************************************************
// Test: 				SimpleSubtraction_DifferentCurrencies
//
// Description: testing the subtraction operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleSubtraction_DifferentCurrencies) {
	Money value1 (1000, Currency (CurrencyType::USD));
	Money value2 (100, Currency (CurrencyType::GBP));
	std::ostringstream stream;
	stream << value1 - value2;
	EXPECT_EQ (stream.str (), "USD8.69");
}

// ***************************************************************************
// Test: 				SimpleSubtraction_DifferentCurrencies_CHF
//
// Description: testing the subtraction operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleSubtraction_DifferentCurrencies_CHF) {
	Money value1 (1000, Currency (CurrencyType::USD));
	Money value2 (100, Currency (CurrencyType::CHF));
	std::ostringstream stream;
	stream << value1 - value2;
	EXPECT_EQ (stream.str (), "USD9.25");
}

// ***************************************************************************
// Test: 				ShortenedSubtraction
//
// Description: testing operator-= 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedSubtraction) {
	Money value1 (250, Currency (CurrencyType::GBP));
	Money value2 (50, Currency (CurrencyType::GBP));
	std::ostringstream stream;
	value1 -= value2;
	stream << value1;
	EXPECT_EQ (stream.str (), "GBP2.00");
}

// ***************************************************************************
// Test: 				ShortenedSubtraction_DifferentCurrencies
//
// Description: testing operator-= 
// ***************************************************************************

TEST (MoneyArithmeticTests, ShortenedSubtraction_DifferentCurrencies) {
	Money value1 (1000, Currency (CurrencyType::USD));
	Money value2 (100, Currency (CurrencyType::GBP));
	std::ostringstream stream;
	value1 -= value2;
	stream << value1;
	EXPECT_EQ (stream.str (), "USD8.69");
}

// ***************************************************************************
// Test: 				SimpleMultiplication
//
// Description: testing the multiplication operator 
// ***************************************************************************

TEST (MoneyArithmeticTests, SimpleMultiplication) {
	Money value1 (250, Currency (CurrencyType::USD));
	double value2 = 2.0;
	std::ostringstream stream;
	stream << value1 * value2;
	EXPECT_EQ (stream.str (), "USD5.00");
}

// ***************************************************************************
// Test: 				LessThan_Appropriate
//
// Description: testing operator<
// ***************************************************************************

TEST (MoneyComparisonTests, LessThan_Appropriate) {
	Money value1 (250, Currency (CurrencyType::USD));
	Money value2 (300, Currency (CurrencyType::USD));
	EXPECT_TRUE (value1 < value2);
}

// ***************************************************************************
// Test: 				LessThan_Inappropriate
//
// Description: testing operator<
// ***************************************************************************

TEST (MoneyComparisonTests, LessThan_Inappropriate) {
	Money value1 (250, Currency (CurrencyType::YEN));
	Money value2 (200, Currency (CurrencyType::YEN));
	EXPECT_FALSE (value1 < value2);
}

// ***************************************************************************
// Test: 				GraterThanOrEqual_Appropriate_Grater
//
// Description: testing operator>=
// ***************************************************************************

TEST (MoneyComparisonTests, GraterThanOrEqual_Appropriate_Grater) {
	Money value1 (250, Currency (CurrencyType::YEN));
	Money value2 (200, Currency (CurrencyType::YEN));
	EXPECT_TRUE (value1 >= value2);
}

// ***************************************************************************
// Test: 				GraterThanOrEqual_Appropriate_Equal
//
// Description: testing operator>=
// ***************************************************************************

TEST (MoneyComparisonTests, GraterThanOrEqual_Appropriate_Equal) {
	Money value1 (250, Currency ("GBP"));
	Money value2 (250, Currency ("GBP"));
	EXPECT_TRUE (value1 >= value2);
}

// ***************************************************************************
// Test: 				GraterThanOrEqual_Inappropriate
//
// Description: testing operator>=
// ***************************************************************************

TEST (MoneyComparisonTests, GraterThanOrEqual_Inappropriate) {
	Money value1 (250, Currency ("EUR"));
	Money value2 (300, Currency ("EUR"));
	EXPECT_FALSE (value1 >= value2);
}

// ***************************************************************************
// Test: 				Input
//
// Description: testing operator>>
// ***************************************************************************

TEST (MoneyIOTests, Input) {
	Money value (0, Currency (CurrencyType::YEN)); // any value any currency resets
	std::ostringstream outStream;
	std::istringstream inStream ("USD 20000");
	inStream >> value;
	outStream << value;
	EXPECT_EQ (outStream.str (), "USD200.00");
}

// ***************************************************************************
// Test: 				Output
//
// Description: testing operator<<
// ***************************************************************************

TEST (MoneyIOTests, Output) {
	Money value (0, Currency (CurrencyType::USD));
	std::ostringstream outStream;
	outStream << value;
	EXPECT_EQ (outStream.str (), "USD0.00");
}

// ***************************************************************************
// Test: 				ConvertToSameCurrency
//
// Description: testing Money::convertTo function
// ***************************************************************************

TEST (MoneyConversionTests, ConvertToSameCurrency) {
	Money usd100 (100, Currency (CurrencyType::USD));
	Money converted = usd100.convertTo (Currency (CurrencyType::USD));
	std::ostringstream stream;
	stream << converted;
	EXPECT_EQ (stream.str (), "USD1.00");
}

// ***************************************************************************
// Test: 				ConvertUsdToEur
//
// Description: testing Money::convertTo function
// ***************************************************************************

TEST (MoneyConversionTests, ConvertUsdToEur) {
	Money usd100 (100, Currency (CurrencyType::USD));
	Money eur = usd100.convertTo (Currency (CurrencyType::EUR));
	std::ostringstream stream;
	stream << eur;
	EXPECT_EQ (stream.str (), "EUR0.92");
}