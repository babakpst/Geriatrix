
/** @file info_cls.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief prints messages in files and on terminal.

@details
info_cls: ctor
~info_cls: dtor
prt_welcome_terminal: prints the welcome message on terminal.
prt_success_terminal: prints the successful execution message on terminal.
prt_welcome_log: prints the welcome message on terminal.
prt_success_log: prints the successful execution message on terminal.
prt_txt_terminal: prints a text message on terminal.
prt_int_terminal: prints an integer on terminal.
prt_txt_int_terminal: prints a string followed by an integer.
prt_txt_flt_terminal: prints a string followed by a float.
chk: prints the checkpoint message and its location.

@date Tuesday, Nov 03, 2020
*/

// classes
#include "../../include/io/Info.h"

io::CInfo::CInfo() {}
io::CInfo::~CInfo() {}

std::ofstream io::CInfo::getLogfileHandle() { return _logfile; };

void io::CInfo::initiationMessageToTerminal() const {
  std::cout << "***********************************************************\n";
  std::cout << "*                                                         *\n";
  std::cout << "*                        Geriatrix                        *\n";
  std::cout << "*           numerical solution of wave equation           *\n";
  std::cout << "*                      version: " << std::setprecision(2)
            << _version << "                      *\n";
  std::cout << _version << std::endl;
  std::cout << "*               developer: babak poursartip               *\n";

  std::cout << "*                                                         *\n";
  std::cout << "***********************************************************\n";
}

void io::CInfo::prt_success_terminal() const {
  std::cout << "***********************************************************\n";
  std::cout << "*                                                         *\n";
  std::cout << "* End of the successfull simulation                       *\n";
  std::cout << "* Simulation name: TBC                                    *\n";
  std::cout << "* Terminating the execution.                              *\n";

  std::cout << "*                                                         *\n";
  std::cout << "***********************************************************\n";
}

void io::CInfo::prt_txt_terminal(const std::string text) const {
  std::cout << text << "\n";
}

void io::CInfo::prt_txt_txt_terminal(const std::string text1,
                                     const std::string text2) const {
  std::cout << text1 << " " << text2 << "\n";
}

void io::CInfo::prt_int_terminal(const int &num) const {
  std::cout << " The int value is: " << num << "\n";
}

void io::CInfo::prt_txt_int_terminal(const std::string text,
                                     const int &num) const {
  std::cout << text << " " << num << "\n";
}

void io::CInfo::prt_txt_flt_terminal(const std::string text,
                                     const float &num) const {
  std::cout << text << " " << num << "\n";
}

void io::CInfo::chk() {
  ++_checkpoint;
  std::cout << " checkpoint: " << _checkpoint << " file: " << __FILE__
            << " line: " << __LINE__ << " func: " << __FUNCTION__
            << " date: " << __DATE__ << " time: " << __TIME__ << std::endl;

  _logfile << " checkpoint: " << _checkpoint << " file: " << __FILE__
           << " line: " << __LINE__ << " func: " << __FUNCTION__
           << " date: " << __DATE__ << " time: " << __TIME__ << std::endl;
}

void io::CInfo::prt_welcome_logfile() const {}
void io::CInfo::prt_success_logfile() const {}
void io::CInfo::prt_txt_txt_logfile(const std::string text1,
                                    const std::string text2) const {}

void io::CInfo::prt_txt_logfile(const std::string text) const {}
