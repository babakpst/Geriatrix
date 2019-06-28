
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "../include/Load.h"
#include "../include/discretize_the_domain_cls.h"
#include "../include/create_global_matrices_cls.h"

#include "../include/create_full_matrices_cls.h"
#include "../include/create_skyline_matrices_cls.h"

#ifndef SOLVER_H
#define SOLVER_H

namespace main_ns
{

namespace Solver_ns
{

class Solver_cls : public main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls
{

  // members
private:
  std::ofstream info;    // information file
  std::ofstream FullSol; // file to write the entire solution at all times
  std::ofstream History; // file to write the history of the solution at some particular nodes

public:
  // Newmark constants
  double A0;
  double A1;
  double A2;
  double A3;
  double A4;
  double A5;

  double E;   // Elastic Modulus of the base material required for the DRM loads
  double Rho; // density of the base material required for the DRM loads
  double c;   // wave velocity of the base material required for the DRM loads

  double Elapsed_Time; // The elapsed time in the simulation
  double Time;         // The actual simulation time, considering the effects of DRM
  double Initial_Time; // Starting time of the simulation, usually negative, because of the DRM

  std::vector<double> UN;   // temporay arrays for the Newmark algorithm

  std::vector<double> U;    // temporay arrays for the Newmark algorithm
  std::vector<double> UD;   // temporay arrays for the Newmark algorithm
  std::vector<double> UDD;  // temporay arrays for the Newmark algorithm
  std::vector<double> Temp; // temporay arrays for the Newmark algorithm

  std::vector<double> F; // global force vector

  //main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls* Loads;

  main_ns::address_ns::address_cls *Addresses;
  main_ns::model_ns::model_cls *Model;
  main_ns::discretization_ns::discretization_cls *DiscretizedModel;
  main_ns::Matrices_ns::Matrices_cls *Matrices;

  main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad LoadPackage;

  // methods
private:
  virtual void Compute_the_effective_matrix(void) = 0;
  virtual void Reduce_the_effective_forece(void) = 0;
  virtual void Effective_forces_fn(std::vector<double> &) = 0;
  virtual void Solve_the_system_for_this_RHS_using_Gaussina_Elimination(std::vector<double> &) = 0;

public:
  Solver_cls(main_ns::address_ns::address_cls *, main_ns::model_ns::model_cls *,
             main_ns::discretization_ns::discretization_cls *,
             main_ns::Matrices_ns::Matrices_cls *);

  void solve_the_system_using_implicit_newmark_method(); //either using the skyline or full system

  virtual ~Solver_cls();
};

} // namespace Solver_ns
} // namespace main_ns

#endif