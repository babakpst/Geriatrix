
#include "../include/solver_cls.h"

#ifndef SOLVER_SKYLINE_SYSTEM_H
#define SOLVER_SKYLINE_SYSTEM_H
namespace main_ns
{

namespace Solver_ns
{

class solve_Skyline_matrices_cls : public main_ns::Solver_ns::Solver_cls
{

  // members

  // methos
private:
  virtual void Compute_the_effective_matrix();
  virtual void Reduce_the_effective_forece();
  void Matrix_Multiplication(std::vector<double> &, std::vector<double> &, std::vector<double> &);
  virtual void Effective_forces_fn(std::vector<double> &);
  virtual void Solve_the_system_for_this_RHS_using_Gaussina_Elimination(std::vector<double> &);

public:
  //main_ns::Matrices_ns::Matrices_Skyline_cls* Matrices;

  solve_Skyline_matrices_cls(main_ns::address_ns::address_cls *,
                             main_ns::model_ns::model_cls *,
                             main_ns::discretization_ns::discretization_cls *,
                             main_ns::Matrices_ns::Matrices_cls *);

  ~solve_Skyline_matrices_cls();
};
} // namespace Solver_ns

} // namespace main_ns

#endif
