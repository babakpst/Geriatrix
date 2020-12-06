

#include "../../include/timing/Date.h"

CDate::CDate() { std::cout << " Date class initiated \n"; }

std::string CDate::getDate() {
  std::time_t temp = std::time(NULL);
  return std::ctime(&temp);
}
