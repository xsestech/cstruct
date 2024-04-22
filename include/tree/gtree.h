//
// Created by Alex on 19.04.2024.
//

#ifndef VECTOR_TREE_H
#define VECTOR_TREE_H

#include <cstruct/vector.h>
#include "stdio.h"

typedef struct tree_node_t tree_node_t;
typedef tree_node_t* tree_t;

/**
 * Initializes empty tree
 * @return Empty tree
 */
tree_t tree_init();
/**
 * Destroys all tree nodes
 * @param tree pointer to tree to destroy
 */
void tree_destroy(tree_t* tree);
bool tree_add(tree_t* tree, double value, char* path);
bool tree_delete(tree_t *tree, tree_t* last_node, char *path);
void tree_print(tree_t tree, int h);
bool tree_is_empty(tree_t);
double tree_get_value(tree_t tree);



#endif //VECTOR_TREE_H
