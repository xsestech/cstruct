//
// Created by Alex on 16.03.2024.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define INIT_CAP 4 // Should be greater than 3/2

typedef struct {
  size_t capaticty = 0;
  size_t size = 0;
  double *data = NULL;
} vector_dbl;

void vector_dbl_init(vector_dbl *v);
void vector_dbl_destroy(vector_dbl *v);
double vector_dbl_get(vector_dbl *v, size_t index);
bool vector_dbl_set(vector_dbl *v, size_t index, double value);
bool vector_dbl_push_back(vector_dbl *v, size_t index, double value);
bool vector_dbl_shrink(vector_dbl *v);
bool vector_dbl_resize(vector_dbl *v, size_t new_size);
size_t vector_dbl_size(vector_dbl *v);


#endif //VECTOR_H
