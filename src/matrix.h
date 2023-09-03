typedef struct
{
  size_t size;
  double **data;
} Matrix;

typedef struct
{
  size_t size;
  double *data;
} Vector;

void printMatrix(Matrix m);
void printVector(Vector v);
void readLinearEquation(Matrix *m, Vector *v);
void printLinearEquation(Matrix m, Vector v);
void gaussEliminationWithPivoting(Matrix *m, Vector *c);
Vector *printSolutionBySubstitution(Matrix m, Vector c);
void printResidual(Matrix m, Vector c, Vector solution);