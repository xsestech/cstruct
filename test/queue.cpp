//
// Created by Alex on 16.03.2024.
//

#include "gtest/gtest.h"
extern "C" {
#include "static/queue.h"
}

TEST(queue, testQueuePush) {
  queue_dbl q;
  queue_dbl_init(&q);
  (&q)->size = 0;
  queue_dbl_push(&q, 1);
  double x = queue_dbl_pop(&q);
  ASSERT_EQ(x, 1);
}

TEST(queue, testQueuePop) {
  queue_dbl q;
  queue_dbl_init(&q);
  for (int i = 0; i < QUEUE_MAX_CAPACITY; i++) {
	queue_dbl_push(&q, i);
  }
  ASSERT_EQ(q.size, QUEUE_MAX_CAPACITY);
  for (int i = 0; i < QUEUE_MAX_CAPACITY; i++) {
    double x = queue_dbl_pop(&q);
	ASSERT_EQ(x, i);
  }

}

TEST(queueone, testQueueOverload) {
  queue_dbl q;
  queue_dbl_init(&q);
  bool res = true;
  for (int i = 0; i < 1000000; i++) {
    res = queue_dbl_push(&q, i);
  }
  double x = queue_dbl_pop(&q);
  ASSERT_EQ(res, false);
  ASSERT_EQ(x, 0);
}
