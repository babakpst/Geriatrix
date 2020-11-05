
#include "../../include/global_matrices/create_skyline_matrices_cls.h"

// Constructor: we also create and allocate matrices
main_ns::Matrices_ns::Matrices_Skyline_cls::Matrices_Skyline_cls(
    main_ns::discretization_ns::discretization_cls *aDiscretization,
    main_ns::model_ns::model_cls *aModel)
    : main_ns::Matrices_ns::Matrices_cls(aDiscretization, aModel) {
  main_ns::Matrices_ns::Matrices_Skyline_cls::allocating_global_matrices_fn();
  main_ns::Matrices_ns::Matrices_Skyline_cls::allocating_local_matrices_fn();
  main_ns::Matrices_ns::Matrices_Skyline_cls::Skyline_fn();
  main_ns::Matrices_ns::Matrices_cls::allocate_matrices_for_assembling_fn();
}

/*
###################################################################################################
Purpose: This function allocates global matrices. In this module we consider
full matrices.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/18/2018 -
Subroutine initiated. V1.00: 06/27/2018 - compiled correctly.

###################################################################################################
*/

void main_ns::Matrices_ns::Matrices_Skyline_cls::
    allocating_global_matrices_fn() {

  std::cout << " -allocating global matrices ..."
            << "\n";

  JD.resize(DiscretizedModel->NEqM);
  NTK.resize(DiscretizedModel->NEqM);

  K.resize(JD[DiscretizedModel->NEqM - 1]); // Stiffness Matrix
  C.resize(JD[DiscretizedModel->NEqM - 1]); // Damping matrix
  M.resize(JD[DiscretizedModel->NEqM - 1]); // Mass matrix

  F.resize(DiscretizedModel->NEqM);

  std::cout << " -initializing global matrices ..."
            << "\n";
  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    F[i] = {0.0};
  }

  for (int i = 0; i < JD[DiscretizedModel->NEqM - 1]; i++) {
    K[i] = {0.0};
    C[i] = {0.0};
    M[i] = {0.0};
  }

  std::cout << " Done with allocation, successfully."
            << "\n";
}

/*
###################################################################################################
Purpose: This function assembles local matrices into the full matrices.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/18/2018 -
Subroutine initiated. V1.00: 06/27/2018 - compiled correctly.

###################################################################################################
*/

void main_ns::Matrices_ns::Matrices_Skyline_cls::assemble_local_to_global_fn() {

  int l, n, i, j, ij;

  for (l = 0; l < NEqEl; l++) {
    for (n = 0; n < NEqEl; n++) {
      i = ND[l];
      j = ND[n];
      if (i > j)
        continue;
      ij = JD[j] + i - j;

      K[ij] = K[ij] + Ke[l][n];
      C[ij] = C[ij] + Ce[l][n];
      M[ij] = M[ij] + Me[l][n];
    }
  }
}

/*
###################################################################################################
Purpose: This function creates the required matrices for the skyline method.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 06/18/2018 -
Subroutine initiated. V1.00: 06/27/2018 - compiled correctly.

###################################################################################################
*/

void main_ns::Matrices_ns::Matrices_Skyline_cls::Skyline_fn() {

  int i, j, k;

  for (int i = 0; i < NEqEl; i++) {
    ND[i] = {0};
  }

  for (int i = 0; i < DiscretizedModel->NEqM; i++) {
    NTK[i] = i;
  }

  for (int iel = 0; iel < Model->NEl; iel++) {
    for (int i = 0; i < Model->NNode; i++) {
      k = DiscretizedModel->INod[i][iel];
      for (int j = 0; j < Model->NDOF; j++) {
        ND[j * Model->NNode + i] = DiscretizedModel->ID[k][j];
      }
    }

    for (int l = 0; l < NEqEl; l++) {
      for (int k = 0; k < NEqEl; k++) {
        i = {ND[l]};
        j = {ND[k]};
        // if ((i==0) ||  (j==0)) continue;
        if (i > j)
          continue;
        if (i < NTK[j])
          NTK[j] = {i};
      }
    }
  }

  JD[0] = {0};

  for (int i = 1; i < DiscretizedModel->NEqM; i++) {
    JD[i] = JD[i - 1] + i + 1 - NTK[i];
  }

  std::cout << "End function skyline"
            << "\n";
}

/*
###################################################################################################
Purpose: This function extracts the DRM matrices from the skyline matrices.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 05/14/2018 -
Subroutine initiated. V0.01: 05/15/2018 - Initiated: Compiled without error for
the first time. V1.00: 06/27/2018 - compiled correctly.

###################################################################################################
*/

void main_ns::Matrices_ns::Matrices_Skyline_cls::create_DRM_matrices_fn() {

  int ij, i, j; // Loop indices

  // - Code
  // ---------------------------------------------------------------------
  std::cout << "Create DRM matrices ..."
            << "\n";

  for (int l = 0; l < Model->NNLayer * Model->NDim; l++) {
    for (int n = 0; n < Model->NNBndry * Model->NDim; n++) {

      i = {ND_e[l]};
      j = {ND_b[n]};

      if (i > j) {
        ij = i;
        i = j;
        j = ij;
        std::cout << " i and j replaced"
                  << "\n";
      }

      ij = JD[j] + i - j;

      K_eb[l][n] = {K[ij]};
      C_eb[l][n] = {C[ij]};
      M_eb[l][n] = {M[ij]};
    }
  }

  std::cout << "DRM matrices created."
            << "\n";
}
