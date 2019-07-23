
// libraries

// classes
#include "../include/ShapeFunctions_cls.h"
#include "../include/ShapeFunctions_1D_cls.h"

// 2D, triangle element, 3 nodes
template <class T1, class T2>
main_ns::ShapeFunctions_ns::ShapeFunctions_2D_3N_cls::ShapeFunctions_2D_3N_cls<
    T1, T2>(T1 aNInt, T1 aNNode)
    : main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>(aNInt, aNNode, 2) {
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         first-order triangle element3-noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/16/2019 - Subroutine initiated.
V0.01: 07/17/2019 - Initiated: Compiled without error for the first time.

################################################################################
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
         first-order triangle element, 3-noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/16/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_3N_cls<
    T1, T2>::DifferentialOfShapeFunctions() {
  DFXI[0] = {-1.0}; // DFXI[0][0]
  DFXI[1] = {-1.0}; // DFXI[0][1]
  DFXI[2] = {+1.0}; // DFXI[1][0]
  DFXI[3] = {0.0};  // DFXI[1][1]
  DFXI[4] = {0.0};  // DFXI[2][0]
  DFXI[5] = {+1.0}; //  DFXI[2][1]
}

// 2D, triangle element, 6 nodes
template <class T1, class T2>
main_ns::ShapeFunctions_ns::ShapeFunctions_2D_6N_cls::ShapeFunctions_2D_6N_cls<
    T1, T2>(T1 aNInt, T1 aNNode)
    : main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>(aNInt, aNNode, 2) {
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         second-order triangle element, 6 noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/22/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_6N_cls<
    T1, T2>::ShapeFunctions() { // ShapeFunc_2D_6N
  Fn[0] = (1.0 - r - s) * (1.0 - 2.0 * r - 2.0 * s);
  Fn[1] = r * (2.0 * r - 1.0);
  Fn[2] = s * (2.0 * s - 1.0);
  Fn[3] = 4.0 * r * (1.0 - r - s);
  Fn[4] = 4.0 * r * s;
  Fn[5] = 4.0 * s * (1.0 - r - s);
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         second-order triangle element, 6 noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/22/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_6N_cls<
    T1, T2>::DifferentialOfShapeFunctions() {
  DFXI[0] = -3.0 + 4.0 * r + 4.0 * s;  // DFXI(1, 1)
  DFXI[1] = -3.0 + 4.0 * r + 4.0 * s;  // DFXI(1, 2)
  DFXI[2] = +4.0 * r - 1.0;            // DFXI(2, 1)
  DFXI[3] = 0.0;                       // DFXI(2, 2)
  DFXI[4] = 0.0;                       // DFXI(3, 1)
  DFXI[5] = +4.0 * s - 1.0;            // DFXI(3, 2)
  DFXI[6] = +4.0 - 8.0 * r - 4.0 * s;  // DFXI(4, 1)
  DFXI[7] = -4.0 * r;                  // DFXI(4, 2)
  DFXI[8] = +4.0 * s;                  // DFXI(5, 1)
  DFXI[9] = +4.0 * r;                  // DFXI(5, 2)
  DFXI[10] = -4.0 * s;                 // DFXI(6, 1)
  DFXI[11] = +4.0 - 4.0 * r - 8.0 * s; // DFXI(6, 2)
}

// 2D, triangle element, 7 nodes
template <class T1, class T2>
main_ns::ShapeFunctions_ns::ShapeFunctions_2D_7N_cls::ShapeFunctions_2D_7N_cls<
    T1, T2>(T1 aNInt, T1 aNNode)
    : main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>(aNInt, aNNode, 2) {
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         second-order triangle element, 7 noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/22/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_7N_cls<
    T1, T2>::ShapeFunctions() { // ShapeFunc_2D_7N
  Fn[0] = 1.0 - 3.0 * (r + s) + 2.0 * (r * r + s * s) + 7.0 * r * s -
          3.0 * r * s * (r + s);
  Fn[1] = r * (-1.0 + 2.0 * r + 3.0 * s - 3.0 * s * (r + s));
  Fn[2] = s * (-1.0 + 2.0 * s + 3.0 * r - 3.0 * r * (r + s));
  Fn[3] = 4.0 * r * (1.0 - r - 4.0 * s + 3.0 * s * (r + s));
  Fn[4] = 4.0 * r * s * (-2.0 + 3.0 * (r + s));
  Fn[5] = 4.0 * s * (1.0 - 4.0 * r - s + 3.0 * r * (r + s));
  Fn[6] = 27.0 * r * s * (1.0 - r - s);
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         second-order triangle element, 7 noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/22/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_7N_cls<
    T1, T2>::DifferentialOfShapeFunctions() {
  DFXI[0] = -3.0 + 4.0 * r + 7.0 * s - 6.0 * r * s - 3.0 * s * s; // DFXI(1, 1)
  DFXI[1] = -3.0 + 4.0 * s + 7.0 * r - 6.0 * r * s - 3.0 * r * r; // DFXI(1, 2)
  DFXI[2] = -1.0 + 4.0 * r + 3.0 * s - 6.0 * r * s - 3.0 * s * s; // DFXI(2, 1)
  DFXI[3] = 3.0 * r * (1.0 - r - 2.0 * s);                        // DFXI(2, 2)
  DFXI[4] = 3.0 * s * (1.0 - s - 2.0 * r);                        // DFXI(3, 1)
  DFXI[5] = -1.0 + 3.0 * r + 4.0 * s - 3.0 * r * r - 6.0 * r * s; // DFXI(3, 2)
  DFXI[6] =
      4.0 * (1.0 - 2.0 * r - 4.0 * s + 6.0 * r * s + 3.0 * s * s); // DFXI(4, 1)
  DFXI[7] = 4.0 * r * (-4.0 + 3.0 * r + 6.0 * s);                  // DFXI(4, 2)
  DFXI[8] = 4.0 * s * (-2.0 + 6.0 * r + 3.0 * s);                  // DFXI(5, 1)
  DFXI[9] = 4.0 * r * (-2.0 + 6.0 * s + 3.0 * r);                  // DFXI(5, 2)
  DFXI[10] = 4.0 * s * (-4.0 + 6.0 * r + 3.0 * s);                 // DFXI(6, 1)
  DFXI[11] =
      4.0 * (1.0 - 4.0 * r - 2.0 * s + 3.0 * r * r + 6.0 * r * s); // DFXI(6, 2)
  DFXI[12] = 27.0 * s * (1.0 - 2.0 * r - s);                       // DFXI(7, 1)
  DFXI[13] = 27.0 * r * (1.0 - r - 2.0 * s);                       // DFXI(7, 2)
}

// 2D, quadrilateral element, 4 nodes
template <class T1, class T2>
main_ns::ShapeFunctions_ns::ShapeFunctions_2D_4N_cls::ShapeFunctions_2D_4N_cls<
    T1, T2>(T1 aNInt, T1 aNNode)
    : main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>(aNInt, aNNode, 2) {
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         first-order quadrilateral element, 4 noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/22/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_4N_cls<
    T1, T2>::ShapeFunctions() { // ShapeFunc_2D_4N
  Fn[0] = (1.0 + x1) * (1.0 - x2) * 0.25;
  Fn[1] = (1.0 + x1) * (1.0 + x2) * 0.25;
  Fn[2] = (1.0 - x1) * (1.0 + x2) * 0.25;
  Fn[3] = (1.0 - x1) * (1.0 - x2) * 0.25;
}

/*
################################################################################
Purpose: This function computes the derivative of shape functions for a 2D,
         first-order quadrilateral element, 4 noded.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

========================= V E R S I O N ========================================
V0.00: 07/22/2019 - Subroutine initiated.
V0.01: 07/22/2019 - Initiated: Compiled without error for the first time.

################################################################################
*/

template <class T1, class T2>
void main_ns::ShapeFunctions_ns::ShapeFunctions_2D_4N_cls<
    T1, T2>::DifferentialOfShapeFunctions() {
  DFXI[0] = +(1.0 - x2) * 0.25; // DFXI ( 1 , 1 )
  DFXI[1] = -(1.0 + x1) * 0.25; // DFXI ( 1 , 2 )
  DFXI[2] = +(1.0 + x2) * 0.25; // DFXI ( 2 , 1 )
  DFXI[3] = +(1.0 + x1) * 0.25; // DFXI ( 2 , 2 )
  DFXI[4] = -(1.0 + x2) * 0.25; // DFXI ( 3 , 1 )
  DFXI[5] = +(1.0 - x1) * 0.25; // DFXI ( 3 , 2 )
  DFXI[6] = -(1.0 - x2) * 0.25; // DFXI ( 4 , 1 )
  DFXI[7] = -(1.0 - x1) * 0.25; // DFXI ( 4 , 2 )
}
