/**
 * Practical 10: Binary Tree Construction and Traversals (Inorder, Preorder, Postorder)
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* Function prototypes */
TreeNode* create_tree_node(int value);
TreeNode* construct_binary_tree(void);
void traversal_inorder(const TreeNode *root);
void traversal_preorder(const TreeNode *root);
void traversal_postorder(const TreeNode *root);
int compute_tree_height(const TreeNode *root);
int count_tree_nodes(const TreeNode *root);
void destroy_binary_tree(TreeNode *root);

/**
 * Creates and initializes a binary tree node
 */
TreeNode* create_tree_node(int value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("[Fatal] Memory allocation failure!\n");
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Recursively constructs a binary tree from user input.
 * Enter -1 to designate an empty branch (NULL leaf).
 */
TreeNode* construct_binary_tree(void) {
    int value;
    printf("Enter node value (-1 for no node): ");
    if (scanf("%d", &value) != 1 || value == -1) {
        return NULL;
    }

    TreeNode *root = create_tree_node(value);
    if (root == NULL) {
        return NULL;
    }

    printf("--> Enter left child of [%d]:\n", value);
    root->left = construct_binary_tree();

    printf("--> Enter right child of [%d]:\n", value);
    root->right = construct_binary_tree();

    return root;
}

/**
 * Inorder Traversal: Left Subtree -> Root -> Right Subtree
 */
void traversal_inorder(const TreeNode *root) {
    if (root != NULL) {
        traversal_inorder(root->left);
        printf("%d ", root->data);
        traversal_inorder(root->right);
    }
}

/**
 * Preorder Traversal: Root -> Left Subtree -> Right Subtree
 */
void traversal_preorder(const TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        traversal_preorder(root->left);
        traversal_preorder(root->right);
    }
}

/**
 * Postorder Traversal: Left Subtree -> Right Subtree -> Root
 */
void traversal_postorder(const TreeNode *root) {
    if (root != NULL) {
        traversal_postorder(root->left);
        traversal_postorder(root->right);
        printf("%d ", root->data);
    }
}

/**
 * Computes maximum depth/height of the binary tree
 */
int compute_tree_height(const TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left_h = compute_tree_height(root->left);
    int right_h = compute_tree_height(root->right);
    return 1 + ((left_h > right_h) ? left_h : right_h);
}

/**
 * Counts total number of nodes in binary tree
 */
int count_tree_nodes(const TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count_tree_nodes(root->left) + count_tree_nodes(root->right);
}

/**
 * Deallocates all nodes in the binary tree
 */
void destroy_binary_tree(TreeNode *root) {
    if (root != NULL) {
        destroy_binary_tree(root->left);
        destroy_binary_tree(root->right);
        free(root);
    }
}

int main(void) {
    TreeNode *tree_root = NULL;
    int choice;

    while (1) {
        printf("\n============================================\n");
        printf("  PRACTICAL 10: BINARY TREE & TRAVERSALS    \n");
        printf("============================================\n");
        printf("1. Construct Binary Tree (Interactive Input)\n");
        printf("2. Inorder Traversal (L - Root - R)\n");
        printf("3. Preorder Traversal (Root - L - R)\n");
        printf("4. Postorder Traversal (L - R - Root)\n");
        printf("5. Display Tree Statistics (Height & Node Count)\n");
        printf("6. Exit Program\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                if (tree_root != NULL) {
                    destroy_binary_tree(tree_root);
                    tree_root = NULL;
                }
                printf("\n--- Constructing Tree (-1 indicates NULL leaf) ---\n");
                tree_root = construct_binary_tree();
                printf("[Success] Binary tree constructed.\n");
                break;

            case 2:
                if (tree_root == NULL) {
                    printf("[Display] Tree is empty. Build tree first.\n");
                } else {
                    printf("Inorder Traversal: [ ");
                    traversal_inorder(tree_root);
                    printf("]\n");
                }
                break;

            case 3:
                if (tree_root == NULL) {
                    printf("[Display] Tree is empty. Build tree first.\n");
                } else {
                    printf("Preorder Traversal: [ ");
                    traversal_preorder(tree_root);
                    printf("]\n");
                }
                break;

            case 4:
                if (tree_root == NULL) {
                    printf("[Display] Tree is empty. Build tree first.\n");
                } else {
                    printf("Postorder Traversal: [ ");
                    traversal_postorder(tree_root);
                    printf("]\n");
                }
                break;

            case 5:
                if (tree_root == NULL) {
                    printf("[Display] Tree is empty. Build tree first.\n");
                } else {
                    printf("Total Nodes: %d\n", count_tree_nodes(tree_root));
                    printf("Tree Height: %d\n", compute_tree_height(tree_root));
                }
                break;

            case 6:
                destroy_binary_tree(tree_root);
                tree_root = NULL;
                printf("Exiting Practical 10. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice between 1 and 6.\n");
        }
    }

    destroy_binary_tree(tree_root);
    return 0;
}
