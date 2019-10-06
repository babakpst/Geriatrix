
// include files
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>

#include "Address_cls.h"

#ifndef MODEL_H
#define MODEL_H

namespace main_ns
{

namespace model_ns
{

class model_cls
{
  // members
private:
  std::string TempS; // temporary variable for reading strings from input files
  std::ifstream InputFile;

  const main_ns::address_ns::address_cls *input;

public:
  int NDim;             // number of Dimension
  int NInt;             // number of integration points in Gauss integration scheme
  int NNode;            // number of nodes of element
  int NDOF;             // number of degrees of freedom
  int NMat;             // number of Materials
  int NPM;              // number of Properties of Materials
  int NStep;            // number of time steps
  int NEl;              // number of Elements
  int NJ;               // number of Joints(Nodes)
  int OrderOfShapeFunc; // order of Shape Functions
  int LoadType;         // Load Type 0:prssure- 1: DRM
  int Wave_Type;        // Wave type (0: SV- 1: P)
  int Wave_Func;        // Wave_Func (0: sine-1: Ricker)
  int Dis_History;      // Number of nodes for the history of displacement
  int Solver;           // Solver type 0: full matrices 1: skyline method
  int NNodePWaveL;      // Number of Nodes per wavelength
  int NEl_DRM;          // DRM boundary
  int NNBndry;          // Number of nodes on the bounday of the DRM
  int NNLayer;          // Number of nodes on the bounday layer of the DRM

  double DT;             // time step
  double Gama, Beta;     // Newmark parameters
  double Alpha, P;       // loading parameters
  double A;              // area of the cross section of the beam
  double L;              // length of the beam
  double alpha1, alpha2; //
  double amplitude;      // Amplitude of the incident wave
  double omega;          // central cyclic frequency in the Ricker pulse wave

  
  std::vector<int> Element_Layer; // Number of elements in each layer
  std::vector<int> Layer_Depth;   // Depth of each layer

  std::vector<double> Length;      // global force vector
  std::vector<double> Loc_History; // holds required locations to store the time history of displacement

  double **PMat; // properties of materials

  // methods
public:
  explicit model_cls(const main_ns::address_ns::address_cls *);

  void InputBasic();

  //template<int NMat, int NNBndry, int NNLayer, int Dis_History, int NPM>
  void InputArrays();
  virtual ~model_cls();
  
};
} // namespace model_ns
} // namespace main_ns
#endif
