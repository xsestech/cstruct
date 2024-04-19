//
// Created by Alex on 19.04.2024.
//

#ifndef VECTOR_TREE_H
#define VECTOR_TREE_H

#include "dynamic/vector.h"

typedef struct tree_node_t tree_node_t;
typedef tree_node_t* tree_t;

/**
 * Initializes empty tree
 * @return Empty tree
 */
tree_t tree_init();
void tree_destroy(tree_t tree);
bool tree_add(tree_t tree, double value, char* path);
bool tree_delete(tree_t tree, char* path);
bool tree_is_empty(tree_t);



#endif //VECTOR_TREE_H
