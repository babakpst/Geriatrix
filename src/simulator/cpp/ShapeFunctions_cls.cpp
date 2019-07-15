
// libraries

// classes
#include "../include/ShapeFunctions_cls.h"

template <class T1, class T2>
main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>::ShapeFunctions_cls(
    T1 NInt, T1 NNode)
    : NInt(NInt), NNode(NNode), Fn(NNode), DFXI(NNode), XInt(NInt), WInt(NInt) {
}

main_ns::ShapeFunctions_ns::ShapeFunctions_cls<T1, T2>::~ShapeFunctions_cls() {}

/*
###################################################################################################
Purpose: This function retrieves Gauss points for the numerical integration.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin

================================= V E R S I O N
===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 06/02/2018 - Initiated: Compiled without error for the first time.

###################################################################################################
*/

void main_ns::ShapeFunctions_ns::ShapeFunctions_cls<
    T1, T2>::Retrieving_Gauss_Points_fn() {

  switch (NInt) {
  case 1:
    XInt[0] = {0.0};  // ABSCISSAE
    WInt[0] = {+2.0}; // WEIGHTS
    break;
  case 2:
    XInt[0] = {-sqrt(1.0 / 3.0)}; // ABSCISSAE
    XInt[1] = {+sqrt(1.0 / 3.0)}; // ABSCISSAE
    WInt[0] = {+1.0};             // WEIGHTS
    WInt[1] = {+1.0};             // WEIGHTS
    break;
  case 3:
    XInt[0] = -sqrt(3.0 / 5.0);   // ABSCISSAE
    XInt[1] = {0.0};              // ABSCISSAE
    XInt[2] = {+sqrt(3.0 / 5.0)}; // ABSCISSAE
    WInt[0] = {5.0 / 9.0};        // WEIGHTS
    WInt[1] = {8.0 / 9.0};        // WEIGHTS
    WInt[2] = {5.0 / 9.0};        // WEIGHTS
    break;
  default:
    std::cout << "This NInt is not available in code."
              << "\n";
  }
}
