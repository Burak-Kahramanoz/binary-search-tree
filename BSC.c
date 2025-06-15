#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Binary Search Tree Node
struct BSC {
    int data;
    struct BSC *left;
    struct BSC *right;
};

typedef struct BSC BSC;

// Function prototypes
BSC *createNode(int data);
BSC *add(BSC *root, int data);
void inorder(BSC *root);

int main() {
    int x, i;
    BSC *root = NULL;

    // Take 10 integers from user and add them to the BST
    for (i = 0; i < 10; i++) {
        printf("Enter a number: ");
        scanf("%d", &x);
        root = add(root, x);
    }

    // Print the BST in in-order traversal (ascending order)
    printf("In-order: ");
    inorder(root);
    printf("\n");

    return 0;
}

// Create a new node with given data
BSC *createNode(int data) {
    BSC *node = (BSC *)malloc(sizeof(BSC));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Add a new node to the BST
BSC *add(BSC *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data == root->data) {
        // Duplicate value; do not insert
        return root;
    } else if (data < root->data) {
        root->left = add(root->left, data);
    } else {
        root->right = add(root->right, data);
    }

    return root;
}

// Perform in-order traversal of the BST
void inorder(BSC *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
