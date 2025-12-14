#include "bst.h"

// Helper function to create a new node
BST *new_node(int data)
{
    BST *node = (BST *)malloc(sizeof(BST));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to insert a key into BST
BST *insert(BST *root, int data)
{
    // If the tree is empty or we reached a leaf, create a new node
    if (root != NULL)
    {
        // If data is smaller, go to the left subtree
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        // If data is larger or equal, go to the right subtree
        else
            root->right = insert(root->right, data);
    }
    else
    {
        // Base case: Found the correct position
        root = new_node(data);
    }
    return root;
}

// Function to delete a node and rearrange the tree
BST *delete_node(BST *root, int x)
{
    // Base case: Tree is empty
    if (root == NULL)
        return NULL;

    // Search for the node to be deleted
    if (root->data == x)
    {
        BST *temp;

        // Case 1: Node has no children (Leaf node)
        if (root->left == root->right)
        {
            free(root);
            return NULL;
        }
        // Case 2: Node has only right child
        else if (root->left == NULL && root->right != NULL)
        {
            temp = root;
            root = root->right; // Replace with right child
            free(temp);
            return root;
        }
        // Case 2: Node has only left child
        else if (root->left != NULL && root->right == NULL)
        {
            temp = root;
            root = root->left; // Replace with left child
            free(temp);
            return root;
        }
        // Case 3: Node has two children
        else
        {
            // Strategy: Replace node with the minimum value from the right subtree
            // (Inorder Successor) and then delete that successor node.

            // However, your specific implementation uses a slightly different logic:
            // It moves the right child up and attaches the old left subtree
            // to the leftmost part of the new right subtree.

            temp = root;
            BST *temp2;

            root = root->right; // Move right child up
            temp2 = root;

            // Find the leftmost node of the right subtree
            while (temp2->left != NULL)
            {
                temp2 = temp2->left;
            }

            // Attach the original left subtree here
            temp2->left = temp->left;

            free(temp); // Free the original node
            return root;
        }
    }
    // If x is greater than root's data, recurse right
    else if (x > root->data)
    {
        root->right = delete_node(root->right, x);
    }
    // If x is smaller than root's data, recurse left
    else
        root->left = delete_node(root->left, x);

    return root;
}

BST *searchTree(BST *root, int x)
{
    // Base case: Root is null or key is present at root
    if (root == NULL || root->data == x)
        return root;

    // Key is smaller than root's key
    if (x < root->data)
        return searchTree(root->left, x);

    // Key is larger than root's key
    else
        return searchTree(root->right, x);
}

// --- Traversals ---

void preorder(BST *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BST *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

void postorder(BST *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

// --- Utilities ---

int size(BST *root)
{
    if (root == NULL)
        return 0;
    return size(root->left) + 1 + size(root->right);
}

int height(BST *root)
{
    if (root == NULL)
        return -1; // Height of empty tree is -1
    else
    {
        int leftH = height(root->left);
        int rightH = height(root->right);

        // Return the larger height + 1
        if (leftH > rightH)
            return leftH + 1;
        else
            return rightH + 1;
    }
}

int minValue(BST *root)
{
    if (root == NULL)
        return 0;

    // Go to the leftmost node
    while (root->left != NULL)
        root = root->left;
    return (root->data);
}

int maxValue(BST *root)
{
    if (root == NULL)
        return 0;

    // Go to the rightmost node
    while (root->right != NULL)
        root = root->right;
    return (root->data);
}