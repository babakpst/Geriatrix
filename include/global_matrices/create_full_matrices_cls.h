
// libraries
#include <fstream>
#include <iostream>

// classes
#include "create_global_matrices_cls.h"

#pragma once

namespace main_ns {

namespace Matrices_ns {

class Matrices_Full_cls : public main_ns::Matrices_ns::Matrices_cls {

protected:
  virtual void allocating_global_matrices_fn();
  virtual void create_DRM_matrices_fn();

public:
  double **K; // global stiffness matrix
  double **C; // global damping matrix
  double **M; // global mass matrix

public:
  Matrices_Full_cls(main_ns::discretization_ns::discretization_cls *,
                    main_ns::model_ns::model_cls *);

  virtual void assemble_local_to_global_fn();
  virtual ~Matrices_Full_cls();
};
} // namespace Matrices_ns
} // namespace main_ns