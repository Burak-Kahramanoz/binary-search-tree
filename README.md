# Binary Search Tree (BST) in C

A robust and modular implementation of the **Binary Search Tree** data structure using the C programming language. This project demonstrates key concepts such as dynamic memory allocation, pointer manipulation, recursion, and modular file structure.

## 🚀 Features

This library supports the following operations:

* **Insertion**: Recursively adds new nodes while maintaining BST properties.
* **Deletion**: Handles three cases (Leaf node, One child, Two children).
* **Search**: Efficiently finds values in the tree.
* **Traversals**:
    * Inorder (Left -> Root -> Right)
    * Preorder (Root -> Left -> Right)
    * Postorder (Left -> Right -> Root)
* **Utilities**:
    * Calculate **Height** (Max depth)
    * Calculate **Size** (Total number of nodes)
    * Find **Minimum** and **Maximum** values

## 📂 Project Structure

The project is designed with a modular approach:

* `bst.h`: **Header File** - Contains the struct definition and function prototypes (API).
* `bst.c`: **Source File** - Contains the logic and implementation of the functions.
* `main.c`: **Driver Code** - A test suite to demonstrate the functionality of the library.

## 🛠️ Compilation & Usage

To compile and run this project, you need a C compiler (like GCC).

### 1. Compile the code
Since the project is split into multiple files, you need to compile `main.c` and `bst.c` together. Open your terminal in the project directory and run:

```bash
gcc main.c bst.c -o bst_program
