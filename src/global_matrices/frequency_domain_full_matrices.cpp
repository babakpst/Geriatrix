

#include "../include/global_matrices/frequency_domain_full_matrices.h"

main_ns::Solver_ns::frequency_domain_analysis::frequency_domain_analysis(
    main_ns::address_ns::address_cls *aAddresses,
    main_ns::model_ns::model_cls *aModel,
    main_ns::discretization_ns::discretization_cls *aDiscretization,
    main_ns::Matrices_ns::Matrices_cls *aMatrices)
    : Addresses(aAddresses), Model(aModel), DiscretizedModel(aDiscretization),
      Matrices(aMatrices) {}

main_ns::Solver_ns::frequency_domain_analysis::~frequency_domain_analysis() {
  for (int i = 0; i < 2 * DiscretizedModel->NEqM; i++) {
    delete[] K_Eff[i];
  }
  delete[] K_Eff;
}
/*
###################################################################################################
Purpose: This function reduces the stiffness matrix using the LDLT method.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 07/11/2018 -
Subroutine initiated. V1.01: 07/14/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::Solver_ns::frequency_domain_analysis::
    Reduce_the_effective_forece_in_the_freq_domain() {

  std::cout << " Factorization of the matrices ... "
            << "\n";
  std::vector<double> L(2 * DiscretizedModel->NEqM); // Identifications

  for (int j = 0; j < (2 * DiscretizedModel->NEqM); j++) {
    std::cout << j << " reduces out of " << 2 * DiscretizedModel->NEqM << "\n";

    // tempI = 5+j;
    // if (tempI> NEqM) tempI = NEqM;

    // for (i=j+1; i<tempI; i++){
    for (int i = j + 1; i < (2 * DiscretizedModel->NEqM); i++) {
      L[i] = K_Eff[i][j] / K_Eff[j][j];
    }

    for (int k = j + 1; k < (2 * DiscretizedModel->NEqM); k++) {
      for (int l = j + 1; l < (2 * DiscretizedModel->NEqM); l++) {
        K_Eff[k][l] = K_Eff[k][l] - L[k] * K_Eff[j][l];
      }
    }

    for (int i = j + 1; i < (2 * DiscretizedModel->NEqM); i++) {
      K_Eff[i][j] = L[i];
    }
  }
}

/*
###################################################################################################
Purpose: This function solves the system for each frequency.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 07/11/2018 -
Subroutine initiated. V1.01: 07/14/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/
void main_ns::Solver_ns::frequency_domain_analysis::
    substitute_the_RHS_and_solve() {

  double temp;
  std::vector<double> L(2 *
                        DiscretizedModel->NEqM); // Identifications- temp vector

  // Forward substitution
  for (int i = 0; i < (2 * DiscretizedModel->NEqM); i++) {
    temp = {0.0};
    for (int j = 0; j < i; j++) {
      temp += K_Eff[i][j] * RHS[j];
    }
    RHS[i] = {RHS[i] - temp};
  }

  for (int i = 0; i < (2 * DiscretizedModel->NEqM); i++) {
    RHS[i] = {RHS[i] / K_Eff[i][i]};
  }

  int k, l; // temporary indices

  // Backward substitution
  for (int i = 0; i < (2 * DiscretizedModel->NEqM); i++) {

    k = (2 * DiscretizedModel->NEqM) - i - 1;
    temp = 0.0;
    for (int j = 0; j < i; j++) {
      l = (2 * DiscretizedModel->NEqM) - j - 1;
      temp += K_Eff[l][k] * L[l];
    }
    L[k] = {RHS[k] - temp};
  }

  for (int i = 0; i < (2 * DiscretizedModel->NEqM); i++) {
    RHS[i] = {L[i]};
  }
}

/*
###################################################################################################
Purpose: This function reduces the stiffness matrix using the LDLT method.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 07/11/2018 -
Subroutine initiated. V1.01: 07/14/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/
void main_ns::Solver_ns::frequency_domain_analysis::
    Compute_the_transfer_functions_in_the_frequency_domain() {

  std::cout << "<<<<   Computing the Transfer functions for this domain >>>>"
            << "\n";

  main_ns::Matrices_ns::Matrices_Full_cls *fullMatrices =
      static_cast<main_ns::Matrices_ns::Matrices_Full_cls *>(this->Matrices);

  // Define arrays
  std::cout << " Create arrays ..."
            << "\n";

  // Solution in for each frequency- The first half of the vector is the real
  // part and the second half is the imaginary part
  std::vector<double> U(2 * DiscretizedModel->NEqM);

  // Right Hand Side of the equation (load vector) - The first half of the
  // vector is the real part and the second half is the imaginary part
  RHS.resize(2 * DiscretizedModel->NEqM);

  K_Eff = new double *[2 * DiscretizedModel->NEqM]; // Effective stiffness
  for (int i = 0; i < (2 * DiscretizedModel->NEqM); i++) {
    K_Eff[i] = new double[2 * DiscretizedModel->NEqM];
  }

  double **K_Eff_eb; // The effective striffness DRM matrix
  K_Eff_eb = new double
      *[Model->NDim * Model->NNLayer]; // The effective striffness DRM matrix
  for (int i = 0; i < (Model->NDim * Model->NNLayer); i++) {
    K_Eff_eb[i] = new double[Model->NDim * Model->NNBndry];
  }

  double **C_Eff_eb; // The effective damping DRM matrix
  C_Eff_eb = new double
      *[Model->NDim * Model->NNLayer]; // The effective striffness DRM matrix
  for (int i = 0; i < (Model->NDim * Model->NNLayer); i++) {
    C_Eff_eb[i] = new double[Model->NDim * Model->NNBndry];
  }

  // Defining the required vectors:
  // The real part of the analytical solution on the boundary
  std::vector<double> U_b_R(Model->NNBndry * Model->NDim);
  // The imaginary part of the analytical solution on the boundary
  std::vector<double> U_b_I(Model->NNBndry * Model->NDim);

  // The real part of the DRM load on the DRM layer
  std::vector<double> F_e_R(Model->NNLayer * Model->NDim);
  // The imaginary part of the DRM load on the DRM layer
  std::vector<double> F_e_I(Model->NNLayer * Model->NDim);

  // Defining the required vectors:
  // The real part of the analytical solution on the layer
  std::vector<double> U_e_R(Model->NNLayer * Model->NDim);
  // The imaginary part of the analytical solution on the boundary
  std::vector<double> U_e_I(Model->NNLayer * Model->NDim);

  // The real part of the DRM load on the DRM boundary
  std::vector<double> F_b_R(Model->NNBndry * Model->NDim);
  // The imaginary part of the DRM load on the DRM boundary
  std::vector<double> F_b_I(Model->NNBndry * Model->NDim);

  // Define frequencies
  double minf = {0.0};         // min cyclic frequency
  double maxf = Model->alpha1; // max cyclic frequency
  double df = Model->alpha2;   // cyclic frequency increment

  // material properties of the domain where the DRM boundary is
  double E = Model->PMat[0][0];   // Elastic Modulus
  double Rho = Model->PMat[0][1]; // density
  double c =
      sqrt(E / Rho); // wave velocity in the domain where the DRM boundary is

  const double pi = 3.14159265358979323846;

  double freq;  // cyclicfrequency increments
  double omega; // circular frequency increments

  double Result_R; // Transfer functions on the sruface - real part
  double Result_I; // Transfer functions on the sruface - imaginary part
  double Result;   // Transfer functions on the sruface - Total motion

  // NSteps
  int NStep = (int)((maxf - minf) /
                    df); // Total number of steps to cover the frequency range

  // filling the load member
  LoadPackage.amplitude = Model->amplitude;
  LoadPackage.c = c;
  LoadPackage.omega = Model->omega;

  // Open output files for the transfer function output
  TransferFunc.open(Addresses->TransferFunction_Dir.c_str(), std::ios::out);

  for (int iStep = 1; iStep <= NStep; iStep++) {

    freq = minf + iStep * df;
    omega = 2.0 * pi * freq;
    std::cout << "Step: " << iStep << " Frequency: " << freq << "\n";

    // Effective stiffness matrix for this frequency
    // std::cout << "Effective stiffness ..." << endl;
    for (int i = 0; i < DiscretizedModel->NEqM; i++) {
      for (int j = 0; j < DiscretizedModel->NEqM; j++) {
        K_Eff[i][j] =
            -omega * omega * fullMatrices->M[i][j] + fullMatrices->K[i][j];
        K_Eff[i + DiscretizedModel->NEqM][j] = -omega * fullMatrices->C[i][j];
        K_Eff[i][j + DiscretizedModel->NEqM] = -omega * fullMatrices->C[i][j];
        K_Eff[i + DiscretizedModel->NEqM][j + DiscretizedModel->NEqM] =
            +omega * omega * fullMatrices->M[i][j] - fullMatrices->K[i][j];
      }
    }

    // Coefficient matrices for DRM loads for this frequency
    for (int i = 0; i < (Model->NDim * Model->NNLayer); i++) {
      for (int j = 0; j < (Model->NDim * Model->NNBndry); j++) {
        K_Eff_eb[i][j] = +omega * omega * fullMatrices->M_eb[i][j] -
                         fullMatrices->K_eb[i][j];
        C_Eff_eb[i][j] = +omega * fullMatrices->C_eb[i][j];
      }
    }

    // Initializing displacement and the load vector (RHS)
    for (int i = 0; i < (2 * DiscretizedModel->NEqM); i++) {
      U[i] = 0.0;
      RHS[i] = 0.0;
    }

    // Working on F_e
    for (int i = 0; i < Model->NNBndry * Model->NDim; i++) {
      U_b_R[i] = 0.0;
      U_b_I[i] = 0.0;
    }

    for (int i = 0; i < Model->NNLayer * Model->NDim; i++) {
      F_e_R[i] = 0.0;
      F_e_I[i] = 0.0;
    }

    // Computing the analytical solution at the DRM boundary and the DRM layer
    // nodes (Flat homogeneous domain)
    for (int i = 0; i < Model->NNBndry; i++) {
      for (int j = 0; j < Model->NDim; j++) {
        // Coordinate of the node
        LoadPackage.x =
            DiscretizedModel->XYZ[DiscretizedModel->NoBndry_DRM[i]][j];

        LoadPackage.u_R = 0.0; // Initialize the values - Not really necessary
        LoadPackage.u_I = 0.0; // Initialize the values - Not really necessary

        // Computing the analytical solution - Comment: the one-dimensional
        // wave-motion is identical for both SV and P waves. (not really
        // required to separate the two waves)
        if (Model->Wave_Type == 0)
          DRM_PointValues_for_frequency_domain(&LoadPackage); // SV wave
        else if (Model->Wave_Type == 1)
          DRM_PointValues_for_frequency_domain(&LoadPackage); // P wave

        // Filling the analytical solution vector
        U_b_R[i * Model->NNBndry * Model->NDim + j] = LoadPackage.u_R;
        U_b_I[i * Model->NNBndry * Model->NDim + j] = LoadPackage.u_I;
      }
    }

    for (int i = 0; i < Model->NNLayer * Model->NDim; i++) {
      for (int j = 0; j < Model->NNBndry * Model->NDim; j++) {
        F_e_R[i] += -K_Eff_eb[i][j] * U_b_R[j] - C_Eff_eb[i][j] * U_b_I[j];
        F_e_I[i] += -K_Eff_eb[i][j] * U_b_I[j] + C_Eff_eb[i][j] * U_b_R[j];
      }
    }

    // Assemble the load vector
    for (int i = 0; i < Model->NNLayer * Model->NDim; i++) {
      RHS[fullMatrices->ND_e[i]] += +F_e_R[i];
      RHS[fullMatrices->ND_e[i] + DiscretizedModel->NEqM] += -F_e_I[i];
    }

    // Working on F_b
    for (int i = 0; i < Model->NNLayer * Model->NDim; i++) {
      U_e_R[i] = 0.0;
      U_e_I[i] = 0.0;
    }

    for (int i = 0; i < Model->NNBndry * Model->NDim; i++) {
      F_b_R[i] = 0.0;
      F_b_I[i] = 0.0;
    }

    // Loop on the nodes on the DRM layer to find out the analytical solution
    // (In this case there are only two nodes.)
    for (int i = 0; i < Model->NNLayer; i++) {
      for (int j = 0; j < Model->NDim; j++) {
        // Coordinate of the node
        LoadPackage.x =
            DiscretizedModel->XYZ[DiscretizedModel->NoLayer_DRM[i]][j];

        LoadPackage.u_R = 0.0; // Initialize the values - Not really necessary
        LoadPackage.u_I = 0.0; // Initialize the values - Not really necessary

        // Computing the analytical solution
        // Comment: the one-dimensional wave-motion is identical for both SV and
        // P waves.
        if (Model->Wave_Type == 0)
          DRM_PointValues_for_frequency_domain(&LoadPackage); // SV wave
        else if (Model->Wave_Type == 1)
          DRM_PointValues_for_frequency_domain(&LoadPackage); // P wave

        // Filling the analytical solution vector
        U_e_R[i * Model->NNBndry * Model->NDim + j] = LoadPackage.u_R;
        U_e_I[i * Model->NNBndry * Model->NDim + j] = LoadPackage.u_I;
      }
    }

    // Multiply the Mass, Damp, and Stiffness matrix by the vector
    for (int i = 0; i < Model->NNBndry * Model->NDim; i++) {
      for (int j = 0; j < Model->NNLayer * Model->NDim; j++) {
        F_b_R[i] += +K_Eff_eb[j][i] * U_e_R[j] + C_Eff_eb[j][i] * U_e_I[j];
        F_b_I[i] += +K_Eff_eb[j][i] * U_e_I[j] - C_Eff_eb[i][j] * U_e_R[j];
      }
    }

    // Assemble the load vector
    for (int i = 0; i < Model->NNBndry * Model->NDim; i++) {
      RHS[fullMatrices->ND_b[i]] += +F_b_R[i];
      RHS[fullMatrices->ND_b[i] + DiscretizedModel->NEqM] += -F_b_I[i];
    }

    // Reduction the coefficient matrix ( Effective Stiffness Matrix )
    // Reduce_Full (NEqM, K, Check);
    Reduce_the_effective_forece_in_the_freq_domain();

    // SOLVE
    substitute_the_RHS_and_solve();

    // time history of the solution at some particular nodes
    Result_R = RHS[DiscretizedModel->NEqM - 1];
    Result_I = RHS[DiscretizedModel->NEqM * 2 - 1];
    Result = sqrt(Result_R * Result_R + Result_I * Result_I);

    // Recording the results in the output file
    TransferFunc << std::setw(20) << freq << std::setw(20) << Result_R
                 << std::setw(20) << Result_I << std::setw(20) << Result
                 << "\n";
  }

  // Close the output file
  TransferFunc.close();

  for (int i = 0; i < Model->NDim * Model->NNLayer; i++) {
    delete[] K_Eff_eb[i];
  }
  delete[] K_Eff_eb;

  for (int i = 0; i < Model->NDim * Model->NNLayer; i++) {
    delete[] C_Eff_eb[i];
  }
  delete[] C_Eff_eb;
}
