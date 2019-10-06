
// libraries
#include <math.h>
#include <iostream>
#include <vector>

// classes

#ifndef SHAPEFUNCTIONS_CLS_H
#define SHAPEFUNCTIONS_CLS_H

namespace main_ns {

namespace ShapeFunctions_ns {

// this class is the parent class for all shape funciton classes
// T1: integer, T2: double precistion
template <class T1, class T2> class ShapeFunctions_cls {

  // members
public:
  T1 NInt;  // Number of Integration points (quadrature)
  T1 NNode; // Number of nodes in the element
  T1 NDim;  // The dimension of the model

  T2 x1; // Location of the integration, for 1D and 2D elements
  T2 x2; // Location of the integration, for 2D quadrilateral elements

  T2 r; // Location of the integration, for 2D triangle elements
  T2 s; // Location of the integration, for 2D triangle elements

  std::vector<T2> Fn;   // Shape function based on the number of nodes
  std::vector<T2> DFXI; // The differential of the shape function
  std::vector<T2> XInt; // ABSCISSAE of the integration points
  std::vector<T2> WInt; // WEIGHTS of the integration points

  // methods
public:
  ShapeFunctions_cls(T1, T1, T1);

  void Retrieving_Gauss_Points_fn();

  virtual void ShapeFunctions(void) = 0;
  virtual void DifferentialOfShapeFunctions(void) = 0;

  virtual ~ShapeFunctions_cls();
};
} // namespace ShapeFunctions_ns
} // namespace main_ns

#endif // SHAPEFUNCTIONS_CLS_H
