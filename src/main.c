#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void) {
  Matrix a;
  Vector c;

  readLinearEquation(&a, &c);
  printLinearEquation(a, c);

  gaussEliminationWithPivoting(&a, &c);

  printLinearEquation(a, c);

  for (size_t i = 0; i < a.size; i++) {
    free(a.data[i]);
  }
  free(a.data);
  free(c.data);

  return 0;
}