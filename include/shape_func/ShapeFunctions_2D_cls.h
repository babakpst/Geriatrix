
// libraries

// classes
#include "ShapeFunctions_cls.h"

//#ifndef SHAPEFUNCTIONS_2D_CLS_H
//#define SHAPEFUNCTIONS_2D_CLS_H
#pragma once

namespace main_ns {

namespace ShapeFunctions_ns {

// first-order, triangle elements (3-noded) - ShapeFunc_2D_3N
template <class T1, class T2>
class ShapeFunctions_2D_3N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_2D_3N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_2D_3N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_3N

  //~ShapeFunctions_FirstOrder_cls();
};

// second-order, triangle elements (6-noded) - ShapeFunc_2D_6N
template <class T1, class T2>
class ShapeFunctions_2D_6N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_2D_6N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_2D_6N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_6N

  //~ShapeFunctions_FirstOrder_cls();
};

// triangle spectral elment (7-nodes) - ShapeFunc_2D_7N
template <class T1, class T2>
class ShapeFunctions_2D_7N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_2D_7N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_2D_7N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_7N

  //~ShapeFunctions_FirstOrder_cls();
};

// first-order, quadrilateral elements (4-noded) - ShapeFunc_2D_4N
template <class T1, class T2>
class ShapeFunctions_2D_4N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_2D_4N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_2D_4N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_4N

  //~ShapeFunctions_FirstOrder_cls();
};

// second-order, quadrilateral elements (8-noded) - ShapeFunc_2D_8N
template <class T1, class T2>
class ShapeFunctions_2D_8N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_2D_8N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_2D_8N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_8N

  //~ShapeFunctions_FirstOrder_cls();
};

// quadrilateral spectral elment (9-nodes) - ShapeFunc_2D_9N
template <class T1, class T2>
class ShapeFunctions_2D_9N_cls
    : public main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2> {

  // members
  // methods
public:
  ShapeFunctions_2D_9N_cls(T1, T1);

  virtual void ShapeFunctions();               // ShapeFunc_2D_9N
  virtual void DifferentialOfShapeFunctions(); // Dif_ShapeFunc_2D_9N

  //~ShapeFunctions_FirstOrder_cls();
};

} // namespace ShapeFunctions_ns

} // namespace main_ns

//#endif // SHAPEFUNCTIONS_2D_CLS_H
