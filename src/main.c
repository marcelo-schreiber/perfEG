#include <stdlib.h>
#include <string.h>
#include "matrix.h"

enum solveMethods
{
  pivot,
  pivotNoMult,
  noPivot,
};

void solve(int solveMethod)
{
  LinearEquation originalLe;
  LinearEquation triangleLe;
  Vector *solution;

  readLinearEquation(&triangleLe.m, &triangleLe.v);
  originalLe = copyLinearEquation(triangleLe);

  switch (solveMethod)
  {
  case pivot:
    printf("Solving with pivoting\n");
    gaussEliminationWithPivoting(&triangleLe.m, &triangleLe.v);
    break;
  case pivotNoMult:
    printf("Solving with pivoting and no division\n");
    gaussEliminationWithPivotingWithoutMult(&triangleLe.m, &triangleLe.v);
    break;
  case noPivot:
    printf("Solving without pivoting\n");
    gaussEliminationWithoutPivoting(&triangleLe.m, &triangleLe.v);
    break;
  default:
    printf("Invalid solve method\n");
    exit(1);
  }

  solution = printSolutionBySubstitution(triangleLe.m, triangleLe.v);

  printLinearEquation(triangleLe.m, triangleLe.v);

  printResidual(originalLe.m, originalLe.v, *solution);
}

int main(void)
{
  solve(pivot);
  return 0;
}