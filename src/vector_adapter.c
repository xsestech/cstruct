//
// Created by Alex on 19.04.2024.
//
#include "dynamic/adapter/vector_adapter.h"


void vector_int_push_back(int** vec, int data) {
  vector_push_back(*vec, data);
}
void vector_int_insert(int** vec, size_t pos, int val) {
  vector_insert(*vec, pos, val);
}
void vector_string_init(char*** vec, size_t size, vector_elem_destructor_t elem_destructor) {
  vector_init(*vec, size, elem_destructor);
}
void vector_string_push_back(char*** vec, char* data) {
  vector_push_back(*vec, data);
}
void vector_int_reserve(int** vec, size_t size) {
  vector_reserve(*vec, size);
}
void vector_int_shrint_to_fit(int** vec) {
  vector_shrink_to_fit(*vec);
}