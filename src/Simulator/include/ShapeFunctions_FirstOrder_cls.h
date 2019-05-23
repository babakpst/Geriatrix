
#include "../include/ShapeFunctions_cls.h"

#ifndef SHAPEFUNCTIONS_FIRSTORDER_CLS_H
#define SHAPEFUNCTIONS_FIRSTORDER_CLS_H

namespace main_ns
{

namespace ShapeFunctions_ns
{

class ShapeFunctions_FirstOrder_cls : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls
{

  // members
  // methods
public:
  ShapeFunctions_FirstOrder_cls(int, int);

  virtual void ShapeFunctions();               // ShapeFunc_1D_2N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_1D_2N

  //~ShapeFunctions_FirstOrder_cls();
};
} // namespace ShapeFunctions_ns

} // namespace main_ns

#endif
