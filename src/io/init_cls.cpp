
#include "../../include/io/init_cls.h"

// ctor
io::init_cls::init_cls(message_cls *msg) {
  msg->prt_txt_terminal(" initializing the directories ...");
}

void io::init_cls::simulationName_fn(message_cls *msg, const int argv,
                                     char *argc[]) {
  msg->prt_txt_terminal(" getting the simulation name ...");
  if (argv == 1) { // no simulation name is entered, read from terminal
    msg->prt_txt_terminal(" no simulaiton name entered.");
    msg->prt_txt_terminal(" enter the simulation name:");
    msg->prt_txt_terminal(
        " Make sure that the input files are in a folder with the same name as "
        "the simulation the simulation name you enter. This folder should be "
        "in the input_files folder.");
    std::cin >> name;
    std::cin.ignore();
    std::string temp = " the input file name: %s", name;
    msg->prt_txt_terminal(temp);
  } else { // a simulation name has entered
    name = argc[1];
    std::string temp = " the input file name: %s", name;
    msg->prt_txt_terminal(temp);
  }
}

void io::init_cls::directories_fn() {

  /**/
  // Open address files
  std::cout << " -opening the address file ...\n";

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
  std::cout << " -reading the address file ...\n";

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

  std::cout << " -creating directories ...\n";

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

void io::init_cls::createFolders_fn() {}