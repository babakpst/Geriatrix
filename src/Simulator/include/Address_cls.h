

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <iomanip>

#ifndef ADDRESS_H
#define ADDRESS_H

namespace main_ns
{

namespace address_ns
{

class address_cls
{

  // members
private:
  std::string TempS; // temporary variable for reading strings from input files

public:
  std::string Name;      // name of the input file
  std::string Directory; // Input/output directory

  std::string Input_Dir;            // Input directory
  std::string OutputMatlab_Dir;     // dir. for the input file for Matlab visualizer interface
  std::string Info_Dir;             // dir. for general information file
  std::string FullFile_Dir;         // dir. for the full results in the time domain analysis
  std::string HistoryFile_Dir;      // dir. for the time history of displacement
  std::string TransferFunction_Dir; // dir. for the frequency domain results

  // methods
public:
  explicit address_cls();
  void address_fn(); // Reads the file name and directories
};
} // namespace address_ns
} // namespace main_ns
#endif
