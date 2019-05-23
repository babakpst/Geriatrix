
// include files
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

#include "../include/reading_the_model_cls.h"

#ifndef DISCRETIZATION_H
#define DISCRETIZATION_H

namespace main_ns
{
namespace discretization_ns
{

class discretization_cls
{

  // members
private:
  const main_ns::model_ns::model_cls *model;

public:
  int NEqM; // number of Equations (Modified i.e. after applying essential boundary conditions)

  std::vector<int> MTel;  // material type of each Element

  int **INod; // node connectivity
  int **ID;   // identity
  double **XYZ; // node coordinates

  std::vector<int> Nodal_History; // a vector that holds the node no. to record the history of displc

  std::vector<int> NoBndry_DRM;   // a vector that holds the node numbers on the DRM boundary
  
  std::vector<int> NoLayer_DRM;   // a vector that holds the node numbers on the DRM layer

  // methods
public:
  explicit discretization_cls(const main_ns::model_ns::model_cls *);
  void Discretization();
  virtual ~discretization_cls();

}; // class discretization_cls
} // namespace discretization_ns
} // namespace main_ns

#endif
