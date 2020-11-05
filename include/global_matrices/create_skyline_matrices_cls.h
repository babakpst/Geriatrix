
#include <fstream>
#include <iostream>

#include "create_global_matrices_cls.h"

#ifndef CREATE_SKYLINE_MATRICES_CLS_H
#define CREATE_SKYLINE_MATRICES_CLS_H

namespace main_ns {

namespace Matrices_ns {

class Matrices_Skyline_cls : public main_ns::Matrices_ns::Matrices_cls {

  // members
public:
  std::vector<int> JD;  // Skyline matrix
  std::vector<int> NTK; // Skyline matrix

  std::vector<double> K; // global stiffness matrix -skyline
  std::vector<double> C; // global damping matrix -skyline
  std::vector<double> M; // global mass matrix -skyline

  // methods
private:
  void Skyline_fn();

protected:
  virtual void allocating_global_matrices_fn();
  virtual void create_DRM_matrices_fn();

public:
  Matrices_Skyline_cls(main_ns::discretization_ns::discretization_cls *,
                       main_ns::model_ns::model_cls *);

  virtual void assemble_local_to_global_fn();
};
} // namespace Matrices_ns
} // namespace main_ns

#endif
