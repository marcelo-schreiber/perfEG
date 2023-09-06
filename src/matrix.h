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

// printa a matriz
void printMatrix(Matrix m);

// printa o vetor de termos independentes
void printVector(Vector v);

// le uma equacao linear
void readLinearEquation(Matrix *m, Vector *v);

// printa a equacao linear 
void printLinearEquation(Matrix m, Vector v);

// executa a eliminacao de gauss sem pivoteamento
void gaussEliminationWithPivoting(Matrix *m, Vector *c);

// printa a solucao depois da retrossubstituicao
Vector *printSolutionBySubstitution(Matrix m, Vector c);

// printa o residuo
void printResidual(Matrix m, Vector c, Vector solution);

// copia a equacao linear
LinearEquation copyLinearEquation(LinearEquation la);

// executa a eliminacao de gauss com pivoteamento, mas sem os multiplicadores
void gaussEliminationWithPivotingWithoutMult(Matrix *m, Vector *c);

// executa a eliminacao de gauss sem pivoteamento
void gaussEliminationWithoutPivoting(Matrix *m, Vector *c);