
#include "../include/create_full_matrices_cls.h"

// Constructor: we also create and allocate matrices
main_ns::Matrices_ns::Matrices_Full_cls::Matrices_Full_cls(
    main_ns::discretization_ns::discretization_cls *aDiscretization,
    main_ns::model_ns::model_cls *aModel)
    : main_ns::Matrices_ns::Matrices_cls(aDiscretization, aModel)
{
  main_ns::Matrices_ns::Matrices_Full_cls::allocating_global_matrices_fn();
  main_ns::Matrices_ns::Matrices_Full_cls::allocating_local_matrices_fn();
  main_ns::Matrices_ns::Matrices_cls::allocate_matrices_for_assembling_fn();
}

main_ns::Matrices_ns::Matrices_Full_cls::~Matrices_Full_cls()
{

  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    delete[] K[i];
  }
  delete[] K;

  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    delete[] M[i];
  }
  delete[] M;

  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    delete[] C[i];
  }
  delete[] C;
}

/*
###################################################################################################
Purpose: This function allocates global matrices. In this module we consider full matrices.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 05/15/2018 - Initiated: Compiled without error for the first time.
V1.00: 06/18/2018 - 

###################################################################################################
*/

void main_ns::Matrices_ns::Matrices_Full_cls::allocating_global_matrices_fn()
{

  std::cout << " -allocating global matrices ..." << "\n";
  K = new double *[DiscretizedModel->NEqM]; // Stiffness Matrix
  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    K[i] = new double[DiscretizedModel->NEqM];
  }

  C = new double *[DiscretizedModel->NEqM]; // Damping matrix
  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    C[i] = new double[DiscretizedModel->NEqM];
  }

  M = new double *[DiscretizedModel->NEqM]; // Mass matrix
  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    M[i] = new double[DiscretizedModel->NEqM];
  }

  F.resize(DiscretizedModel->NEqM);

  std::cout << " -initializing global matrices ..." << "\n";
  for (int i = 0; i < DiscretizedModel->NEqM; i++)
  {
    for (int j = 0; j < DiscretizedModel->NEqM; j++)
    {
      M[i][j] = {0.0};
      C[i][j] = {0.0};
      K[i][j] = {0.0};
    }
    F[i] = {0.0};
  }

  std::cout << " Done with allocation, successfully." << "\n";
}

/*
###################################################################################################
Purpose: This function allocates the required matrices for assembling. 

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 05/15/2018 - Initiated: Compiled without error for the first time.
V1.00: 06/24/2018 - 

###################################################################################################
*/
void main_ns::Matrices_ns::Matrices_Full_cls::assemble_local_to_global_fn()
{

  int L;
  int N;

  for (int i = 0; i < NEqEl; i++)
  {
    for (int j = 0; j < NEqEl; j++)
    {
      L = ND[i];
      N = ND[j];
      if (L == -1 || N == -1)
        continue;
      K[L][N] = K[L][N] + Ke[i][j];
      C[L][N] = C[L][N] + Ce[i][j];
      M[L][N] = M[L][N] + Me[i][j];
    }
  }

  // std::cout << "C  " <<  C [L][N] << "Ce" << Ce [i][j] << endl;
  //cin.get();
}

/*
###################################################################################################
Purpose: This function extracts the DRM matrices from the full matrices.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 05/14/2018 - Subroutine initiated.
V0.01: 05/15/2018 - Initiated: Compiled without error for the first time.
V1.00: 06/24/2018 - 

###################################################################################################
*/

void main_ns::Matrices_ns::Matrices_Full_cls::create_DRM_matrices_fn()
{

  for (int i = 0; i < Model->NNLayer * Model->NDim; i++)
  {
    for (int j = 0; j < Model->NNBndry * Model->NDim; j++)
    {
      K_eb[i][j] = K[ND_e[i]][ND_b[j]];
      C_eb[i][j] = C[ND_e[i]][ND_b[j]];
      M_eb[i][j] = M[ND_e[i]][ND_b[j]];
    }
  }
}
