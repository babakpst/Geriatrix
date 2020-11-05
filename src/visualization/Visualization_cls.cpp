
#include "../../include/visualization/Visualization_cls.h"

main_ns::visualization_ns::visualization_cls::visualization_cls(
    const main_ns::address_ns::address_cls *a,
    const main_ns::model_ns::model_cls *b,
    const main_ns::discretization_ns::discretization_cls *c)
    : address(a), model(b), discretized_model(c) {
  std::cout << " -writing the input file for Matlab visualizer script ..."
            << "\n";

  // address=a;
  // model=b;
  // discretized_model=c;

  // Output file for Matlab for visualization
  std::cout << " -opening the results file for Matlab ..."
            << "\n";
  OutputMatlab.open(address->OutputMatlab_Dir.c_str(), std::ios::out);
}

/*
################################################################################
Purpose: This function writes down all the required information for the Matlab
script to visualize the results.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 05/20/2018 -
Subroutine initiated. V0.01: 05/21/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::visualization_ns::visualization_cls::MatlabOutput_fn() {

  OutputMatlab << model->NMat << "\n";
  OutputMatlab << model->NEl << "\n";
  OutputMatlab << model->Dis_History << "\n";
  OutputMatlab << model->DT << "\n";
  OutputMatlab << model->NStep << "\n";
  OutputMatlab << model->L << "\n";
  OutputMatlab << discretized_model->NEqM << "\n";

  for (int i = 0; i < model->NMat; i++) {
    for (int j = 0; j < model->NPM; j++) {
      OutputMatlab << std::setw(20) << model->PMat[i][j];
    }
    OutputMatlab << "\n";
  }

  for (int i = 0; i < model->NMat; i++) {
    OutputMatlab << std::setw(20) << model->Length[i];
  }
  OutputMatlab << "\n";

  for (int i = 0; i < model->Dis_History; i++) {
    OutputMatlab << std::setw(20) << model->Loc_History[i];
  }
  OutputMatlab << "\n";

  for (int i = 0; i < model->NJ; i++) {
    OutputMatlab << discretized_model->XYZ[i][0] << "\n";
  }

  OutputMatlab << "\n";

  std::cout << " Matlab input file created successfully."
            << "\n"
            << "\n";
  OutputMatlab.close();
}
