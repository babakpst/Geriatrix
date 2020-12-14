

// classes
#include "../../include/io/Info.h"

io::CInfo::CInfo() {}
io::CInfo::~CInfo() {}

void io::CInfo::getLogfileHandle(std::string &logDir) {

  _logfile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
  try {
    _logfile.open(logDir, std::ios::out);
  } catch (std::ofstream::failure &inputerr) { // here is the catch for opening the input file.
    std::cout << " Error while opening the log file. \n";
    std::cout << " The error message is: " << inputerr.what() << "\n";
  }
};

void io::CInfo::chk() {
  ++_checkpoint;
  std::cout << " checkpoint: " << _checkpoint << " file: " << __FILE__ << " line: " << __LINE__
            << " func: " << __FUNCTION__ << " date: " << __DATE__ << " time: " << __TIME__
            << std::endl;

  _logfile << " checkpoint: " << _checkpoint << " file: " << __FILE__ << " line: " << __LINE__
           << " func: " << __FUNCTION__ << " date: " << __DATE__ << " time: " << __TIME__
           << std::endl;
}

//======= upto here.
void io::CInfo::initiationMessageOnTerminal() const {
  std::cout << "***********************************************************\n";
  std::cout << "*                                                         *\n";
  std::cout << "*                        Geriatrix                        *\n";
  std::cout << "*           numerical solution of wave equation           *\n";
  std::cout << "*                      version: " << std::setprecision(2) << _version
            << "                      *\n";
  std::cout << "*               developer: babak poursartip               *\n";
  std::cout << "*               Date: ???               *\n";
  std::cout << "*               Time: ???               *\n";
  std::cout << "*                                                         *\n";
  std::cout << "***********************************************************\n";
}

void io::CInfo::terminationMessageOnTerminal() const {
  std::cout << "***********************************************************\n";
  std::cout << "*                                                         *\n";
  std::cout << "* End of the successfull simulation                       *\n";
  std::cout << "* Simulation name: ????                                    *\n";
  std::cout << "*               Date: ???               *\n";
  std::cout << "*               Time: ???               *\n";
  std::cout << "* Terminating the execution.                              *\n";
  std::cout << "*                                                         *\n";
  std::cout << "***********************************************************\n";
}

void io::CInfo::prt_txt_terminal(const std::string text) const { std::cout << text << "\n"; }

void io::CInfo::prt_txt_txt_terminal(const std::string text1, const std::string text2) const {
  std::cout << text1 << " " << text2 << "\n";
}

void io::CInfo::prt_int_terminal(const int &num) const {
  std::cout << " The int value is: " << num << "\n";
}

void io::CInfo::prt_txt_int_terminal(const std::string text, const int &num) const {
  std::cout << text << " " << num << "\n";
}

void io::CInfo::prt_txt_flt_terminal(const std::string text, const float &num) const {
  std::cout << text << " " << num << "\n";
}

void io::CInfo::prt_welcome_logfile() const {}
void io::CInfo::prt_success_logfile() const {}
void io::CInfo::prt_txt_txt_logfile(const std::string text1, const std::string text2) const {}

void io::CInfo::prt_txt_logfile(const std::string text) const {}
