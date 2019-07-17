
// libraries

// classes
#include "../include/ShapeFunctions_cls.h"
#include "../include/ShapeFunctions_1D_cls.h"

// 2D, triangle element
template <class T1, class T2>
main_ns::ShapeFunctions_ns::ShapeFunctions_2D_3N_cls::ShapeFunctions_2D_3N_cls<
    T1, T2>(T1 aNInt, T1 aNNode)
    : main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>(aNInt, aNNode) {}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         first-order element: element (linear- 3-noded) at the x1 point.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/16/2019 - Subroutine initiated.
V0.01: 07/17/2019 - Initiated: Compiled without error for the first time.

###################################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_3N_cls<
    T1, T2>::ShapeFunctions() { // ShapeFunc_2D_3N
  Fn[0] = 1.0 - r - s;
  Fn[1] = r;
  Fn[2] = s;
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         first-order element: element (linear- 3-noded) at the x1, x2 point.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/16/2019 - Subroutine initiated.
V0.01: 07/16/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_1D_2N_cls<
    T1, T2>::DifferentialOfShapeFunctions() {
  DFXI[0] = {-0.5};
  DFXI[1] = {+0.5};

  DFXI[0][0] = {-1.0};
  DFXI[0][1] = {-1.0};
  DFXI[1][0] = {+1.0};
  DFXI[1][1] = {0.0};
  DFXI[2][0] = {0.0};
  DFXI[2][1] = {+1.0};
}
