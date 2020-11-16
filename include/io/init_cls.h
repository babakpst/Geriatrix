
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

@brief reads the name of simulation and the directories from the address.txt
file in the input_file folder, and stores it.

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
#include <fstream>
#include <iostream>
//#include <iomanip>
//#include <math.h>
//#include <sstream>
//#include <string>

// classes
#include "../../include/io/message_cls.h"

#pragma once

namespace io {

class init_cls {

  // members
private:
  std::string TempS; // temporary variable for reading strings from input files

public:
  std::string name;   // name of the input/simulation file
  std::string inDir;  // Input directory containing the input files
  std::string outDir; // output directory

  std::string Input_Dir;        // Input directory
  std::string OutputMatlab_Dir; // dir. for the input file for Matlab visualizer
                                // interface
  std::string log_Dir;          // log file dir
  std::string
      FullFile_Dir; // dir. for the full results in the time domain analysis
  std::string HistoryFile_Dir;      // dir. for the time history of displacement
  std::string TransferFunction_Dir; // dir. for the frequency domain results

  // methods
public:
  explicit init_cls(message_cls *msg); // ctor
  ~init_cls();                         // dtor

  void simulationName_fn(message_cls *msg, const int argv, char *argc[]);
  /**<
  Reads the simulation name from terminal or arguments.
  @return void
  @param
  none.
  @pre
  -# noe.
  @post
  -# no output.
  */

  void directories_fn();
  /**<
  creates the directories variables for the input/output files.
  @return void
  @param
  none.
  @pre
  -# noe.
  @post
  -# no output.
  */

  // creates the output folder, log file, etc.
  void createFolders_fn();
  /**<
  creates the output folder, log file, etc.
  @return void
  @param
  none.
  @pre
  -# noe.
  @post
  -# no output.
  */
};
} // namespace io
