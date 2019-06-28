

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "../include/discretize_the_domain_cls.h"
#include "../include/reading_the_model_cls.h"

#ifndef VISUALIZATION_H
#define VISUALIZATION_H

namespace main_ns
{

namespace visualization_ns
{

class visualization_cls
{

// members
private:
  std::ofstream OutputMatlab;

  const main_ns::address_ns::address_cls *address;
  const main_ns::model_ns::model_cls *model;
  const main_ns::discretization_ns::discretization_cls *discretized_model;

// methods
public:
  explicit visualization_cls(const main_ns::address_ns::address_cls *,
                             const main_ns::model_ns::model_cls *,
                             const main_ns::discretization_ns::discretization_cls *);
  void MatlabOutput_fn();
};
} // namespace visualization_ns
} // namespace main_ns

#endif // !VISUALIZATION_H