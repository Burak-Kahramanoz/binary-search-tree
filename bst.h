#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition of the Binary Search Tree (BST) Node structure.
 */
typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} BST;

/* --- Function Prototypes --- */

/**
 * Allocates memory for a new node and initializes it with data.
 * @param data The integer value to store in the node.
 * @return Pointer to the newly created node.
 */
BST *new_node(int data);

/**
 * Inserts a new value into the BST maintaining the sorted property.
 * @param root The root of the tree.
 * @param data The value to be inserted.
 * @return The (possibly new) root of the tree.
 */
BST *insert(BST *root, int data);

/**
 * Deletes a node with value x from the tree.
 * Handles cases for leaf nodes, nodes with one child, and nodes with two children.
 * @param root The root of the tree.
 * @param x The value to be deleted.
 * @return The root of the updated tree.
 */
BST *delete_node(BST *root, int x);

/**
 * Searches for a specific value in the tree.
 * @param root The root of the tree.
 * @param x The value to search for.
 * @return Pointer to the node if found, otherwise NULL.
 */
BST *searchTree(BST *root, int x);

// --- Traversal Functions ---
void preorder(BST *root);  // Root -> Left -> Right
void inorder(BST *root);   // Left -> Root -> Right (Sorted output)
void postorder(BST *root); // Left -> Right -> Root

// --- Utility Functions ---
int size(BST *root);     // Returns total number of nodes
int height(BST *root);   // Returns the height (max depth) of the tree
int minValue(BST *root); // Returns the minimum value in the tree
int maxValue(BST *root); // Returns the maximum value in the tree

#endif