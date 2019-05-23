

#include <math.h>
#include <iostream>
#include <vector>

#ifndef SHAPEFUNCTIONS_CLS_H
#define SHAPEFUNCTIONS_CLS_H

namespace main_ns
{

namespace ShapeFunctions_ns
{

class ShapeFunctions_cls
{
  // members

public:
  int NInt;  // Number of Integration points (quadrature)
  int NNode; // Number of nodes in the element

  double x1;    // Location of the integration

  std::vector<double> Fn;   // Shape function based on the number of nodes
  std::vector<double> DFXI; // The differential of the shape function
  std::vector<double> XInt; // ABSCISSAE of the integration points
  std::vector<double> WInt; // WEIGHTS of the integration points  

  // methods
public:
  ShapeFunctions_cls(int, int);

  void Retrieving_Gauss_Points_fn();

  virtual void ShapeFunctions(void) = 0;
  virtual void DifferentialOfShapeFunctions(void) = 0;

  virtual ~ShapeFunctions_cls();
};
} // namespace ShapeFunctions_ns
} // namespace main_ns

#endif
