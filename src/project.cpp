#include <deal.II/base/convergence_table.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Poisson3D.hpp"

// Main function.
int
main(int argc, char *argv[])
{
  // This object calls MPI_Init when it is constructed, and MPI_Finalize when it
  // is destroyed. It also initializes several other libraries bundled with
  // dealii (e.g. p4est, PETSc, ...).
  Utilities::MPI::MPI_InitFinalize mpi_init(argc, argv);

  //const unsigned int N      = 9;
  const std::vector<unsigned int> N_values = {4, 9, 19, 39};
  const unsigned int degree = 1;

  for (const unsigned int &N : N_values){

  Poisson3D problem(N, degree);

  problem.setup();
  problem.assemble();
  problem.solve();
  problem.output();

  }

  return 0;

}