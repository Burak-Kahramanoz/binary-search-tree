#include <stdio.h>
#include "bst.h" // Include our custom BST library

int main()
{
    BST *root = NULL;

    // 1. Insertion Test
    printf("--- Inserting Data into Tree ---\n");
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // Tree Structure:
    //        50
    //      /    \
    //     30     70
    //    /  \   /  \
    //   20  40 60  80

    // 2. Traversal Test
    printf("Inorder Traversal (Sorted): ");
    inorder(root); // Expected Output: 20 30 40 50 60 70 80
    printf("\n");

    // 3. Utility Function Tests
    printf("Minimum Value: %d\n", minValue(root));
    printf("Maximum Value: %d\n", maxValue(root));
    printf("Tree Size (Node Count): %d\n", size(root));
    printf("Tree Height: %d\n", height(root));

    // 4. Search Test
    int searchVal = 60;
    BST *found = searchTree(root, searchVal);
    if (found != NULL)
        printf("Value %d found in the tree.\n", searchVal);
    else
        printf("Value %d not found.\n", searchVal);

    // 5. Deletion Test
    printf("--- Deleting Node 20 (Leaf Node) ---\n");
    root = delete_node(root, 20);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}