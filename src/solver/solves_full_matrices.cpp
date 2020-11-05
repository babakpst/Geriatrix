
#include "../../include/solver/solves_full_matrices.h"

main_ns::Solver_ns::solve_full_matrices_cls::solve_full_matrices_cls(
    main_ns::address_ns::address_cls *aAddresses,
    main_ns::model_ns::model_cls *aModel,
    main_ns::discretization_ns::discretization_cls *aDiscretization,
    main_ns::Matrices_ns::Matrices_cls *aMatrices)
    : main_ns::Solver_ns::Solver_cls(aAddresses, aModel, aDiscretization,
                                     aMatrices) {}

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

void main_ns::Solver_ns::solve_full_matrices_cls::
    Compute_the_effective_matrix() {

  main_ns::Matrices_ns::Matrices_Full_cls *fullMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Full_cls *>(this->Matrices);

  // Effective stiffness matrix
  std::cout << " Obtaining the effective matrix ..."
            << "\n";
  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    for (int j = 0; j < DiscretizedModel->NEqM; j++) {
      fullMatrices->K[i][j] = fullMatrices->K[i][j] +
                              A0 * fullMatrices->M[i][j] +
                              A1 * fullMatrices->C[i][j];
    }
  }
}

/*
###################################################################################################
Purpose: This function reduces the stiffness matrix using the LDLT method.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/28/2018 -
Subroutine initiated. V0.01: 06/29/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/
void main_ns::Solver_ns::solve_full_matrices_cls::
    Reduce_the_effective_forece() {

  main_ns::Matrices_ns::Matrices_Full_cls *fullMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Full_cls *>(this->Matrices);

  std::cout << "Reduce effective matrix ..."
            << "\n";
  int tempI;

  std::vector<double> L(DiscretizedModel->NEqM); // Identifications

  for (int j = 0; j < DiscretizedModel->NEqM; j++) {
    std::cout << j << " reduces out of " << DiscretizedModel->NEqM << "\n";

    tempI = 5 + j;
    if (tempI > DiscretizedModel->NEqM)
      tempI = DiscretizedModel->NEqM;

    for (int i = j + 1; i < tempI; i++) {
      L[i] = fullMatrices->K[i][j] / fullMatrices->K[j][j];
    }
    for (int k = j + 1; k < tempI; k++) {
      for (int l = j + 1; l < DiscretizedModel->NEqM; l++) {
        fullMatrices->K[k][l] =
            fullMatrices->K[k][l] - L[k] * fullMatrices->K[j][l];
      }
    }
    for (int i = j + 1; i < tempI; i++) {
      fullMatrices->K[i][j] = L[i];
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

void main_ns::Solver_ns::solve_full_matrices_cls::Effective_forces_fn(
    std::vector<double> &UN) {
  main_ns::Matrices_ns::Matrices_Full_cls *fullMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Full_cls *>(this->Matrices);

  // Effective force - stored in UN
  for (int i = 0; i < DiscretizedModel->NEqM;
       i++) { // find the coefficient of the M matrix
    Temp[i] = A0 * U[i] + A2 * UD[i] + A3 * UDD[i];
  };

  // Multiply the mass matrix by the load vector
  Matrix_Multiplication(fullMatrices->M, Temp, UN);

  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    Temp[i] = A1 * U[i] + A4 * UD[i] + A5 * UDD[i];
  }

  Matrix_Multiplication(fullMatrices->C, Temp, UN);
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

void main_ns::Solver_ns::solve_full_matrices_cls::Matrix_Multiplication(
    double **&Matrix, std::vector<double> &Temp, std::vector<double> &UN) {
  double TempVar;
  for (int i = 0; i < DiscretizedModel->NEqM;
       i++) { // multiplying the vector by the mass matrix
    TempVar = {0.0};
    for (int j = 0; j < DiscretizedModel->NEqM; j++) {
      TempVar += Matrix[i][j] * Temp[j];
    }
    UN[i] = TempVar;
  }
}

/*
###################################################################################################
Purpose: This function solves the AX=B using LDLT method.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/28/2018 -
Subroutine initiated. V0.01: 07/06/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::Solver_ns::solve_full_matrices_cls::
    Solve_the_system_for_this_RHS_using_Gaussina_Elimination(
        std::vector<double> &UN) {
  main_ns::Matrices_ns::Matrices_Full_cls *fullMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Full_cls *>(this->Matrices);

  int k, l; // temporary variables
  double temp;
  std::vector<double> L(DiscretizedModel->NEqM); // Identifications

  // cout << "Forward" << endl;
  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    temp = 0.0;
    for (int j = 0; j < i; j++) {
      temp += fullMatrices->K[i][j] * UN[j];
    }
    UN[i] = UN[i] - temp;
  }

  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    UN[i] = UN[i] / fullMatrices->K[i][i];
  }

  // cout << "Backward" << endl;
  for (int i = 0; i < DiscretizedModel->NEqM; i++) {

    k = DiscretizedModel->NEqM - i - 1;
    temp = 0.0;
    for (int j = 0; j < i; j++) {
      l = DiscretizedModel->NEqM - j - 1;
      temp += fullMatrices->K[l][k] * L[l];
    }
    L[k] = (UN[k] - temp);
  }

  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    UN[i] = L[i];
  }
}
