
#include "../../include/solver/solves_Skyline_matrices.h"

main_ns::Solver_ns::solve_Skyline_matrices_cls::solve_Skyline_matrices_cls(
    main_ns::address_ns::address_cls *aAddresses,
    main_ns::model_ns::model_cls *aModel,
    main_ns::discretization_ns::discretization_cls *aDiscretization,
    main_ns::Matrices_ns::Matrices_cls *aMatrices)
    : main_ns::Solver_ns::Solver_cls(aAddresses, aModel, aDiscretization,
                                     aMatrices) {
  this->Matrices =
      new main_ns::Matrices_ns::Matrices_Skyline_cls(DiscretizedModel, Model);
}

main_ns::Solver_ns::solve_Skyline_matrices_cls::~solve_Skyline_matrices_cls() {

  delete this->Matrices;
}

/*
###################################################################################################
Purpose: This function computes the effective matrix based on the Newmark
algorithm.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/29/2018 -
Subroutine initiated. V0.01: 06/29/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::Solver_ns::solve_Skyline_matrices_cls::
    Compute_the_effective_matrix() {

  main_ns::Matrices_ns::Matrices_Skyline_cls *skyMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Skyline_cls *>(this->Matrices);

  std::cout << " Obtaining the effective matrix ..."
            << "\n";
  Compute_the_effective_matrix();

  for (int i = 0; i < skyMatrices->JD[DiscretizedModel->NEqM - 1]; i++) {
    skyMatrices->K[i] =
        skyMatrices->K[i] + A0 * skyMatrices->M[i] + A1 * skyMatrices->C[i];
  }
}

/*
###################################################################################################
Purpose: This function reduces of the effective stiffness matrix to a triangular
one for Gauss-Elimination method using the skyline method

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/28/2018 -
Subroutine initiated. V0.01: 06/28/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::Solver_ns::solve_Skyline_matrices_cls::
    Reduce_the_effective_forece() {

  main_ns::Matrices_ns::Matrices_Skyline_cls *skyMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Skyline_cls *>(this->Matrices);

  std::cout << "Reduce effective matrix ..."
            << "\n";
  int K1, I1, KJ, KK, KI, IJ; // temp var

  double Fac; // temp var

  int N, N1; // temp var to follow the algorithm

  N = DiscretizedModel->NEqM;
  N1 = N - 1;

  for (int K = 0; K < N1; K++) {
    K1 = K + 1;
    for (int J = K1; J <= N; J++) {
      if (K < (skyMatrices->NTK[J]))
        continue;
      KJ = skyMatrices->JD[J] + K - J;
      KK = skyMatrices->JD[K];
      I1 = K1;
      if (K1 < (skyMatrices->NTK[J]))
        I1 = skyMatrices->NTK[J];
      for (int I = I1; I <= J; I++) {
        if (K > (skyMatrices->NTK[I])) {
          KI = skyMatrices->JD[I] + K - I;
          Fac = skyMatrices->K[KI] / skyMatrices->K[KK];
          IJ = skyMatrices->JD[J] + I - J;
          skyMatrices->K[IJ] = skyMatrices->K[IJ] - skyMatrices->K[KJ] * Fac;
        }
      }
    }
  }
}

/*
###################################################################################################
Purpose: This function solves the AX=B using Gaussian-Elemination method.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/28/2018 -
Subroutine initiated. V0.01: 07/02/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::Solver_ns::solve_Skyline_matrices_cls::Effective_forces_fn(
    std::vector<double> &UN) {
  main_ns::Matrices_ns::Matrices_Skyline_cls *skyMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Skyline_cls *>(this->Matrices);

  // Effective force - stored in UN
  for (int i = 0; i < DiscretizedModel->NEqM;
       i++) { // find the coefficient of the M matrix
    Temp[i] = A0 * U[i] + A2 * UD[i] + A3 * UDD[i];
  };

  // Multiply the mass matrix by the load vector
  Matrix_Multiplication(skyMatrices->M, Temp, UN);

  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    Temp[i] = A1 * U[i] + A4 * UD[i] + A5 * UDD[i];
  }

  Matrix_Multiplication(skyMatrices->C, Temp, UN);
}

/*
###################################################################################################
Purpose: This function conducts matrix-matrix multiplication.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/28/2018 -
Subroutine initiated. V0.01: 07/02/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::Solver_ns::solve_Skyline_matrices_cls::Matrix_Multiplication(
    std::vector<double> &Matrix, std::vector<double> &Temp,
    std::vector<double> &UN) {
  main_ns::Matrices_ns::Matrices_Skyline_cls *skyMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Skyline_cls *>(this->Matrices);

  int I, J, K, IJ;

  for (int II = 0; II < DiscretizedModel->NEqM; II++) {
    for (int JJ = 0; JJ < DiscretizedModel->NEqM; JJ++) {
      I = II;
      J = JJ;
      if (I > J) {
        K = I;
        I = J;
        J = K;
      }
      if (I < skyMatrices->NTK[J])
        continue;
      IJ = skyMatrices->JD[J] + I - J;
      UN[II] += Matrix[IJ] * Temp[JJ];
    }
  }
}

/*
###################################################################################################
Purpose: This function solver the system for each RHS at each time step.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/28/2018 -
Subroutine initiated. V0.01: 07//2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/
void main_ns::Solver_ns::solve_Skyline_matrices_cls::
    Solve_the_system_for_this_RHS_using_Gaussina_Elimination(
        std::vector<double> &UN) {
  main_ns::Matrices_ns::Matrices_Skyline_cls *skyMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Skyline_cls *>(this->Matrices);
  int k, KJ, N, N1, KK, K1, NN; // temporary variables

  N = DiscretizedModel->NEqM;
  N1 = N - 1;

  for (int k = 0; k < N1; k++) {
    K1 = k + 1;
    for (int j = K1; j < N; j++) {
      if (k < skyMatrices->NTK[j])
        continue;
      KJ = skyMatrices->JD[j] + k - j;
      KK = skyMatrices->JD[k];
      UN[j] = UN[j] - UN[k] * skyMatrices->K[KJ] / skyMatrices->K[KK];
    }
  }

  NN = skyMatrices->JD[N];
  UN[N] = UN[N] / skyMatrices->K[NN];

  for (int i = 0; i < N1; i++) {
    k = N - i;
    K1 = k + 1;
    for (int j = K1; j < N; j++) {
      if (k >= skyMatrices->NTK[j]) {
        KJ = skyMatrices->JD[j] + k - j;
        UN[k] = UN[k] - skyMatrices->K[KJ] * UN[j];
      }
    }
    KK = skyMatrices->JD[k];
    UN[k] = UN[k] / skyMatrices->K[KK];
  }
}
