
#include <cmath>
#include <iostream>
#include <string>

#include "../include/reading_the_model_cls.h"

#ifndef LOAD_H
#define LOAD_H

namespace main_ns
{

namespace Solver_ns
{

// This data type packages all the required data to compute the DRM load at a point

class apply_seismic_loads_to_the_domain_cls
{

  // members
public:
  double LoadFactor; // We use this apply pressure loads
  const double pi = {3.14159265359};

  struct InputLoad
  {
    int NDim;      // The dimension of the model (always 1 in this code)
    int NNBndry;   // Number of nodes on the DRM interface (always 1 in the 1D model)
    int NNLayer;   // Number of nodes on the DRM layer (always 2 in the 1D model)
    int Wave_Type; // shear/pressure waves, in the 1D simulation, this does not matter
    int Wave_Func; // determine the shape of the incoming wave

    double alpha1;    // the lower bound of the phase of the incoming wave
    double alpha2;    // the upper bound of the phase of the incoming wave
    double amplitude; // amplitude of the incoming wave
    double c;         // the speed of wave
    double omega;     // the frequency of the incoming wave

    double Time; // Time instant that we want to calculate the DRM forces
    double x;    // The coordinate
    double u;    // Analytical displacement
    double v;    // Analytical velocity
    double a;    // Analytical acceleration


    std::vector<int> NoBndry_DRM;
    std::vector<int> NoLayer_DRM;
    
    std::vector<int> ND_e;
    std::vector<int> ND_b;
    
    std::vector<double> UN;


    double **XYZ;
    double **M_eb;
    double **C_eb;
    double **K_eb;
  };

  struct InputLoad_frequency_domain
  {
    double amplitude; // amplitude of the incoming wave
    double c;         // the speed of wave
    double omega;     // the frequency of the incoming wave

    double x;   // The coordinate
    double u_R; // Analytical displacement - real part
    double u_I; // Analytical displacement - imaginary part
  };

  // methods
public:
  apply_seismic_loads_to_the_domain_cls();

  double LoadFunction(const double, const double, const double);

  void DRM_Loads_Implicit(main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad *);

  void DRM_PointValues(main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad *);

  void DRM_PointValues_for_frequency_domain(
      main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad_frequency_domain *);

}; // load class
} // namespace Solver_ns
} // namespace main_ns

#endif
