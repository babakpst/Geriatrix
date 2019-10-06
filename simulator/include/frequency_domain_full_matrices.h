
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "../include/Load.h"
#include "../include/discretize_the_domain_cls.h"
#include "../include/create_global_matrices_cls.h"
#include "../include/create_full_matrices_cls.h"

#ifndef FREQUENCY_DOMAIN_FULL
#define FREQUENCY_DOMAIN_FULL

namespace main_ns
{

namespace Solver_ns
{

class frequency_domain_analysis : public main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls
{

  // members
private:
  std::ofstream TransferFunc;

  double **K_Eff; // complex Effective stiffness (real + imaginary) - See notes
  std::vector<double> RHS;
  main_ns::Solver_ns::apply_seismic_loads_to_the_domain_cls::InputLoad_frequency_domain
      LoadPackage;

public:
  main_ns::address_ns::address_cls *Addresses;
  main_ns::model_ns::model_cls *Model;
  main_ns::discretization_ns::discretization_cls *DiscretizedModel;
  main_ns::Matrices_ns::Matrices_cls *Matrices;

  // methods
private:
  void Reduce_the_effective_forece_in_the_freq_domain();
  void substitute_the_RHS_and_solve();

public:
  frequency_domain_analysis(main_ns::address_ns::address_cls *, main_ns::model_ns::model_cls *,
                            main_ns::discretization_ns::discretization_cls *,
                            main_ns::Matrices_ns::Matrices_cls *);

  void Compute_the_transfer_functions_in_the_frequency_domain();
  virtual ~frequency_domain_analysis();
};

} // namespace Solver_ns
} // namespace main_ns

#endif
