//
// Created by Alex on 16.03.2024.
//

#include "dynamic/stack.h"

void stack_dbl_create(stack_dbl *s) {
  s->size = 0;
  s->buff = 0;
}
void stack_dbl_destroy(stack_dbl *s);
void stack_dbl_push(stack_dbl *s, double value);
void stack_dbl_pop(stack_dbl *s);
void stack_dbl_is_empty(stack_dbl *s);