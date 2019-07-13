
// libraries

// classes
#include "../include/ShapeFunctions_cls.h"

#ifndef SHAPEFUNCTIONS_2D_CLS_H
#define SHAPEFUNCTIONS_2D_CLS_H

namespace main_ns {

namespace ShapeFunctions_ns {

// first-order, triangle elements (3-noded) - ShapeFunc_2D_3N
class ShapeFunctions_2D_3N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls {

  // members
  // methods
public:
  ShapeFunctions_2D_3N_cls(int, int);

  virtual void ShapeFunctions();               // ShapeFunc_2D_3N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_3N

  //~ShapeFunctions_FirstOrder_cls();
};

// second-order, triangle elements (6-noded) - ShapeFunc_2D_6N

// triangle spectral elment (7-nodes) - ShapeFunc_2D_7N

// first-order, quadrilateral elements (4-noded) - ShapeFunc_2D_4N

// second-order, quadrilateral elements (8-noded) - ShapeFunc_2D_8N

// quadrilateral spectral elment (9-nodes) - ShapeFunc_2D_9N

} // namespace ShapeFunctions_ns

} // namespace main_ns

#endif // SHAPEFUNCTIONS_2D_CLS_H
