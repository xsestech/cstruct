#include "static/queue.h"

void queue_dbl_init(queue_dbl *q) {
  q->size = 0;
  q->front = 0;
}

bool queue_dbl_push(queue_dbl *q, const double element) {
  if (q->size == QUEUE_MAX_CAPACITY) {
    return false;
  }
  q->buff[(q->front + q->size++) % QUEUE_MAX_CAPACITY] = element;
  return true;
}

double queue_dbl_pop(queue_dbl *q) {
  if (q->size == 0) {
    return NAN;
  }
  double value = q->buff[q->front];
  --q->size;
  q->front = (q->front + 1) % QUEUE_MAX_CAPACITY;
  return value;
}

bool queue_dbl_is_empty(queue_dbl *q) {
  return q->size == 0;
}
void queue_dbl_destroy(queue_dbl *q) {
  q->size = 0;
  q->front = 0;
}
