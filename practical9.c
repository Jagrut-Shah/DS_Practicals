/**
 * Practical 9: Binary Search Tree (BST) - Insertion, Search, and Inorder Traversal
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

/* Function prototypes */
BSTNode* bst_create_node(int key);
BSTNode* bst_insert(BSTNode *root, int key);
BSTNode* bst_search(const BSTNode *root, int target);
void bst_inorder(const BSTNode *root);
void bst_preorder(const BSTNode *root);
void bst_postorder(const BSTNode *root);
void bst_free(BSTNode *root);

/**
 * Allocates and initializes a new binary search tree node
 */
BSTNode* bst_create_node(int key) {
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
    if (node == NULL) {
        printf("[Fatal] Memory allocation failed!\n");
        return NULL;
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Inserts a key into the BST following search tree property:
 * Left subtree < Root < Right subtree
 */
BSTNode* bst_insert(BSTNode *root, int key) {
    if (root == NULL) {
        printf("[Success] Inserted key %d into BST.\n", key);
        return bst_create_node(key);
    }

    if (key < root->key) {
        root->left = bst_insert(root->left, key);
    } else if (key > root->key) {
        root->right = bst_insert(root->right, key);
    } else {
        printf("[Warning] Duplicate key %d rejected (keys in BST must be unique).\n", key);
    }

    return root;
}

/**
 * Recursively searches for a target key in the BST
 * Returns pointer to node if found, otherwise NULL
 */
BSTNode* bst_search(const BSTNode *root, int target) {
    if (root == NULL || root->key == target) {
        return (BSTNode *)root;
    }
    if (target < root->key) {
        return bst_search(root->left, target);
    }
    return bst_search(root->right, target);
}

/**
 * Inorder Traversal (Left -> Root -> Right):
 * Produces elements in non-decreasing sorted order
 */
void bst_inorder(const BSTNode *root) {
    if (root != NULL) {
        bst_inorder(root->left);
        printf("%d ", root->key);
        bst_inorder(root->right);
    }
}

/**
 * Preorder Traversal (Root -> Left -> Right)
 */
void bst_preorder(const BSTNode *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        bst_preorder(root->left);
        bst_preorder(root->right);
    }
}

/**
 * Postorder Traversal (Left -> Right -> Root)
 */
void bst_postorder(const BSTNode *root) {
    if (root != NULL) {
        bst_postorder(root->left);
        bst_postorder(root->right);
        printf("%d ", root->key);
    }
}

/**
 * Recursively releases all memory associated with BST
 */
void bst_free(BSTNode *root) {
    if (root != NULL) {
        bst_free(root->left);
        bst_free(root->right);
        free(root);
    }
}

int main(void) {
    BSTNode *root = NULL;
    int choice, value;
    BSTNode *search_res;

    while (1) {
        printf("\n============================================\n");
        printf("    PRACTICAL 9: BINARY SEARCH TREE (BST)   \n");
        printf("============================================\n");
        printf("1. Insert Key\n");
        printf("2. Search Key\n");
        printf("3. Inorder Traversal (Sorted Output)\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit Program\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter integer key to insert: ");
                scanf("%d", &value);
                root = bst_insert(root, value);
                break;

            case 2:
                if (root == NULL) {
                    printf("[Notice] BST is empty.\n");
                    break;
                }
                printf("Enter key to search: ");
                scanf("%d", &value);
                search_res = bst_search(root, value);
                if (search_res != NULL) {
                    printf("[Found] Key %d is present in the BST.\n", value);
                } else {
                    printf("[Not Found] Key %d does not exist in the BST.\n", value);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("[Display] BST is empty.\n");
                } else {
                    printf("Inorder Traversal: [ ");
                    bst_inorder(root);
                    printf("]\n");
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("[Display] BST is empty.\n");
                } else {
                    printf("Preorder Traversal: [ ");
                    bst_preorder(root);
                    printf("]\n");
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("[Display] BST is empty.\n");
                } else {
                    printf("Postorder Traversal: [ ");
                    bst_postorder(root);
                    printf("]\n");
                }
                break;

            case 6:
                bst_free(root);
                root = NULL;
                printf("Exiting Practical 9. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice between 1 and 6.\n");
        }
    }

    bst_free(root);
    return 0;
}
