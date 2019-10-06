
// libraries

// classes
#include "../include/ShapeFunctions_cls.h"

#ifndef SHAPEFUNCTIONS_1D_CLS_H
#define SHAPEFUNCTIONS_1D_CLS_H

namespace main_ns {

namespace ShapeFunctions_ns {

// first-order elements
template <class T1, class T2>
class ShapeFunctions_1D_2N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_1D_2N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_1D_2N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_1D_2N

  //~ShapeFunctions_FirstOrder_cls();
};

// second-order elements
template <class T1, class T2>
class ShapeFunctions_1D_3N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_1D_3N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_1D_3N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_1D_3N

  //~ShapeFunctions_SecondOrder_cls();
};

} // namespace ShapeFunctions_ns

} // namespace main_ns

#endif
