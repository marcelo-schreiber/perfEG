#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <likwid.h>
#include "matrix.h"

enum solveMethods
{
  pivot,
  pivotNoMult,
  noPivot,
};

void solve(int solveMethod, LinearEquation triangleLe)
{
  LinearEquation originalLe = copyLinearEquation(triangleLe);
  Vector *solution;

  switch (solveMethod)
  {
  case pivot:
    printf("Solving with pivoting\n");
    gaussEliminationWithPivoting(&triangleLe.m, &triangleLe.v);
    break;
  case pivotNoMult:
    printf("Solving with pivoting and no multiplication\n");
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

  // printLinearEquation(triangleLe.m, triangleLe.v);
  // printLinearEquation(originalLe.m, originalLe.v);

  printResidual(originalLe.m, originalLe.v, *solution);
}

int main(void)
{
  LinearEquation triangleLe;
  readLinearEquation(&triangleLe.m, &triangleLe.v);

  solve(pivot, triangleLe);
  solve(pivotNoMult, triangleLe);
  solve(noPivot, triangleLe);
  return 0;
}