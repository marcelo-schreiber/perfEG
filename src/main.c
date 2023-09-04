#include <stdlib.h>
#include "matrix.h"

int main(void)
{
  LinearEquation originalLe;
  LinearEquation triangleLe;
  Vector *solution;

  readLinearEquation(&triangleLe.m, &triangleLe.v);
  originalLe = copyLinearEquation(triangleLe);

  gaussEliminationWithPivoting(&triangleLe.m, &triangleLe.v);

  solution = printSolutionBySubstitution(triangleLe.m, triangleLe.v);

  printLinearEquation(triangleLe.m, triangleLe.v);

  printResidual(originalLe.m, originalLe.v, *solution);

  return 0;
}