//
// Created by Alex on 16.03.2024.
//
#include "dynamic/vector.h"

bool index_check(const size_t size, const size_t index) {
  return index > 0 && index < size;
}

void vector_dbl_init(vector_dbl *v) {
  v->size = 0;
  v->capaticty = 0;
  v->data = NULL;
}

void vector_dbl_destroy(vector_dbl *v) {
  v->size = 0;
  v->capaticty = 0;
  free(v->data);
}

double vector_dbl_get(const vector_dbl *v, const size_t index) {
  if (!index_check(v->size, index)) return NAN;
  return v->data[index];
}

bool vector_dbl_set(const vector_dbl *v, size_t index, const double value) {
  if (!index_check(v->size, index)) return false;
  v->data[index] = value;
  return true;
}

bool vector_dbl_resize(vector_dbl *v, const size_t new_size) {
  double* new_data = realloc(v->data, sizeof(double) * new_size);
  if(new_data == NULL) {
    return false;
  }
  v->data = new_data;
  return true;
}
size_t vector_dbl_size(const vector_dbl *v) {
  return v->size;
}

bool vector_dbl_grow_buffer(vector_dbl *v) {
  size_t new_capacity = v->capaticty * 3/2;
  if(new_capacity == v->capaticty) {
    new_capacity = 4;
  }
  if(!vector_dbl_resize(v, new_capacity)) {
    return false;
  }

}

bool vector_dbl_push_back(vector_dbl *v, size_t index, double value) {

}
bool vector_dbl_shrink(vector_dbl *v);
