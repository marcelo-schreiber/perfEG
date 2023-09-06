#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void printMatrix(Matrix m)
{
  for (size_t i = 0; i < m.size; i++)
  {
    for (size_t j = 0; j < m.size; j++)
    {
      /* print only tree digits*/
      printf("%.2lf ", m.data[i][j]);
    }
    printf("\n");
  }
}

void printVector(Vector v)
{
  for (size_t i = 0; i < v.size; i++)
  {
    printf("%.2lf ", v.data[i]);
  }
  printf("\n");
}

void readLinearEquation(Matrix *m, Vector *v)
{
  if (!scanf("%zu", &m->size))
  {
    printf("Invalid input\n");
    exit(1);
  };

  v->size = m->size;

  m->data = (double **)malloc(m->size * sizeof(double *));
  v->data = (double *)malloc(v->size * sizeof(double));

  for (size_t i = 0; i < m->size; i++)
  {
    m->data[i] = (double *)malloc(m->size * sizeof(double));

    for (size_t j = 0; j < m->size; j++)
    {
      if (!scanf("%lf", &m->data[i][j]))
      {
        printf("Invalid input\n");
        exit(1);
      };
    }

    if (!scanf("%lf", &v->data[i]))
    {
      printf("Invalid input\n");
      exit(1);
    }
  }
}

void printLinearEquation(Matrix m, Vector v)
{
  for (size_t i = 0; i < m.size; i++)
  {
    for (size_t j = 0; j < m.size; j++)
    {
      printf("%.2lf ", m.data[i][j]);
    }
    printf("= %.2lf\n", v.data[i]);
  }
  printf("\n");
}

size_t findMax(Matrix m, size_t i)
{
  size_t max = i;

  for (size_t j = i + 1; j < m.size; j++)
  {
    if (m.data[j][i] > m.data[max][i])
    {
      max = j;
    }
  }

  return max;
}

void switchLine(Matrix *m, Vector *c, size_t i, size_t max)
{
  double *temp = m->data[i];
  m->data[i] = m->data[max];
  m->data[max] = temp;

  double t = c->data[i];
  c->data[i] = c->data[max];
  c->data[max] = t;
}

void gaussEliminationWithPivoting(Matrix *m, Vector *c)
{
  for (size_t i = 0; i < m->size; i++)
  {
    size_t max = findMax(*m, i);

    if (max != i)
    { // switch line
      switchLine(m, c, i, max);
    }

    for (size_t j = i + 1; j < m->size; j++)
    {
      double mult = m->data[j][i] / m->data[i][i];
      m->data[j][i] = 0; // [j][i] = 0
      for (size_t k = i + 1; k < m->size; k++)
      {
        m->data[j][k] -= mult * m->data[i][k];
      }

      c->data[j] -= mult * c->data[i];
    }
  }
}

void gaussEliminationWithoutPivoting(Matrix *m, Vector *c)
{
  for (size_t i = 0; i < m->size; i++)
  {
    for (size_t j = i; j < m->size; j++)
    {
      if (i == j)
      {
        double pivot = m->data[i][i];
        for (size_t k = i; k < m->size; k++)
        {
          m->data[j][k] /= pivot;
        }

        c->data[i] /= pivot;

        continue;
      }

      double mult = m->data[j][i] / m->data[i][i];
      m->data[j][i] = 0; // [j][i] = 0

      for (size_t k = i + 1; k < m->size; k++)
      {
        m->data[j][k] -= mult * m->data[i][k];
      }

      c->data[j] -= mult * c->data[i];
    }
  }
}

void gaussEliminationWithPivotingWithoutMult(Matrix *m, Vector *c)
{
  for (size_t i = 0; i < m->size; i++)
  {
    size_t max = findMax(*m, i);

    if (max != i)
    { // switch line
      switchLine(m, c, i, max);
    }
    for (size_t j = i + 1; j < m->size; j++)
    {
      // m->data[j][i] = 0; // [j][i] = 0
      for (size_t k = i + 1; k < m->size; k++)
      {
        m->data[j][k] = m->data[j][k] * m->data[i][i] - m->data[i][k] * m->data[j][i];
      }

      c->data[j] = c->data[j] * m->data[i][i] - c->data[i] * m->data[j][i];
    }
  }
}

LinearEquation copyLinearEquation(LinearEquation la)
{
  LinearEquation lb;
  lb.m.size = la.m.size;
  lb.v.size = la.v.size;

  lb.m.data = (double **)malloc(lb.m.size * sizeof(double *));
  lb.v.data = (double *)malloc(lb.v.size * sizeof(double));

  for (size_t i = 0; i < lb.m.size; i++)
  {
    lb.m.data[i] = (double *)malloc(lb.m.size * sizeof(double));

    for (size_t j = 0; j < lb.m.size; j++)
    {
      lb.m.data[i][j] = la.m.data[i][j];
    }

    lb.v.data[i] = la.v.data[i];
  }

  return lb;
}

Vector *printSolutionBySubstitution(Matrix m, Vector c)
{
  Vector *solution = (Vector *)malloc(sizeof(Vector));
  solution->size = m.size;
  solution->data = (double *)malloc(solution->size * sizeof(double));

  for (int i = m.size - 1; i >= 0; i--)
  {
    double sum = 0;

    for (size_t j = i + 1; j < m.size; j++)
      sum += m.data[i][j] * solution->data[j];

    solution->data[i] = (c.data[i] - sum) / m.data[i][i];
  }
  printf("Solution: ");
  printVector(*solution);

  return solution;
}

void printResidual(Matrix m, Vector c, Vector solution)
{
  Vector *residual = (Vector *)malloc(sizeof(Vector));
  residual->size = m.size;
  residual->data = (double *)malloc(residual->size * sizeof(double));

  for (size_t i = 0; i < m.size; i++)
  {
    double sum = 0.0;

    for (size_t j = 0; j < m.size; j++)
      sum += m.data[i][j] * solution.data[j];

    residual->data[i] = c.data[i] - sum;
  }
  printf("Residual: ");
  printVector(*residual);
}