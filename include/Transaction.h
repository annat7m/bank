//***************************************************************************
// File name:   Transaction.h
// Author:      Anna Tymoshenko
// Date:        03/15/2025
// Class:       CS485
// Assignment:  Assignment 4 - Bank 2
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>
#include "../include/Money.h"

#pragma once

#ifndef TRANSACTIO_H
#define TRANSACTION_H

enum class TransactionType {
	deposit,
	withdrawal,
	fee,
	interest
};

#endif

class Transaction {

public:
	Transaction (TransactionType transactionType, const Money& amount);
	virtual ~Transaction ();

	TransactionType& getType () const;
	Money& getAmount () const;

private:
	TransactionType mType;
	Money mAmount;

};