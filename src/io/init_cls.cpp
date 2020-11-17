
#include "../../include/io/init_cls.h"
#include "../../include/io/info_cls.h"

// ctor ======================================================================
io::init_cls::init_cls(std::unique_ptr<io::info_cls> &info) {
  info->prt_txt_terminal(" initializing the directories ...");
}

// ===========================================================================
void io::init_cls::simulationName_fn(std::unique_ptr<io::info_cls> &info,
                                     const int argv, char *argc[]) {

  info->prt_txt_terminal(" getting the simulation name ...");

  if (argv == 1) { // no simulation name is entered, read from terminal
    info->prt_txt_terminal(" no simulaiton name entered.");
    info->prt_txt_terminal(" enter the simulation name:");
    info->prt_txt_terminal(
        " Make sure that the input files are in a folder with the same name as "
        "the simulation the simulation name you enter. This folder should be "
        "in the input_files folder.");
    std::cin >> name;
    std::cin.ignore();
    std::string temp = " the input file name: %s", name;
    info->prt_txt_terminal(temp);
  } else { // a simulation name has entered
    name = argc[1];
    std::string temp = " the input file name: %s", name;
    info->prt_txt_terminal(temp);
  }
}

// ===========================================================================
void io::init_cls::directories_fn(std::unique_ptr<io::info_cls> &info) {

  inDir = "../input_files/" + name;
  outDir = "../output_files/" + name;
  logDir = "../output_files/" + name + "/" + name + ".log";

  // Final Directories
  std::cout << " Input dir:  " << inDir << "\n";
  std::cout << " Output dir: " << outDir << "\n";
  std::cout << " log file:   " << logDir << "\n";
}

// ===========================================================================
void io::init_cls::createFolders_fn(std::unique_ptr<io::info_cls> &info) {
  info->prt_txt_terminal(" creating output folders/files ... ");

  info->prt_txt_terminal(" creating the log file ...");
  info->get_logfile().exceptions(std::ifstream::failbit |
                                 std::ifstream::badbit);
  try {
    info->get_logfile().open(logDir, std::ios::out);
  } catch (std::ifstream::failure &inputerr) {
    info->prt_txt_terminal(" Error while opening the log file.");
    info->prt_txt_terminal(
        " Please make sure the input file is in the cpp folder.");
    info->prt_txt_txt_terminal(" The error message is:", inputerr.what());
  }

  boost::filesystem::path dir(outDir);
  if (boost::filesystem::create_directory(dir)) {
    info->prt_txt_terminal(" output folder created!");
  } else
    info->prt_txt_terminal(" output folder already exists!");
}
