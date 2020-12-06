
/*
================================================================================

G E R I A T R I X

Numerical solution the wave equation in a heterogeneous a half-space.

Developer:         Babak Poursartip
Affiliation:
 Civil, Architectural, and Environmental Engineering Department (1/2010~12/2017)
 The Institute for Computational Engineering and Sciences (ICES)(1/2018~6/2019)
 The University of Texas at Austin
 Ansys, Inc.                                                    (11/2020~)


Date starting:     Jul 01, 2016
version 1.0        Jul 07, 2016     Time domain
version 1.1        Jul 20, 2016     output for Matlab
version 1.2        Jul 25, 2016     Matlab output has modified
version 1.3        Jul 27, 2016     Visualization (Animation)
version 1.4        Sep 10, 2016     Unstructured mesh
version 2.0        Sep 22, 2016     Transfer functions (frequency domain)
version 2.0        Mar 30, 2018     Check
version 2.1        Apr 08, 2018     Some minor modifications
version 2.2        May 30, 2018     Transforming the code to an OOP
version 2.3        Jul 22, 2018     adding vectors
version 2.4        Nov 04, 2020     redesigning the code

Last Update:       June 27 04, 2019

Comments:
- This code solves the wave differential equation in time- and frequency
domains.
- The options for boundary condition is a) Lysmer damping absorbing boundary,
and b) Perfectly Matched Layers.

- The seismic load prescribed in the domain through a) point load, b) DRM
(Domain Reduction Method).
- The solver is LD factorization method.
- We use a full or skyline method to save global matrices.
- Node numbers start from 0.
- Element numbers start from 0.
- Equation number starts from 0.
  ID(1 2
     3 4 )
  ND [---x--- ---y---]

================================================================================
*/

/** @file simulator.cpp
@author Poursartip:Babak:PhD:Wave simulation

@version Revision 2.4

@brief Numerical solution the wave equation in a heterogeneous a half-space.

@details I developed this code after I completed my PhD, to provide a free
software for the solution of wave equation.

@date Tuesday, Nov 03, 2020
*/

/**
@mainpage
<em>comments:</em>
- This code solves the <b>wave differential equation</b> in time- and frequency
domains.
- The options for boundary condition is a) Lysmer damping absorbing boundary,
and b) Perfectly Matched Layers.
- The seismic load prescribed in the domain through a) point load, b) DRM
(Domain Reduction Method).
- The solver is LD factorization method.
- We use a full or skyline method to save global matrices.
- Node numbers start from 0.
- Element numbers start from 0.
- Equation number starts from 0.
  ID(1 2
     3 4 )
  ND [---x--- ---y---]
.

This is not the final version,\n and I am still working on it. <br> Use it at
your own risk.
*/

// libraries
#include <iostream>

// classes
#include "../include/io/Info.h"
#include "../include/io/Initialization.h"
#include "../include/timing/Date.h"

//#include "../include/global_matrices/create_full_matrices_cls.h"
//#include "../include/global_matrices/create_global_matrices_cls.h"
//#include "../include/global_matrices/create_skyline_matrices_cls.h"
//#include "../include/input/reading_the_model_cls.h"
//#include "../include/mesh/discretize_the_domain_cls.h"
//#include "../include/solver/solver_cls.h"
//#include "../include/solver/solves_Skyline_matrices.h"
//#include "../include/solver/solves_full_matrices.h"
//#include "../include/visualization/Visualization_cls.h"

/**<
Compute and return the number of digits in a positive integer.
The style used for the pre/post coditions of this function is
purposely different from that for the void function given above,
just so you can see the differnce in the HTML output.
@return The number of digits in n.
@param n An integer, the number of whose digits is desired.
@pre n contains a positive integer.
This is some other precondition, and note that it does not
start on a new line.
@post
The number of digits in n has been returned.
\n This is some other post condition, and note that it does start
on a new line.
*/

int main(int argv, char *argc[]) {
  // int main() {

  std::shared_ptr<io::CInfo> info(new io::CInfo());             // communication class
  std::shared_ptr<timing::CDate> dateTime(new timing::CDate()); // date and time class

  info->prt_welcome_terminal();

  std::unique_ptr<io::CInitialization> init(
      new io::CInitialization(info));        // initializing the directories
  init->simulationName_fn(info, argv, argc); // the simulation name
  init->directories_fn();                    // filling directory strings
  init->createFolders_fn();                  // creating output folders/files

  // welcome message in the logfile

  // shut down message ======
  info->prt_success_terminal();

  // ================================================================
  // ================================================================
  // ================================================================
  /*
  // reading the model (mesh, geometry, etc.)
  main_ns::model_ns::model_cls model(&input);
  model.InputBasic();  // reading basic data
  model.InputArrays(); // reading arrays

  // discretization (This is only needed for the 1D model)
  main_ns::discretization_ns::discretization_cls discretized_model(&model);
  discretized_model.Discretization();

  // visualization
  main_ns::visualization_ns::visualization_cls Visual(&input, &model,
                                                      &discretized_model);
  Visual.MatlabOutput_fn();

  // creating global matrices
  main_ns::Matrices_ns::Matrices_cls *Matrix;

  switch (model.Solver) {
  case 0: // solving the system using full matrices
    Matrix =
        new main_ns::Matrices_ns::Matrices_Full_cls(&discretized_model, &model);
    break;
  case 1: // solving the system using skyline mathod
    Matrix = new main_ns::Matrices_ns::Matrices_Skyline_cls(&discretized_model,
                                                            &model);
    break;
  case 2: // Transfer functions in the frequency domain
    Matrix =
        new main_ns::Matrices_ns::Matrices_Full_cls(&discretized_model, &model);
    break;
  default:
    std::cout
        << "The input solver type is not available. Solver should be either 0
  for full \ matrices or 1 for skyline method"
        << "\n";
    Matrix = NULL;
  }

  Matrix->assembling_local_matrices_into_global_matrices_fn();
  Matrix->create_DRM_matrices_fn();

  // solver: marching in time

  main_ns::Solver_ns::Solver_cls *Solver;
  switch (model.Solver) {
  case 0: // solving the system using full matrices
    Solver = new main_ns::Solver_ns::solve_full_matrices_cls(
        &input, &model, &discretized_model, Matrix);
    break;
  case 1: // solving the system using skyline mathod
    Solver = new main_ns::Solver_ns::solve_Skyline_matrices_cls(
        &input, &model, &discretized_model, Matrix);
    break;
  case 2: // Computing transfer functions in the frequency domain anaylsis using
          // full matrices

  default:
    std::cout
        << "The input solver type is not available. Solver should be either 0
  for full \ matrices or 1 for skyline method"
        << "\n";
    Solver = NULL;
  }
  Solver->solve_the_system_using_implicit_newmark_method();
  */
  /*
  // - Computing the transfer functions in the frequency domain
  -----------------------------------
  Transfer_Full ( alpha1, alpha2, Wave_Type, NEqM, M, C, K, PMat, XYZ, ND_e,
  ND_b, TransferFunc );
  info.close();
  break;
  }
  }
  */

  // terminating the code
  std::cout << "\n ---- Simulation terminated successfully! ----\n\n";

  return 0;
}
