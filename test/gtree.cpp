//
// Created by Alex on 20.04.2024.
//

#include "gtest/gtest.h"
extern "C" {
#include "tree/gtree.h"
}

TEST(tree, testTree) {
  tree_t tree = tree_init();
  tree_add(&tree, 5, "\0");
  tree_add(&tree, 6, "c");
  tree_add(&tree, 7, "cb");
  tree_add(&tree, 8, "cc");
  tree_add(&tree, 8, "ccc");
  tree_print(tree, 0);
  tree_delete(&tree, NULL, "cc");
  tree_print(tree, 0);
  ASSERT_EQ(tree_get_value(tree), 5);
  tree_destroy(&tree);
}