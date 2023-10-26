#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "well1D.hpp"
#include "constants.hpp"
#include "zeros.hpp"

int main()
{
  // PARAMETERS
  int N_E = 1000;
  double E_min = meV_to_Ha(0.0);
  double E_max = meV_to_Ha(35.0);
  double dE = (E_max - E_min) / N_E;
  double eps_E = meV_to_Ha(1.0e-6);

  double L = nm_to_ab(100.0);

  int N1 = 100;
  int N2 = 300;
  Well1D well1(L, N1);
  Well1D well2(L, N2);

  int N_W = 1e2;
  double W_min = meV_to_Ha(0.0);
  double W_max = meV_to_Ha(1000.0);
  double dW = (W_max - W_min) / N_W;

  // CALCULATING WF_N

  std::fstream WF_N_file("data/WF_N.dat", std::ios::out);

  for (int i_E = 0; i_E < N_E + 1; ++i_E)
  {
    double E = E_min + i_E * dE;
    WF_N_file << Ha_to_meV(E) << " " << well1.getWF_N(E) << std::endl;
  }

  WF_N_file.close();

  // FINDING ZEROS

  std::fstream zeros_file("data/zeros.dat", std::ios::out);

  std::vector<double> zeros1 = findZerosWF_N(well1, E_min, E_max, dE, eps_E);
  std::vector<double> zeros2 = findZerosWF_N(well2, E_min, E_max, dE, eps_E);

  for (size_t i = 0; i < zeros2.size(); ++i)
  {
    zeros_file << i + 1 << " " << Ha_to_meV(zeros1[i]) << " " << Ha_to_meV(zeros2[i]) << " ";
    zeros_file << Ha_to_meV(1.0 / 2.0 / m * pow((i + 1) * h_bar * M_PI / L, 2)) << std::endl;
  }

  // CALCULATING WF NEAR ZERO

  double E = zeros1[2];

  well1.calcWF(E * 0.95, true);
  well1.printWF("data/WF_down.dat");

  well1.calcWF(E, true);
  well1.printWF("data/WF.dat");

  well1.calcWF(E * 1.05, true);
  well1.printWF("data/WF_up.dat");

  // ZEROS vs POTENTIAL BARRIER DEPTH

  std::fstream zeros_PB_file("data/zeros_PB.dat", std::ios::out);

  for (size_t i_W = 0; i_W < N_W + 1; ++i_W)
  {
    double W = W_min + i_W * dW;
    well2.setPointBarierV(-W, N2 / 2);
    std::vector<double> zeros = findZerosWF_N(well2, -W, E_max, dE, eps_E, 7);

    zeros_PB_file << Ha_to_meV(W) << " ";

    for (auto zero : zeros)
    {
      zeros_PB_file << Ha_to_meV(zero) << " ";
    }

    zeros_PB_file << std::endl;
  }

  zeros_PB_file.close();

  // WAFEFUNCTIONS WITH POTENTIAL BARRIER - 4 lowest states

  double W = meV_to_Ha(500.0);
  well2.setPointBarierV(-W, N2 / 2);

  std::vector<double> energies = findZerosWF_N(well2, -W, E_max, dE, eps_E, 4);

  for (int i = 0; i < energies.size(); i++)
  {
    well2.calcWF(energies[i], true);
    well2.printWF("data/WF_PB_" + std::to_string(i + 1) + ".dat");
  }

  // WAVEFUNCTIONS VS POTENTIAL BARRIER DEPTH - 2 lowest states

  size_t k_W = 10;

  for (size_t i_W = 0; i_W < k_W + 1; i_W++)
  {
    double W = W_min + i_W * W_max / k_W;
    well2.setPointBarierV(-W, N2 / 2);
    std::vector<double> energies = findZerosWF_N(well2, -W, E_max, dE, eps_E, 2);

    for (int i = 0; i < energies.size(); i++)
    {
      well2.calcWF(energies[i], true);

      std::string filename = "data/WF_PB_W_" + std::to_string(i_W) + "_S_" + std::to_string(i + 1) + ".dat";

      well2.printWF(filename);
    }
  }

  return 0;
}
