//***************************************************************************
// File name:   ICommand.h
// Author:      Anna Tymoshenko
// Date:        04/26/2025
// Class:       CS485
// Assignment:  Bank 4
// Purpose:     Practice Object Oriented Design Skills
//***************************************************************************

#include <iostream>

#pragma once

class ICommand {
	
public:
	virtual ~ICommand ();

	virtual void execute () = 0;

};