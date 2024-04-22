//
// Created by Alex on 20.04.2024.
//
#include "tree/gtree.h"

#define tree_ptr_get_attr_ptr(t, attr) \
  &((*t)->attr)
#define tree_ptr_get_attr(t, attr) \
((*t)->attr)

struct tree_node_t {
  double value;
  tree_node_t *child;
  tree_node_t *brother;
};

tree_t tree_init() {
  return NULL;
}
bool tree_add(tree_t *tree, double value, char *path) {
  if (*path != '\0' && *tree == NULL) {
    return false;
  }
  if (*path == '\0') {
    tree_node_t *temp = malloc(sizeof(tree_node_t));
    temp->child = NULL;
    temp->value = value;
    temp->brother = *tree;
    *tree = temp;
    return true;
  }
  if (*path == 'c') {
    return tree_add(tree_ptr_get_attr_ptr(tree, child), value, path + 1);
  }
  if (*path == 'b') {
    return tree_add(tree_ptr_get_attr_ptr(tree, brother), value, path + 1);
  }

  return false;
}
bool tree_delete(tree_t *tree, tree_t* last_node, char *path) {
  if (*path != '\0' && *tree == NULL) {
    return false;
  }
  if (*path == '\0') {
    tree_t tmp = *tree;
    if(last_node != NULL) {
      tree_ptr_get_attr(last_node, child) = tree_ptr_get_attr(tree, brother);
    }
    tree_destroy(&tmp->child);
    free(tmp);
    tmp = NULL;
    return true;
  }
  if (*path == 'c') {
    return tree_delete(tree_ptr_get_attr_ptr(tree, child), tree, path + 1);
  }
  if (*path == 'b') {
    return tree_delete(tree_ptr_get_attr_ptr(tree, brother),tree, path + 1);
  }

  return false;
}

void tree_print(tree_t tree, int h) {
  if (tree == NULL) {
    return;
  }
  for (int i = 0;i < h; i++) {
    printf("\t");
  }
  printf("%.2f", tree->value);
  if (tree->child != NULL) {
    printf(":");
  }
  printf("\n");
  tree_print(tree->child, h + 1);
  tree_print(tree->brother, h);
}

void tree_destroy(tree_t* tree){
  if(tree == NULL) return;
  if(*tree == NULL) return;
  tree_destroy(tree_ptr_get_attr_ptr(tree, child));
  tree_destroy(tree_ptr_get_attr_ptr(tree, brother));
  free(*tree);
}

bool tree_is_empty(tree_t tree) {
  return tree->value != tree->value;
}
double tree_get_value(tree_t tree) {
  return tree->value;
}
