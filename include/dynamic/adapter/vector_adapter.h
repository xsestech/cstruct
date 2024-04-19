//
// Created by Alex on 19.04.2024.
//

#ifndef VECTOR_ADAPTER_H
#define VECTOR_ADAPTER_H
#include <stddef.h>

#include "dynamic/vector.h"

void vector_int_push_back(int** vec, int data);
void vector_int_insert(int** vec, size_t pos, int val);
void vector_string_init(char*** vec, size_t size, vector_elem_destructor_t elem_destructor);
void vector_string_push_back(char*** vec, char* data);
void vector_int_reserve(int** vec, size_t size);
void vector_int_shrint_to_fit(int** vec);

#endif //VECTOR_ADAPTER_H
