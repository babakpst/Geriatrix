
#include "../../include/timekeeper/Time.h"

// ctor ======================================================================
Time::CTime::CTime(std::string name, std::shared_ptr<io::CInfo> info)
    : _name(name), _info(info), CDate(name, info) {
  if (DEBUG)
    _info->txtAndTxtMessageOnTerminal(" Time class initiated: ", _name);
}

Time::CTime::~CTime() {}

// ===========================================================================
void Time::CTime::startTime() {
  if (DEBUG)
    _info->txtAndTxtMessageOnTerminal(" Time class started for: ", _name);
  _start = std::chrono::steady_clock::now();
}

// ===========================================================================
void Time::CTime::endTime() {
  if (DEBUG)
    _info->txtAndTxtMessageOnTerminal(" Time class stopped for: ", _name);
  _end = std::chrono::steady_clock::now();
}

// ===========================================================================
void Time::CTime::elaspedTime() { _elapsedTime = _end - _start; }

// ===========================================================================
std::chrono::steady_clock::duration Time::CTime::getElaspedTime() { return _elapsedTime; }