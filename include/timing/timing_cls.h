

/*
################################################################################
Purpose: This function performs all timing related operations.

Developed by: Babak Poursartip

V1.00: 11/16/2020 - class initiated.
################################################################################
*/

/** @file timing_cls.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief

@details
timing_cls: ctor
~timing_cls: dtor


@date Monday, Nov 16, 2020
*/

// libraries
#include <iostream>

// classes

#pragma once
namespace time {

class timing_cls {

  // members
private:
  // methods
public:
  explicit timing_cls(std::unique_ptr<io::info_cls> &info); // ctor
  ~timing_cls();                                            // dtor

  void getTime_fn(std::unique_ptr<io::info_cls> &info);
  /**<
  Reads the simulation name from terminal or arguments.
  @return void
  @param
  std::unique_ptr<io::info_cls> &info,
  const int argv,
  char *argc[]
  @pre
  -# noe.
  @post
  -# no output.
  */
}
} // namespace time