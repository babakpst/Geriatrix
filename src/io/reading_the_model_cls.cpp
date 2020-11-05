

#include "../../include/io/reading_the_model_cls.h"

// Constructor
main_ns::model_ns::model_cls::model_cls(const io::address_cls *input)
    : input{input} {

  std::cout << " Reading the model ..."
            << "\n";

  NNBndry = {1}; // Number of nodes on the bounday of the DRM
  NNLayer = {2}; // Number of nodes on the bounday layer of the DRM

  // Input File
  std::cout << " Opening the input file ..."
            << "\n";
  InputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    InputFile.open(input->Input_Dir.c_str(), std::ios::in);
  } catch (std::ifstream::failure
               &inputerr) { // here is the catch for opening the input file.
    std::cout << " Error while opening the input file. "
              << "\n";
    std::cout << " Please double check the input file in the input folder. "
              << "\n";
    std::cout << " The error message is: " << inputerr.what() << "\n";
  }
}

main_ns::model_ns::model_cls::~model_cls() {

  for (int i = 0; i < NMat; i++) {
    delete[] PMat[i];
  }
  delete[] PMat;
}

/*
###################################################################################################

Purpose: This function reads the basic data for the model, so that we can form
the arrays.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 05/14/2018 -
Subroutine initiated. V0.01: 05/15/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/

void main_ns::model_ns::model_cls::InputBasic() {

  double Total_Time; // Total simulation time

  std::string TempS; // Temporary variable for reading strings from input files

  // = Code
  // =======================================================================================

  std::cout << " Basic data..."
            << "\n";

  getline(InputFile, TempS);
  getline(InputFile, TempS);
  getline(InputFile, TempS);
  getline(InputFile, TempS);

  InputFile >> NMat >> NPM >> NNodePWaveL >> LoadType >> Dis_History >> Solver;

  NInt = {3};
  NDim = {1};
  NDOF = {1};
  NNode = {3};

  getline(InputFile, TempS);
  getline(InputFile, TempS);
  getline(InputFile, TempS);

  InputFile >> Beta >> Gama >> DT >> Total_Time;
  NStep = (int)(Total_Time / DT);

  getline(InputFile, TempS);
  getline(InputFile, TempS);
  getline(InputFile, TempS);

  InputFile >> L >> Alpha >> P >> A >> OrderOfShapeFunc;

  getline(InputFile, TempS);
  getline(InputFile, TempS);
  getline(InputFile, TempS);
  InputFile >> Wave_Type >> Wave_Func >> alpha1 >> alpha2 >> amplitude >>
      omega >> NEl_DRM;

  std::cout << "\n";
  std::cout << " Here is the model: "
            << "\n";

  std::cout << " Number of materials: " << NMat << "\n"
            << " Number of properties of material: " << NPM << "\n"
            << " Requried number of nodes per wavelenght: " << NNodePWaveL
            << "\n"
            << " Load Type is :" << LoadType << "\n"
            << " Number of nodes for recording the history of displacement: "
            << Dis_History << "\n"
            << " The solver type is: " << Solver << "\n"
            << " Number of integration points: " << NInt << "\n"
            << " The dimension of the model: " << NDim << "\n"
            << " The degrees of freedom of each node: " << NDOF << "\n"
            << " Number of nodes per element: " << NNode << "\n"
            << " Newmark variables: " << Beta << Gama << "\n"
            << " Time step: " << DT << "\n"
            << " Total simulation time: " << Total_Time << "\n"
            << " Total Number of stets: " << NStep << "\n"
            << "\n";

  std::cout << " Done with the model reading, successfully."
            << "\n"
            << "\n";
}

/*
###################################################################################################

Purpose: This function reads the data in the forms of arrays for the model.

Developed by: Babak Poursartip

The Institute for Computational Engineering and Sciences (ICES)
The University of Texas at Austin
================================= V E R S I O N
=================================================== V0.00: 05/14/2018 -
Subroutine initiated. V0.01: 05/15/2018 - Initiated: Compiled without error for
the first time.

###################################################################################################
*/
void main_ns::model_ns::model_cls::InputArrays() {

  int imat, i;   // loop variable
  int NEl_Layer; // Number of elements in each layer

  double Layer;       // Layer size
  double m1, m2;      // material properties
  double Layer_check; // Layer size
  double G;           // Module (Shear or Elastic)
  double rho;         // Density
  double c;           // Wave velocity
  double wavelength;  // wavelength of the wave
  double h;           // element size

  std::string TempS; // Temporary variable for reading strings from input files

  // = Code
  // =======================================================================================

  // Allocating required 1D arrays - vectors
  std::cout << " -allocating model arrays ..."
            << "\n";
  Length.resize(NMat); // Material Type of Elements

  Loc_History.resize(Dis_History);

  PMat = new double *[NMat]; // Properties of Materials
  for (int i = 0; i < NMat; i++) {
    PMat[i] = new double[NPM];
  }

  Element_Layer.resize(NMat); // Total number of layers in the model should be
                              // equal to the number of materials.
  Layer_Depth.resize(NMat);

  std::cout << " -reading input files (arrays) ..."
            << "\n";

  getline(InputFile, TempS);
  getline(InputFile, TempS);

  std::cout << " Material properties ..."
            << "\n";
  for (i = 0; i < NMat; i++) {
    InputFile >> imat >> m1 >> m2;
    PMat[imat - 1][0] = m1;
    PMat[imat - 1][1] = m2;
  }

  std::cout << " Layeres ..."
            << "\n";
  getline(InputFile, TempS);
  getline(InputFile, TempS);
  Layer_check = 0.0;
  for (i = 0; i < NMat; i++) {
    InputFile >> Layer;
    Layer_check += Layer;
    Layer_Depth[i] = Layer;
    Length[i] = -L + Layer_check;
  }

  if (Layer_check !=
      L) { // To see if the length of layers match up with the total length
    std::cout
        << " Warning: Total sum of layers is not equal to the total length:  "
        << L << " /= " << Layer_check << "\n";
    return;
  }

  // Reading the location of nodes for recording the history of displacement
  std::cout << " Time history locations ..."
            << "\n";
  getline(InputFile, TempS);
  getline(InputFile, TempS);
  for (i = 0; i < Dis_History; i++) {
    InputFile >> Loc_History[i];
  }

  // compute discretization information
  NEl = 0;
  for (i = 0; i < NMat; i++) {
    G = PMat[i][0];
    rho = PMat[i][1];
    c = sqrt(G / rho);
    wavelength = c / omega;
    h = 2 * wavelength / NNodePWaveL;            // max allowable element size
    NEl_Layer = (int)(ceil(Layer_Depth[i] / h)); // NEl_Layer
    Element_Layer[i] = NEl_Layer;
    NEl += Element_Layer[i];
  }

  NJ = OrderOfShapeFunc * NEl + 1;

  InputFile.close();

  std::cout << " Total number of elements= " << NEl << "\n";
  std::cout << " Total number of joints  = " << NJ << "\n";

  std::cout << " Done with reading arrays, successfully. "
            << "\n"
            << "\n";
}
