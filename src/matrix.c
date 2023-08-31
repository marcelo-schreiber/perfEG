#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void printMatrix(Matrix m) {
  for (size_t i = 0; i < m.size; i++) {
    for (size_t j = 0; j < m.size; j++) {
      printf("%lf ", m.data[i][j]);
    }
    printf("\n");
  }
}

void printVector(Vector v) {
  for (size_t i = 0; i < v.size; i++) {
    printf("%lf ", v.data[i]);
  }
  printf("\n");
}

void readLinearEquation(Matrix *m, Vector *v) {
  if (!scanf("%zu", &m->size)) {
    printf("Invalid input\n");
    exit(1);
  };

  v->size = m->size;

  m->data = (double **)malloc(m->size * sizeof(double *));
  v->data = (double *)malloc(v->size * sizeof(double));

  for (size_t i = 0; i < m->size; i++) {
    m->data[i] = (double *)malloc(m->size * sizeof(double));

    for (size_t j = 0; j < m->size; j++) {
      if (!scanf("%lf", &m->data[i][j])) {
        printf("Invalid input\n");
        exit(1);
      };
    }

    if (!scanf("%lf", &v->data[i]) ) {
      printf("Invalid input\n");
      exit(1);
    }
  }
}

void printLinearEquation(Matrix m, Vector v) {
  for (size_t i = 0; i < m.size; i++) {
    for (size_t j = 0; j < m.size; j++) {
      printf("%lf ", m.data[i][j]);
    }
    printf("= %lf\n", v.data[i]);
  }
  printf("\n");
}

void gaussElimination(Matrix a, Vector c) {
  for (size_t i = 0; i < a.size; i++) {
    for (size_t j = i + 1; j < a.size; j++) {
      double m = a.data[j][i] / a.data[i][i];

      for (size_t k = i; k < a.size; k++) {
        a.data[j][k] -= m * a.data[i][k];
      }

      c.data[j] -= m * c.data[i];
    }
  }
}

size_t findMax(Matrix m, size_t i) {
  size_t max = i;

  for (size_t j = i + 1; j < m.size; j++) {
    if (m.data[j][i] > m.data[max][i]) {
      max = j;
    }
  }

  return max;
}

void switchLine(Matrix *m, Vector *c, size_t i, size_t max) {
  double *temp = m->data[i];
  m->data[i] = m->data[max];
  m->data[max] = temp;

  double t = c->data[i];
  c->data[i] = c->data[max];
  c->data[max] = t;
}

void gaussEliminationWithPivoting(Matrix *m, Vector *c) {
  for (size_t i = 0; i < m->size; i++) {
    size_t max = findMax(*m, i);

    if (max != i) { // switch line
      switchLine(m, c, i, max);
    }

    for (size_t j = i + 1; j < m->size; j++) {
      double mult = m->data[j][i] / m->data[i][i];

      for (size_t k = i; k < m->size; k++) {
        m->data[j][k] -= mult * m->data[i][k];
      }

      c->data[j] -= mult * c->data[i];
    }
  }
  
}