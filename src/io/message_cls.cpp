
/** @file message_cls.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief prints messages in files and on terminal.

@details
message_cls: ctor
~message_cls: dtor
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
#include "../../include/io/message_cls.h"

io::message_cls::message_cls() {}
io::message_cls::~message_cls() {}

void io::message_cls::prt_welcome_terminal() const {
  std::cout << "***********************************************************\n";
  std::cout << "*                                                         *\n";
  std::cout << "*                        Geriatrix                        *\n";
  std::cout << "*           numerical solution of wave equation           *\n";
  std::cout << "*                      version: " << std::setprecision(2)
            << version << "                      *\n";
  std::cout << version << std::endl;
  std::cout << "*               developer: babak poursartip               *\n";
  std::cout << "*                                                         *\n";
  std::cout << "***********************************************************\n";
}

void io::message_cls::prt_success_terminal() const {
  std::cout << "***********************************************************\n";
  std::cout << "*                                                         *\n";
  std::cout << "* The end of successfull simulation                       *\n";
  std::cout << "* Simulation name: TBC                                    *\n";
  std::cout << "* Terminating the execution.                              *\n";
  std::cout << "*                                                         *\n";
  std::cout << "***********************************************************\n";
}
void io::message_cls::prt_txt_terminal(const char *text) const {
  std::cout << text << "\n";
}

void io::message_cls::prt_int_terminal(const int &num) const {
  std::cout << " The int value is: " << num << "\n";
}

void io::message_cls::prt_txt_int_terminal(const char *text,
                                           const int &num) const {
  std::cout << text << " " << num << "\n";
}

void io::message_cls::prt_txt_flt_terminal(const char *text,
                                           const float &num) const {
  std::cout << text << " " << num << "\n";
}

void io::message_cls::chk() {
  ++checkpoint;
  std::cout << " checkpoint: " << checkpoint << " file: " << __FILE__
            << " line: " << __LINE__ << " func: " << __FUNCTION__
            << " date: " << __DATE__ << " time: " << __TIME__ << std::endl;
}

void io::message_cls::prt_welcome_log() const {}
void io::message_cls::prt_success_log() const {}
