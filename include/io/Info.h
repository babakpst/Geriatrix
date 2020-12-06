
/*
################################################################################
info_cls: All input/output messages on terminal or to the log file is through
this class.

Developed by: Babak Poursartip

V1.00: 11/03/2020 - class initiated (election day)
V1.00: 12/05/2020 - Initiated: Compiled without error for the first time.

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
chk: prints the checkpoint message on terminal and the log file.

initiationMessageOnTerminal: prints the welcome message on terminal.
terminationMessageOnTerminal: prints the successful execution message to the
logfile.

txtOnTerminal: prints a text message on terminal.
txtAndTxtMessageOnTerminal: prints two text messages on terminal.
intOnTerminal: prints an integer on terminal.
txtAndIntOnTerminal: prints a string followed by an integer on terminal.
txtAndFloatOnTerminal: prints a string followed by a float on terminal.
txtAndDoubleOnTerminal: prints a string followed by a double on terminal.

initiationMessageToLogfile: prints the welcome message to the logfile.
terminationMessageToLogfile: prints the successful execution message to file.

txtToLogfile: prints a text message to the logfile.
txtAndTxtMessageToLogfile: prints two text messages to the logfile.
intToLogfile: prints an integer to the logfile.
txtAndIntToLogfile: prints a string followed by an integer to the logfile.
txtAndFloatToLogfile: prints a string followed by a float to the logfile.
txtAndDoubleToLogfile: prints a string followed by a double to the logfile.

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
  unsigned int _checkpoint = 0;
  float _version = 1.00;

  std::ofstream _logfile;

public:
  explicit CInfo();
  ~CInfo();

  void getLogfileHandle(std::string &logDir);
  /**<
  get the logfile handler.
  @return fstream
  @param void
  @pre
  -# text
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

  void initiationMessageOnTerminal() const;
  /**<
  prints the welcome message on terminal.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void terminationMessageOnTerminal() const;
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

  void txtAndTxtMessageOnTerminal(const std::string text1, const std::string text2) const;
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
  prints a string followed by a double to the logfile.
  @return void
  @param
  char *text: a char variable.
  float &num: a float variable.
  @pre
  -# float number to be printed.
  @post
  -# no output.
  */

  void initiationMessageToLogfile() const;
  /**<
  prints the welcome message to the logfile.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void terminationMessageToLogfile() const;
  /**<
  prints the successful execution message to the logfile.
  @return void
  @param void
  @pre
  -# text
  @post
  -# no output.
  */

  void txtToLogfile(const std::string text) const;
  /**<
  prints a text message to the logfile.
  @return void
  @param *char: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void txtAndTxtMessageToLogfile(const std::string text1, const std::string text2) const;
  /**<
  prints a two text messages to the logfile.
  @return void
  @param std::string: a string to be printed.
  @pre
  -# text contains a string to be printed.
  @post
  -# no output.
  */

  void intToLogfile(const int &num) const;
  /**<
  prints an integer to the logfile.
  @return void
  @param &num: an int variable.
  @pre
  -# int number to be printed.
  @post
  -# no output.
  */

  void txtAndIntToLogfile(const std::string text, const int &num) const;
  /**<
  prints a string followed by an integer to the logfile.
  @return void
  @param
  char *text: a char variable.
  int &num: an int variable.
  @pre
  -# int number to be printed.
  @post
  -# no output.
  */

  void txtAndFloatToLogfile(const std::string text, const float &num) const;
  /**<
  prints a string followed by a float  to the logfile.
  @return void
  @param
  char *text: a char variable.
  float &num: a float variable.
  @pre
  -# float number to be printed.
  @post
  -# no output.
  */

  void txtAndDoubleToLogfile(const std::string text, const float &num) const;
  /**<
  prints a string followed by a double to the logfile.
  @return void
  @param
  char *text: a char variable.
  float &num: a float variable.
  @pre
  -# float number to be printed.
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