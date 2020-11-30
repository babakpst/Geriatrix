
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

getLogfileHandle: creating the log file

initiationMessageToTerminal: prints the welcome message on terminal.
terminationMessageToTerminal: prints the successful execution message on
terminal.

txtOnTerminal: prints a text message on terminal.
txtAndTxtMessageOnTerminal: prints two text messages on terminal.
intOnTerminal: prints an integer on terminal.
txtAndIntOnTerminal: prints a string followed by an integer on terminal.
txtAndFloatOnTerminal: prints a string followed by a float on terminal.
txtAndDoubleOnTerminal: prints a string followed by a double on terminal.


initiationMessageToLogfile: prints the welcome message on terminal.
terminationMessageToLogfile: prints the successful execution message on
terminal.

txtOnLogfile: prints a text message on the logfile.
txtAndTxtMessageOnLogfile: prints two text messages on logfile.
intOnLogfile: prints an integer on terminal.
txtAndIntOnLogfile: prints a string followed by an integer on logfile.
txtAndFloatOnLogfile: prints a string followed by a float on logfile.
txtAndDoubleOnLogfile: prints a string followed by a double on logfile.

chk: prints the checkpoint message on terminal and the log file.

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

  void initiationMessageToTerminal() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void terminationMessageToTerminal() const;
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

  void txtAndTxtMessageOnTerminal(const std::string text1,
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

  void txtAndIntOnTerminal(const std::string text, const int &num) const;
  /**<
  prints a string followed by an integer on terminal.
  @return void
  @param
  char *text: a char variable.
  int &num: an int variable.
  @pre
  -# int number to be printed.
  @post
  -# no output.
  */

  void txtAndFloatOnTerminal(const std::string text, const float &num) const;
  /**<
  prints a string followed by a float  on terminal.
  @return void
  @param
  char *text: a char variable.
  float &num: a float variable.
  @pre
  -# float number to be printed.
  @post
  -# no output.
  */

  void txtAndDoubleOnTerminal(const std::string text, const float &num) const;
  /**<
  prints a string followed by a double on terminal.
  @return void
  @param
  char *text: a char variable.
  float &num: a float variable.
  @pre
  -# float number to be printed.
  @post
  -# no output.
  */

  void InitiationMessageToLogfile() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void TeminationMessageToLogfile() const;
  /**<
  prints the successful execution message on terminal.
  @return void
  @param void
  @pre
  -# text
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

  void txtAndTxtMessageOnLogfile(const std::string text1,
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

  //========================================================
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