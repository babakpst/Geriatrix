
/*
################################################################################
Purpose: This function returns the current time.

Developed by: Babak Poursartip

V1.00: 12/05/2020 - class initiated.
################################################################################
*/

/** @file Date.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief

@details
CDate: ctor.
~CDate: dtor.
get_date: returning the date.

@date Monday, Nov 24, 2020
*/

// libraries
#include <ctime>
#include <iostream>

// classes
#include "../io/Info.h"

#pragma once

namespace timing {
class CDate {

  // objects
private:
public:
  // methods
private:
public:
  CDate();
  std::string getDate(); //*< returning the date
};
} // namespace timing