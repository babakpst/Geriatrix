
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
#include <memory>

// classes
#include "../../src/parameter.h"
#include "../io/Info.h"

#pragma once

namespace Time {
class CDate {

  // objects
private:
  std::string _date;
  std::string _name;

  std::shared_ptr<io::CInfo> _info;

public:
  // methods

private:
  CDate();

public:
  CDate(std::string name, std::shared_ptr<io::CInfo> info);
  void setDate();        //<* sets the date
  std::string getDate(); //*< returning the date
};
} // namespace Time