
#include <iostream>
#include <string>
#include <sstream>

#include "../include/discretize_the_domain_cls.h"
#include "../include/ShapeFunctions_cls.h"
#include "../include/ShapeFunctions_FirstOrder_cls.h"
#include "../include/ShapeFunctions_SecondOrder_cls.h"

#ifndef CREATE_GLOBAL_MATRICES_H
#define CREATE_GLOBAL_MATRICES_H

namespace main_ns
{

namespace Matrices_ns
{

class Matrices_cls
{
// members
private:
  int   MType; // material type
  double E;    // elastic modulus
  double Rho;  // density

public:
  int NEqEl; // Number of equations of each element

  double **K_eb; // global stiffness matrix
  double **C_eb; // global damping matrix
  double **M_eb; // global mass matrix

  std::vector<double> F; // global force vector

  int LoadFunc; // Load Function  0:DRM

  double **XT; // Array to store coordinates of the element
  double **Ke; // stiffness matrix of each element
  double **Ce; // damping matrix of each element
  double **Me; // mass matrix of each element

  std::vector<double> Fe;  // element force vector

  std::vector<int> ND_b; // Nodal ID for DRM
  std::vector<int> ND_e; // Nodal ID for DRM

  std::vector<int> ND; // element constraints

  main_ns::discretization_ns::discretization_cls *DiscretizedModel;
  main_ns::model_ns::model_cls *Model;

  main_ns::ShapeFunctions_ns::ShapeFunctions_cls *SF;

// methods
private:
  void compute_elemental_matrices_fn(int, double, double);

public:
  Matrices_cls(main_ns::discretization_ns::discretization_cls *, main_ns::model_ns::model_cls *);

  void allocating_local_matrices_fn();

  virtual void allocating_global_matrices_fn(void) = 0;
  virtual void assemble_local_to_global_fn(void) = 0;
  void allocate_matrices_for_assembling_fn();
  void assembling_local_matrices_into_global_matrices_fn();

  virtual void create_DRM_matrices_fn(void) = 0;

  virtual ~Matrices_cls();
};

} // namespace Matrices_ns
} // namespace main_ns

#endif