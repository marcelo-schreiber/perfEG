#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// #include <likwid.h>
#include "utils.h"
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

  double tempo = timestamp();

  switch (solveMethod)
  {
  case pivot:
    printf("Solving with pivoting\n");
    gaussEliminationWithPivoting(&triangleLe.m, &triangleLe.v);
    tempo = timestamp() - tempo;
    printf("tempo de execucao: %lf\n", tempo);
    break;
  case pivotNoMult:
    printf("Solving with pivoting and no division\n");
    gaussEliminationWithPivotingWithoutMult(&triangleLe.m, &triangleLe.v);
    tempo = timestamp() - tempo;
    printf("tempo de execucao: %lf\n", tempo);
    break;
  case noPivot:
    printf("Solving without pivoting\n");
    gaussEliminationWithoutPivoting(&triangleLe.m, &triangleLe.v);
    tempo = timestamp() - tempo;
    printf("tempo de execucao: %lf\n", tempo);
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
  LinearEquation aux = copyLinearEquation(triangleLe);
  solve(pivot, aux);
  aux = copyLinearEquation(triangleLe);
  solve(pivotNoMult, aux);
  aux = copyLinearEquation(triangleLe);
  solve(noPivot, aux);

  return 0;
}
