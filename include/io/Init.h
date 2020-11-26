
/*
################################################################################
Purpose: This function reads the data file name and directories

Developed by: Babak Poursartip

V1.00: 05/14/2018 - class initiated.
V1.01: 05/14/2018 - initiated: Compiled without error for the first time.
V2.01: 11/05/2020 - major modificaiton in the address file.

################################################################################
*/

/** @file init_cls.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 2.0

@brief initializes the simulation name and directories.

@details
init_cls: ctor
~init_cls: dtor
directories_fn():   creates the directories variables for the input/output
files.
createFolders_fn(): creates the output folder, log file, etc.
simulationName_fn(): Reads the simulation name from terminal or arguments.


@date Friday, Nov 15, 2020
*/

// libraries
#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>

//#include <iomanip>
//#include <math.h>
//#include <sstream>
//#include <string>

// classes
#include "../../include/io/info_cls.h"

#pragma once

namespace io {

class init_cls {

  // members
private:
  std::string _name; // name of the input/simulation file

  std::string _inDir;           // Input directory containing the input files
  std::string _outDir;          // output directory
  std::string _logDir;          // log file dir
  std::string _HistoryFile_Dir; // dir. for the time history of displacement
  std::string _TransferFunction_Dir; // dir. for the frequency domain results

  // methods
public:
  explicit init_cls(std::unique_ptr<io::info_cls> &info); // ctor
  ~init_cls();                                            // dtor

  void simulationName_fn(std::unique_ptr<io::info_cls> &info, const int argv,
                         char *argc[]);
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

  void directories_fn(std::unique_ptr<io::info_cls> &info);
  /**<
  creates the directories variables for the input/output files.
  @return void
  @param
  std::unique_ptr<io::info_cls> &info
  @pre
  -# noe.
  @post
  -# no output.
  */

  // creates the output folder, log file, etc.
  void createFolders_fn(std::unique_ptr<io::info_cls> &info);
  /**<
  creates the output folder, log file, etc.
  @return void
  @param
  std::unique_ptr<io::info_cls> &info
  @pre
  -# noe.
  @post
  -# no output.
  */
};
} // namespace io
