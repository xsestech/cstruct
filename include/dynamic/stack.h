//
// Created by Alex on 16.03.2024.
//

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct {
  int front;
  int size;
  int capacity;
  double *buff;
} stack_dbl;

void stack_dbl_create(stack_dbl *s);
void stack_dbl_destroy(stack_dbl *s);
void stack_dbl_push(stack_dbl *s, double value);
void stack_dbl_pop(stack_dbl *s);
void stack_dbl_is_empty(stack_dbl *s);


#endif //STACK_H
