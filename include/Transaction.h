//***************************************************************************
// File name:   Transaction.h
// Author:      Anna Tymoshenko
// Date:        03/04/2025
// Class:       CS485
// Assignment:  Assignment 3 - Bank Accounts
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <vector>

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
	Transaction (TransactionType transactionType, long long amount);
	virtual ~Transaction ();

	TransactionType getType ();
	long long getAmount ();

private:
	TransactionType mType;
	long long mAmount;

};