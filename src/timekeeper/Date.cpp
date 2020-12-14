
#include "../../include/timekeeper/Date.h"

Time::CDate::CDate(std::string name, std::shared_ptr<io::CInfo> info) : _name(name), _info(info) {
  if (DEBUG) {
    _info->txtAndTxtMessageOnTerminal(" Date class initiated: ", _name);
  }
}

void Time::CDate::setDate() {
  if (DEBUG)
    _info->txtAndTxtMessageOnTerminal(" Date set for: ", _name);
  std::time_t temp = std::time(NULL);
  _date = std::ctime(&temp);
}

std::string Time::CDate::getDate() { return _date; }
