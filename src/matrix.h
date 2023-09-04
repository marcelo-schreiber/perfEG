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

typedef struct
{
  Matrix m;
  Vector v;
} LinearEquation;

void printMatrix(Matrix m);
void printVector(Vector v);
void readLinearEquation(Matrix *m, Vector *v);
void printLinearEquation(Matrix m, Vector v);
void gaussEliminationWithPivoting(Matrix *m, Vector *c);
Vector *printSolutionBySubstitution(Matrix m, Vector c);
void printResidual(Matrix m, Vector c, Vector solution);
LinearEquation copyLinearEquation(LinearEquation la);
void gaussEliminationWithPivotingWithoutMult(Matrix *m, Vector *c);
void gaussEliminationWithoutPivoting(Matrix *m, Vector *c);