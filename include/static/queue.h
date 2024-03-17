#ifndef QUEUE_LIBRARY_H
#define QUEUE_LIBRARY_H

#include <stdbool.h>
#include <sys/_types/_size_t.h>
#include <math.h>

#define QUEUE_MAX_CAPACITY 10

typedef struct {
  int front;
  size_t size;
  double buff[QUEUE_MAX_CAPACITY];
} queue_dbl;

void queue_dbl_init(queue_dbl *q);
bool queue_dbl_push(queue_dbl *q, double element);
double queue_dbl_pop(queue_dbl * q);
bool queue_dbl_is_empty(queue_dbl *q);
void queue_dbl_destroy(queue_dbl *q);


#endif //QUEUE_LIBRARY_H
