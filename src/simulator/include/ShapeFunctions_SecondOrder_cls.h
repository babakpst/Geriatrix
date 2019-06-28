

#include "../include/ShapeFunctions_cls.h"

#ifndef SHAPEFUNCTIONS_SECONDORDER_CLS_H
#define SHAPEFUNCTIONS_SECONDORDER_CLS_H

namespace main_ns
{

namespace ShapeFunctions_ns
{

class ShapeFunctions_SecondOrder_cls : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls
{

  // members
  // methods
public:
  ShapeFunctions_SecondOrder_cls(int, int);

  virtual void ShapeFunctions();               // ShapeFunc_1D_3N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_1D_3N

  //~ShapeFunctions_SecondOrder_cls();
};

} // namespace ShapeFunctions_ns

} // namespace main_ns

#endif
