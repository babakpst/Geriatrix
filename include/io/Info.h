
/*
################################################################################
info_cls: All input/output messages on terminal or on the log file is through
this class.

Developed by: Babak Poursartip

V1.00: 11/03/2020 - class initiated (election day)
V1.00: 11/03/2020 - Initiated: Compiled without error for the first time.

################################################################################
*/

/** @file Info.h

@author Poursartip:Babak:PhD:Wave simulation

@version Revision 1.0

@brief prints messages in files and on terminal.

@details
info_cls: ctor
~info_cls: dtor
welcomeOnTerminal: prints the welcome message on terminal.
successOnTerminal: prints the successful execution message on terminal.
txtOnTerminal: prints a text message on terminal.
txtOnTxtOnTerminal: prints two text messages on terminal.
intOnTerminal: prints an integer on terminal.
txt_intOnTerminal: prints a string followed by an integer.
txt_fltOnTerminal: prints a string followed by a float.

txttoLogfile: prints a text message on the logfile.

chk: prints the checkpoint message on terminal and the log file.


welcometoLogfile: prints the welcome message on terminal.
successtoLogfile: prints the successful execution message on terminal.

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

class CInfo {
private:
  char *_text;
  unsigned int _checkpoint = 0;
  float _version = 1.00;

  std::ofstream _logfile;

public:
  explicit CInfo();
  ~CInfo();

  std::ofstream getLogfileHandle();
  /**<
  get the logfile handler.
  @return fstream
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void welcomeOnTerminal() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void successOnTerminal() const;
  /**<
  prints the successful execution message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void welcometoLogfile() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void successtoLogfile() const;
  /**<
  prints the successful execution message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void txtOnTerminal(const std::string text) const;
  /**<
  prints a text message on terminal.
  @return void
  @param *char: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void txttoLogfile(const std::string text) const;
  /**<
  prints a text message on terminal.
  @return void
  @param *char: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void txtOnTxtOnTerminal(const std::string text1,
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

  void txtOnTxttoLogfile(const std::string text1,
                         const std::string text2) const;
  /**<
  prints a two text messages in the log file.
  @return void
  @param std::string: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void intOnTerminal(const int &num) const;
  /**<
  prints an integer on terminal.
  @return void
  @param &num: an int variable.
  @pre
  -# int number to be printed.
  @post
  -# no output.
  */

  void txt_intOnTerminal(const std::string text, const int &num) const;
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

  void txt_fltOnTerminal(const std::string text, const float &num) const;
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

  /*
  std::cout << " elapsed time: " << input_time.elapsed_time.count()
              << " and in microsecond: "
              << std::chrono::duration_cast<std::chrono::microseconds>(
                     input_time.elapsed_time)
                     .count()
              << " in nanoseconds: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(
                     input_time.elapsed_time)
                     .count()
              << " in seconds: "
              << std::chrono::duration_cast<std::chrono::seconds>(
                     input_time.elapsed_time)
                     .count()
              << "\n";
  */
};
} // namespace io