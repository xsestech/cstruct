//
// Created by Alex on 30.03.2024.
//
#define NO_STRICT
#include "gtest/gtest.h"
#define CVECTOR_LOGARITHMIC_GROWTH
extern "C" {
#include "dynamic/vector.h"
}
extern "C" {
#include "dynamic/adapter/vector_adapter.h"
}

static void free_string(void *ptr) {
    if (ptr) {
        free(*(char **)ptr);
    }
}

TEST(vector, testBack) {
  vector(int) v = nullptr;
  vector_int_push_back(&v, 0);
  vector_int_push_back(&v, 1);
  ASSERT_EQ(vector_size(v), 2);
  int *back = vector_back(v);
  ASSERT_TRUE(*back == 1);
  vector_int_push_back(&v, 2);
  back = vector_back(v);
  ASSERT_TRUE(*back == 2);
  vector_destroy(v);
}
TEST(vector, testFront) {
    vector(int) v = nullptr;
    vector_int_push_back(&v, 0);
    vector_int_push_back(&v, 1);

    ASSERT_TRUE(vector_size(v) == 2);

    int *front = vector_front(v);
    ASSERT_TRUE(*front == 0);

    vector_erase(v, 0);
    front = vector_front(v);
    ASSERT_TRUE(*front == 1);

    vector_destroy(v);
}

TEST(vector, testAt) {
    vector(int) v = nullptr;
    for (int i = 0; i < 5; i++) {
        vector_int_push_back(&v, i);
    }

    ASSERT_EQ(vector_size(v), 5);

    if (v) {
        int i = 0;
        for (; i < (int)vector_size(v); i++) {
            ASSERT_EQ(*vector_at(v, i), i);
        }
    }

    // test non-exists position
    int pos_non_exists = 999;
    ASSERT_EQ(vector_at(v, pos_non_exists), (void *)NULL);

    // remove last element
    vector_pop_back(v);
    ASSERT_EQ(vector_at(v, 4), (void *)NULL);

    vector_destroy(v);
}

TEST(vector, testEmpty) {
    vector_type_t(int) v = NULL;
    ASSERT_EQ(vector_capacity(v), 0);
    ASSERT_EQ(vector_size(v), 0);
    ASSERT_EQ(vector_begin(v), (void*)NULL);
    ASSERT_EQ(vector_end(v), (void*)NULL);
}

TEST(vector, testPushPop) {
    vector(int) v = NULL;

    // add some elements to the back
    vector_int_push_back(&v, 10);
    vector_int_push_back(&v, 20);
    vector_int_push_back(&v, 30);

    // and remove one too
    vector_pop_back(v);

    ASSERT_EQ(vector_capacity(v), 4);
    ASSERT_EQ(vector_size(v), 2);

    vector_destroy(v);
}

TEST(vector, testIndex) {
    vector(int) v = NULL;

    // add some elements to the back
    vector_int_push_back(&v, 10);
    vector_int_push_back(&v, 20);
    vector_int_push_back(&v, 30);

    // and remove one too
    vector_pop_back(v);

    ASSERT_EQ(vector_capacity(v), 4);
    ASSERT_EQ(vector_size(v), 2);

    /* iterator over the vector standard indexing too! */
    if (v) {
        size_t i;
        for (i = 0; i < vector_size(v); ++i) {
            switch (i) {
                case 0:
                    ASSERT_EQ(v[i], 10);
                    break;
                case 1:
                    ASSERT_EQ(v[i], 20);
                }
        }
    }

    vector_destroy(v);
}

TEST(vector, testInsertDelete) {
    vector(int) a = NULL;

    vector_int_push_back(&a, 5);
    vector_int_push_back(&a, 1);
    vector_int_push_back(&a, 4);
    vector_pop_back(a); // delete 4
    vector_int_push_back(&a, 5);
    vector_erase(a, 1); // delete 5
    vector_erase(a, 0);
    vector_int_insert(&a, 0, 1);

    ASSERT_EQ(vector_capacity(a), 4);
    ASSERT_EQ(vector_size(a), 2);

    vector_destroy(a);
}
TEST(vector, testReserve) {
    int i;
    vector(int) c = NULL;

    vector_int_reserve(&c, 100);
    ASSERT_EQ(vector_capacity(c), 100);
    ASSERT_EQ(vector_size(c), 0);

    vector_int_push_back(&c, 10);
    ASSERT_EQ(vector_capacity(c), 100);
    ASSERT_EQ(vector_size(c), 1);

    vector_int_reserve(&c, 10);
    ASSERT_EQ(vector_capacity(c), 100);

    for (i = 0; i < 100; ++i) {
        vector_int_push_back(&c, i);
    }

    ASSERT_EQ(vector_capacity(c), 200);
    vector_destroy(c);
}


TEST(vector, testFreeAll) {
    int i;
    vector(char *) v = NULL;
    vector_string_init(&v, 1, free_string);
    for (i = 0; i < 10; ++i) {
        char *p = (char*) malloc(6);
        strcpy(p, "hello");
        vector_string_push_back(&v, p);
    }

    ASSERT_EQ(vector_size(v), 10);
    ASSERT_GE(vector_capacity(v), 10);

    vector_destroy(v);
}

TEST(vector, testShrinkToFit) {
    vector(int) a = NULL;

    vector_int_push_back(&a, 1);
    vector_int_push_back(&a, 5);
    vector_int_push_back(&a, 4);

    vector_int_reserve(&a, 50);
    ASSERT_EQ(vector_capacity(a), (size_t)50);

    vector_int_shrint_to_fit(&a);
    ASSERT_EQ(vector_capacity(a), (size_t)3);

    vector_destroy(a);
}
