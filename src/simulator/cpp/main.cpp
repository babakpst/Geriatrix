
/*
===================================================================================================

************************************** G E T A F I X   1 D  ***************************************
Purpose:  Numerical solution of one-dimensional wave propagation in a heterogeneous half-space.

Developer:         Babak Poursartip
                   Civil, Architectural, and Environmental Engineering department
                   The Institute for Computational Engineering and Sciences (ICES)
                   The University of Texas at Austin

Date starting:     July 1, 2016
version 1.0        July 07, 2016     Time domain
version 1.1        July 20, 2016     output for Matlab
version 1.2        July 25, 2016     Matlab output has modified
version 1.3        July 27, 2016     Visualization (Animation)
version 1.4        Sept 10, 2016     Unstructured mesh
version 2.0        Sept 22, 2016     Transfer functions (frequency domain)
version 2.0        March 30, 2018    Check
version 2.1        April 08, 2018    Some minor modifications
version 2.2        May 30, 2018      Transforming the code to an OOP
version 2.3        July 22, 2018     adding vectors

Last Update:       Dec 04, 2018

Comments:
- This code solves the one-dimensional equation, in several domains. The boundary condition at the
  top of the domain is a free surface, and at the bottom is the Lysmer damping absorbing boundary.
- The seismic load prescribed in the domain through DRM (Domain Reduction Method).
- The solver is LD method.
- The simulation can be in the time or frequency domain.
- We use a full or skyline method to save global matrices.
- Node numbers start from 0.
- Element numbers start from 0.
- Equation number starts from 0.
  ID(1 2
     3 4 )
  ND [---x--- ---y---]

===================================================================================================
*/

#include "../include/Address_cls.h"
#include "../include/reading_the_model_cls.h"
#include "../include/discretize_the_domain_cls.h"
#include "../include/Visualization_cls.h"
#include "../include/create_global_matrices_cls.h"

#include "../include/create_full_matrices_cls.h"    // This should be here <delete> the comment
#include "../include/create_skyline_matrices_cls.h" // This should be here <delete> the comment

#include "../include/solver_cls.h"
#include "../include/solves_full_matrices.h"
#include "../include/solves_Skyline_matrices.h"

int main()
{

  // = input class ================================================================================
  main_ns::address_ns::address_cls input;
  input.address_fn();

  // = model data =================================================================================
  main_ns::model_ns::model_cls model(&input);
  model.InputBasic();  // Reading basic data
  model.InputArrays(); // Reading arrays

  // = discretization =============================================================================
  main_ns::discretization_ns::discretization_cls discretized_model(&model);
  discretized_model.Discretization();

  // = discretization =============================================================================
  main_ns::visualization_ns::visualization_cls Visual(&input, &model, &discretized_model);
  Visual.MatlabOutput_fn();

  // = matrices ===================================================================================
  // creating global matrices

  main_ns::Matrices_ns::Matrices_cls *Matrix;

  switch (model.Solver)
  {
  case 0: // solving the system using full matrices
    Matrix = new main_ns::Matrices_ns::Matrices_Full_cls(&discretized_model, &model);
    break;
  case 1: // solving the system using skyline mathod
    Matrix = new main_ns::Matrices_ns::Matrices_Skyline_cls(&discretized_model, &model);
    break;
  case 2: // Transfer functions in the frequency domain
    Matrix = new main_ns::Matrices_ns::Matrices_Full_cls(&discretized_model, &model);
    break;
  default:
    std::cout << "The input solver type is not available. Solver should be either 0 for full \
                                                   matrices or 1 for skyline method" << "\n";
    Matrix = NULL;
  }

  Matrix->assembling_local_matrices_into_global_matrices_fn();
  Matrix->create_DRM_matrices_fn();

  // = solver =====================================================================================
  main_ns::Solver_ns::Solver_cls *Solver;
  switch (model.Solver)
  {
  case 0: // solving the system using full matrices
    Solver = new main_ns::Solver_ns::
             solve_full_matrices_cls(&input, &model, &discretized_model, Matrix);
    break;
  case 1: // solving the system using skyline mathod
    Solver = new main_ns::Solver_ns::
             solve_Skyline_matrices_cls(&input, &model, &discretized_model, Matrix);
    break;
  case 2: // Computing transfer functions in the frequency domain anaylsis using full matrices

  default:
    std::cout << "The input solver type is not available. Solver should be either 0 for full \
                                                   matrices or 1 for skyline method" << "\n";
    Solver = NULL;
  }
  Solver->solve_the_system_using_implicit_newmark_method();

  /*
  // - Computing the transfer functions in the frequency domain -----------------------------------
  Transfer_Full ( alpha1, alpha2, Wave_Type, NEqM, M, C, K, PMat, XYZ, ND_e, ND_b, TransferFunc );
  info.close();
  break;
  }
  }
*/

  // terminating the code
  std::cout << "End of the code! " << "\n";
  std::cout << "Press 'Enter' to end! " << "\n";

  return 0;
}
