
/*
################################################################################
info_cls: All input/output messages on terminal or on the log file is through
this class.

Developed by: Babak Poursartip

V1.00: 11/03/2020 - class initiated (election day)
V1.00: 11/03/2020 - Initiated: Compiled without error for the first time.

################################################################################
*/

/** @file info_cls.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief prints messages in files and on terminal.

@details
info_cls: ctor
~info_cls: dtor
prt_welcome_terminal: prints the welcome message on terminal.
prt_success_terminal: prints the successful execution message on terminal.
prt_txt_terminal: prints a text message on terminal.
prt_txt_txt_terminal: prints two text messages on terminal.
prt_int_terminal: prints an integer on terminal.
prt_txt_int_terminal: prints a string followed by an integer.
prt_txt_flt_terminal: prints a string followed by a float.
chk: prints the checkpoint message on terminal and the log file.


prt_welcome_log: prints the welcome message on terminal.
prt_success_log: prints the successful execution message on terminal.
@date Tuesday, Nov 03, 2020
*/

// libraries
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

// classes

#pragma once

namespace io {

class info_cls {
private:
  char *text;
  unsigned int checkpoint = 0;
  float version = 1.00;

  std::ofstream logfile;

public:
  explicit info_cls();
  ~info_cls();

  std::ofstream get_logfile();
  /**<
  get the logfile handler.
  @return fstream
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void prt_welcome_terminal() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void prt_success_terminal() const;
  /**<
  prints the successful execution message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void prt_welcome_log() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void prt_success_log() const;
  /**<
  prints the successful execution message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void prt_txt_terminal(const std::string text) const;
  /**<
  prints a text message on terminal.
  @return void
  @param *char: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void prt_txt_txt_terminal(const std::string text1,
                            const std::string text2) const;
  /**<
  prints a two text messages on terminal.
  @return void
  @param std::string: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void prt_txt_txt_log(const std::string text1, const std::string text2) const;
  /**<
  prints a two text messages in the log file.
  @return void
  @param std::string: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void prt_int_terminal(const int &num) const;
  /**<
  prints an integer on terminal.
  @return void
  @param &num: an int variable.
  @pre
  -# int number to be printed.
  @post
  -# no output.
  */

  void prt_txt_int_terminal(const std::string text, const int &num) const;
  /**<
  prints a string followed by an integer.
  @return void
  @param
  char *text: a char variable.
  int &num: an int variable.
  @pre
  -# int number to be printed.
  @post
  -# no output.
  */

  void prt_txt_flt_terminal(const std::string text, const float &num) const;
  /**<
  prints a string followed by a float.
  @return void
  @param
  char *text: a char variable.
  float &num: a float variable.
  @pre
  -# float number to be printed.
  @post
  -# no output.
  */

  void chk();
  /**<
  prints the checkpoint message on terminal and the log file.
  @return void
  @param
  num checkpoint.
  @pre
  -# int checkpoint be printed.
  @post
  -# no output.
  */
};
} // namespace io