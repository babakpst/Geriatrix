
#include "../include/Address_cls.h"

// Constructor
main_ns::address_ns::address_cls::address_cls() {
  std::cout << " --------------- SeismoOne ---------------"
            << "\n";
  std::cout << " ----- Developed by: Babak Poursartip ----"
            << "\n";
  std::cout << " -------------- version 3.0 --------------"
            << "\n";
  std::cout << "\n";
}

/*
###################################################################################################
Purpose: This function reads the data file name and directories

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 05/14/2018 - Initiated: Compiled without error for the first time.

###################################################################################################
*/

void main_ns::address_ns::address_cls::address_fn() {

  // Open address files
  std::cout << " -opening the address file ..."
            << "\n";
  std::ifstream Addressfile;
  Addressfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    Addressfile.open("Address.txt", std::ios::in);
  } catch (std::ifstream::failure
               &inputerr) { // here is the catch for opening the input file.
    std::cout << " Error while opening the address file. \n";
    std::cout << " Please make sure the input file is in the cpp folder.\n";
    std::cout << " The error message is: " << inputerr.what() << "\n";
  }

  // Reading simulation information
  std::cout << " -reading the information file ..."
            << "\n";
  getline(Addressfile, TempS);
  Addressfile >> Name; // Input file name

  getline(Addressfile, TempS);
  getline(Addressfile, TempS);
  Addressfile >> Directory; // Directory of the input file

  std::cout << "\n";
  std::cout << " Analysis information:"
            << "\n";
  std::cout << " Name:  " << Name << "\n";
  std::cout << " Directory:  " << Directory << "\n";

  std::cout << " -creating directories ..."
            << "\n";

  // Windows
  /*
Input_Dir            = Directory + "\\Input\\"   + Name + ".txt";
OutputMatlab_Dir     = Directory + "\\Output\\"  + Name + ".Matlab";
Info_Dir             = Directory + "\\Output\\"  + Name + ".inf";

FullFile_Dir         = Directory + "\\Output\\"  + Name + ".Res";
HistoryFile_Dir      = Directory + "\\Output\\"  + Name + ".His";
TransferFunction_Dir = Directory + "\\Output\\"  + Name + ".TRF";
*/

  // Linux

  Input_Dir = Directory + "/input/" + Name + ".txt";
  OutputMatlab_Dir = Directory + "/output/" + Name + ".Matlab";
  Info_Dir = Directory + "/output/" + Name + ".inf";

  FullFile_Dir = Directory + "/output/" + Name + ".Res";
  HistoryFile_Dir = Directory + "/output/" + Name + ".His";
  TransferFunction_Dir = Directory + "/output/" + Name + ".TRF";

  // Final Directories
  std::cout << "  Input dir:   " << Input_Dir << "\n";
  std::cout << "  Output dir:  " << Info_Dir << "\n";

  Addressfile.close();
  std::cout << " -done with the address file, successfully."
            << "\n"
            << "\n";
}
