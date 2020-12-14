
/*
################################################################################
Purpose: This function performs all timing related operations.

Developed by: Babak Poursartip

V1.00: 11/16/2020 - class initiated.
################################################################################
*/

/** @file Time.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief

@details
CTime: ctor
~CTime: dtor
startTime: sets the starting time point
endTime: sets the ending time point
elaspedTime: Calculates the elapsed time
getElaspedTime: returns the elapsed time

@date Monday, Nov 16, 2020
*/

// libraries
#include <chrono>
#include <iostream>
#include <memory>

// classes
#include "../io/Info.h"
#include "Date.h"

#pragma once

namespace Time {

class CTime : public CDate {

  // members
private:
  std::string _name;

  std::chrono::steady_clock::time_point _start;     //*< the start time
  std::chrono::steady_clock::time_point _end;       //*< the end time
  std::chrono::steady_clock::duration _elapsedTime; //*< duration

  std::shared_ptr<io::CInfo> _info;

  // methods
public:
  explicit CTime(std::string name, std::shared_ptr<io::CInfo> info);
  ~CTime();

  void startTime();
  /**<
  sets the starting time point.
  @return std::chrono::steady_clock::time_point
  @param
  @pre
  -# none.
  @post
  -# no output.
  */

  void endTime();
  /**<
  sets the ending time point.
  @return std::chrono::steady_clock::time_point
  @param
  @pre
  -# none.
  @post
  -# no output.
  */

  void elaspedTime();
  /**<
  Calculates the elapsed time.
  @return void
  @param
  @pre
  -# none.
  @post
  -# no output.
  */

  std::chrono::steady_clock::duration getElaspedTime();
  /**<
  returns the elapsed time.
  @return std::chrono::steady_clock::duration
  @param
  @pre
  -# none.
  @post
  -# no output.
  */
};
} // namespace Time