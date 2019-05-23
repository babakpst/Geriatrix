
#include "../include/Load.h"

main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::
    apply_seismic_loads_to_the_domain_cls()
{
}

/*
###################################################################################################
Purpose: This function computes the load factor to apply the pressure load on the surface.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 06/26/2018 - Subroutine initiated.
V1.00: 06/26/2018 - Compiled successfully.

###################################################################################################
*/

double main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::
    LoadFunction(const double Time, const double Alpha, const double P)
{
  if (Time < 2.0 * pi / Alpha)
    LoadFactor = -P * sin(Alpha * Time);
  else
    LoadFactor = {0.0};

  return (LoadFactor);
}

/*
###################################################################################################
Purpose: This function compuates the DRM point loads at each load.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 06/26/2018 - Subroutine initiated.
V1.00: 06/27/2018 - Compiled successfully.

###################################################################################################
*/

void main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::
    DRM_PointValues(
        main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad *LoadPackage)
{

  int TotalCycle;
  int Direction;

  double arg1; // wave phase for the moving in the positive direction
  double arg2; // wave phase for the moving in the negative direction

  double LowerLimit; // Lower limit of the phase
  double UpperLimit; // Upper limit of the phase

  double wr;    // Central frequency of the Ricker pulse
  double t_max; // Loading duration
  double fr;

  double ur;

  // The analytical solution is u (x,t) = Ui (f_inc (t - x/c) + f_inc (t + x/c) )

  // phases

  switch (LoadPackage->Wave_Func)
  {
  case 0: // sine function

    wr = 2.0 * pi * LoadPackage->omega; // characteristic central circular frequency

    // positive direction phase - incident wave
    arg1 = LoadPackage->Time - LoadPackage->x / LoadPackage->c;
    // negative direction phase - reflected wave
    arg2 = LoadPackage->Time + LoadPackage->x / LoadPackage->c;

    arg1 *= wr;
    arg2 *= wr;

    LowerLimit = LoadPackage->alpha1;
    UpperLimit = LoadPackage->alpha2;

    if (LowerLimit <= arg1 && arg1 <= UpperLimit)
    {
      LoadPackage->u += LoadPackage->amplitude * sin(arg1);
      LoadPackage->v += wr * LoadPackage->amplitude * cos(arg1);
      LoadPackage->a -= wr * wr * LoadPackage->amplitude * sin(arg1);
    }

    if (LowerLimit <= arg2 && arg2 <= UpperLimit)
    {
      LoadPackage->u += LoadPackage->amplitude * sin(arg2);
      LoadPackage->v += wr * LoadPackage->amplitude * cos(arg2);
      LoadPackage->a -= wr * wr * LoadPackage->amplitude * sin(arg2);
    }

    break;
  case 1: // Ricker

    TotalCycle = (int)(LoadPackage->alpha1);
    Direction = (int)(LoadPackage->alpha2);

    fr = LoadPackage->omega; // Central frequency of Ricker pulse
    wr = 2.0 * pi * fr;      // characteristic central circular frequency

    //arg1 = wr * Time - wr * x/c ; // positive direction phase - incident wave
    //arg2 = wr * Time + wr * x/c ; // negative direction phase - reflected wave

    // positive direction phase - incident wave
    arg1 = LoadPackage->Time - LoadPackage->x / LoadPackage->c;
    // negative direction phase - reflected wave
    arg2 = LoadPackage->Time + LoadPackage->x / LoadPackage->c;

    //wr = omega ;           // characteristic central circular frequency

    t_max = 6.0 * sqrt(6.0) / wr; // duration of loading

    LowerLimit = {0.0};
    UpperLimit = {t_max};

    if (LowerLimit <= arg1 && arg1 <= UpperLimit)
    {

      ur = wr * arg1 - 3.0 * sqrt(6.0);

      LoadPackage->u +=
          LoadPackage->amplitude *
          ((0.25 * ur * ur - 0.5) * exp(-0.25 * ur * ur) - 13.0 * exp(-13.5)) / (0.5 + 13.0 * exp(-13.5));

      LoadPackage->v +=
          LoadPackage->amplitude *
          (wr * (0.75 * ur - 0.125 * pow(ur, 3.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));

      LoadPackage->a +=
          LoadPackage->amplitude *
          (pow(wr, 2.0) * (0.75 - 0.75 * pow(ur, 2.0) + 0.0625 * pow(ur, 4.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));
    }
    else
    {
      for (int j = 2; j <= TotalCycle; j++)
      {
        arg1 = LoadPackage->Time - LoadPackage->x / LoadPackage->c - (j - 1) * t_max;
        if (LowerLimit <= arg1 && arg1 <= UpperLimit)
        {
          ur = wr * arg1 - 3.0 * sqrt(6.0);

          LoadPackage->u +=
              (pow(Direction, (j - 1))) *
              LoadPackage->amplitude * ((0.25 * ur * ur - 0.5) * exp(-0.25 * ur * ur) - 13.0 * exp(-13.5)) / (0.5 + 13.0 * exp(-13.5));

          LoadPackage->v +=
              (pow(Direction, (j - 1))) *
              LoadPackage->amplitude * (wr * (0.75 * ur - 0.125 * pow(ur, 3.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));

          LoadPackage->a +=
              (pow(Direction, (j - 1))) *
              LoadPackage->amplitude * (pow(wr, 2.0) * (0.75 - 0.75 * pow(ur, 2.0) + 0.0625 * pow(ur, 4.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));
        }
      }
    }

    if (LowerLimit <= arg2 && arg2 <= UpperLimit)
    {

      ur = wr * arg2 - 3.0 * sqrt(6.0);

      LoadPackage->u +=
          LoadPackage->amplitude *
          ((0.25 * ur * ur - 0.5) * exp(-0.25 * ur * ur) - 13.0 * exp(-13.5)) / (0.5 + 13.0 * exp(-13.5));

      LoadPackage->v +=
          LoadPackage->amplitude *
          (wr * (0.75 * ur - 0.125 * pow(ur, 3.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));

      LoadPackage->a += LoadPackage->amplitude *
                        (pow(wr, 2.0) * (0.75 - 0.75 * pow(ur, 2.0) + 0.0625 * pow(ur, 4.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));
    }
    else
    {
      for (int j = 2; j <= TotalCycle; j++)
      {
        arg2 = LoadPackage->Time + LoadPackage->x / LoadPackage->c - (j - 1) * t_max;
        if (LowerLimit <= arg2 && arg2 <= UpperLimit)
        {
          ur = wr * arg2 - 3.0 * sqrt(6.0);

          LoadPackage->u +=
              (pow(Direction, (j - 1))) * LoadPackage->amplitude *
              ((0.25 * ur * ur - 0.5) * exp(-0.25 * ur * ur) - 13.0 * exp(-13.5)) / (0.5 + 13.0 * exp(-13.5));

          LoadPackage->v +=
              (pow(Direction, (j - 1))) * LoadPackage->amplitude *
              (wr * (0.75 * ur - 0.125 * pow(ur, 3.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));

          LoadPackage->a += (pow(Direction, (j - 1))) * LoadPackage->amplitude *
                            (pow(wr, 2.0) * (0.75 - 0.75 * pow(ur, 2.0) + 0.0625 * pow(ur, 4.0)) * exp(-0.25 * ur * ur)) / (0.5 + 13.0 * exp(-13.5));
        }
      }
    }

    break;
  default:
    std::cout << "Wave function is not defined." << "\n";
  }
}

/*
###################################################################################################
Purpose: This function computes the load factor to apply the pressure load on the surface.

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 07/04/2018 - Subroutine initiated.
V1.00: 07/04/2018 - Compiled successfully.

###################################################################################################
*/

void main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::
    DRM_Loads_Implicit(
        main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad *LoadPackage)
{
  // the analytical acceleration at the boundary nodes. In this 1D problem, there is only one node.

  // Defining the required vectors
  std::vector<double> U_b(LoadPackage->NNBndry * LoadPackage->NDim);
  
  // Ud_b is not needed bcs there is no damping in the system.
  std::vector<double> Ud_b(LoadPackage->NNBndry * LoadPackage->NDim);
  std::vector<double> Udd_b(LoadPackage->NNBndry * LoadPackage->NDim);

  // holds the loads for the boundary nodes.
  std::vector<double> F_e(LoadPackage->NNLayer * LoadPackage->NDim);

  for (std::vector<double> :: iterator it = F_e.begin(); it < F_e.end(); it++)
  {
    *it = {0.0};
  }





  // Loop on the nodes on the DRM boundary to find out the analytical soln (In 1D only one node)
  for (int i = 0; i < LoadPackage->NNBndry; i++)
  {
    for (int j = 0; j < LoadPackage->NDim; j++)
    {
      LoadPackage->x = LoadPackage->XYZ[LoadPackage->NoBndry_DRM[i]][j]; // Coordinate of the node
      LoadPackage->u = LoadPackage->v = LoadPackage->a = 0.0;            // Initialize the values

      // Computing the analytical solution at this particular node
      // Remark: the one-dimensional wave-motion is identical for both SV and P waves.

      // The point loads are identical for both shear and pressure waves.
      // Just for the sake of clarity, we wrtie it as follows.
      if (LoadPackage->Wave_Type == 0) // SV wave
        DRM_PointValues(LoadPackage);
      else if (LoadPackage->Wave_Type == 1) // P wave
        DRM_PointValues(LoadPackage);

      // Filling the analytical solution vector
      U_b[i * LoadPackage->NNBndry * LoadPackage->NDim + j] = LoadPackage->u;
      Ud_b[i * LoadPackage->NNBndry * LoadPackage->NDim + j] = LoadPackage->v;
      Udd_b[i * LoadPackage->NNBndry * LoadPackage->NDim + j] = LoadPackage->a;
    }
  }

  // Multiply the Mass, Damp, and Stiffness matrix by the vector
  for (int i = 0; i < LoadPackage->NNLayer * LoadPackage->NDim; i++)
  {
    for (int j = 0; j < LoadPackage->NNBndry * LoadPackage->NDim; j++)
    {
      F_e[i] += LoadPackage->M_eb[i][j] * Udd_b[j] +
                LoadPackage->C_eb[i][j] * Ud_b[j] + LoadPackage->K_eb[i][j] * U_b[j];
    }
  }

  // Assemble the load vector
  for (int i = 0; i < LoadPackage->NNLayer * LoadPackage->NDim; i++)
  {
    LoadPackage->UN[LoadPackage->ND_e[i]] += F_e[i];
  }

  // the analytical displacement at the boundary nodes. In this 1D problem, there is only one node.
  std::vector<double> U_e(LoadPackage->NNLayer * LoadPackage->NDim); // Not needed because we do not have damping in the system.
  std::vector<double> Ud_e(LoadPackage->NNLayer * LoadPackage->NDim);
  std::vector<double> Udd_e(LoadPackage->NNLayer * LoadPackage->NDim);
  // holds the loads for the layer nodes.
  std::vector<double> F_b(LoadPackage->NNBndry * LoadPackage->NDim);

  for (int i = 0; i < LoadPackage->NNBndry * LoadPackage->NDim; i++)
  {
    F_b[i] = 0.0;
  }

  // Loop on the nodes on the DRM layer to find out the analytical solution (In 1D only two nodes)
  for (int i = 0; i < LoadPackage->NNLayer; i++)
  {
    for (int j = 0; j < LoadPackage->NDim; j++)
    {
      LoadPackage->x = LoadPackage->XYZ[LoadPackage->NoLayer_DRM[i]][j]; // Coordinate of the node
      LoadPackage->u = LoadPackage->v = LoadPackage->a = 0.0;            // Initialize the values

      // Computing the analytical solution
      // Comment: the one-dimensional wave-motion is identical for both SV and P waves.
      if (LoadPackage->Wave_Type == 0) // SV wave
        DRM_PointValues(LoadPackage);
      else if (LoadPackage->Wave_Type == 1) // P wave
        DRM_PointValues(LoadPackage);

      // Filling the analytical solution vector
      U_e[i * LoadPackage->NNBndry * LoadPackage->NDim + j] = LoadPackage->u;
      Ud_e[i * LoadPackage->NNBndry * LoadPackage->NDim + j] = LoadPackage->v;
      Udd_e[i * LoadPackage->NNBndry * LoadPackage->NDim + j] = LoadPackage->a;
    }
  }

  // Multiply the Mass, Damp, and Stiffness matrix by the vector
  for (int i = 0; i < LoadPackage->NNBndry * LoadPackage->NDim; i++)
  {
    for (int j = 0; j < LoadPackage->NNLayer * LoadPackage->NDim; j++)
    {
      F_b[i] += -(LoadPackage->M_eb[j][i] * Udd_e[j] +
                  LoadPackage->C_eb[j][i] * Ud_e[j] + LoadPackage->K_eb[j][i] * U_e[j]);
    }
  }

  // Assemble the load vector
  for (int i = 0; i < LoadPackage->NNBndry * LoadPackage->NDim; i++)
  {
    LoadPackage->UN[LoadPackage->ND_b[i]] += F_b[i];
  }
}

/*
###################################################################################################
Purpose: This function computes the point loads in the frequency domain

Developed by: Babak Poursartip
 
The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin	
================================= V E R S I O N ===================================================
V0.00: 07/04/2018 - Subroutine initiated.
V1.00: 07/10/2018 - Compiled successfully.

###################################################################################################
*/

void main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::
    DRM_PointValues_for_frequency_domain(
        main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::
            InputLoad_frequency_domain *LoadPackage)
{

  double k; // wavenumber

  // The analytical solution is u (x,t) = u_i (exp(i k x) + exp (-i k x)) = 2 u_i cos(kx)

  k = LoadPackage->omega / LoadPackage->c; // wavenumber

  // The real part of the analytical solution in the frequency domain
  LoadPackage->u_R = 2.0 * LoadPackage->amplitude * cos(k * LoadPackage->x);
  // The imaginary part of the analytical solution in the frequency domain
  LoadPackage->u_I = 0.0;
}
