

#include "../include/ShapeFunctions_FirstOrder_cls.h"
#include "../include/ShapeFunctions_cls.h"

main_ns::ShapeFunctions_ns::ShapeFunctions_FirstOrder_cls::
    ShapeFunctions_FirstOrder_cls(int aNInt, int aNNode)
    : main_ns::ShapeFunctions_ns::ShapeFunctions_cls(aNInt, aNNode)
{
}

/*
###################################################################################################
Purpose: This function computes the value of the shape functions of a first order 
element (linear- 2-noded) at the x1 point.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	

================================= V E R S I O N ===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 06/02/2018 - Initiated: Compiled without error for the first time.

###################################################################################################
*/

void main_ns::ShapeFunctions_ns::ShapeFunctions_FirstOrder_cls::ShapeFunctions()
{ //ShapeFunc_1D_2N
  Fn[0] = 0.5 * (1.0 - x1);
  Fn[1] = 0.5 * (1.0 + x1);
}

/*
###################################################################################################
Purpose: This function computes the value of the derivative of shape functions of a first order 
element (linear- 2-noded) at the x1 point.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	

================================= V E R S I O N ===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 06/02/2018 - Initiated: Compiled without error for the first time.

###################################################################################################
*/
void main_ns::ShapeFunctions_ns::ShapeFunctions_FirstOrder_cls::DifferentialOfShapeFunctions()
{
  DFXI[0] = {-0.5};
  DFXI[1] = {+0.5};
}
