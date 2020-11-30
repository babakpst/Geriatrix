
#include "../../include/timing/Time.h"

// ctor ======================================================================
timing::CTime::CTime(std::string name, std::shared_ptr<io::CInfo> info,
                     std::shared_ptr<CDate> date)
    : _name(name), _info(info), _date(date) {
  std::string temp = _date->getDate();
  _info->prt_txt_terminal(" Timing class for " + _name +
                          " started at: " + temp);
  info->prt_txt_logfile("timing class for " + name + " started at: " + temp);
}

timing::CTime::~CTime() {}

// ===========================================================================
void timing::CTime::startTime() { _start = std::chrono::steady_clock::now(); }

// ===========================================================================
void timing::CTime::endTime() { _end = std::chrono::steady_clock::now(); }

// ===========================================================================
void timing::CTime::elaspedTime() { _elapsedTime = _end - _start; }

// ===========================================================================
std::chrono::steady_clock::duration timing::CTime::getElaspedTime() {
  return _elapsedTime;
}