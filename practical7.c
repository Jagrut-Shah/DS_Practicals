/**
 * Practical 7: Singly Linked List - Deletion Operations
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Function prototypes */
Node* create_node(int value);
int get_node_count(const Node *head);
void append_node(Node **head_ref, int value);
int delete_from_head(Node **head_ref, int *removed_val);
int delete_from_tail(Node **head_ref, int *removed_val);
int delete_from_position(Node **head_ref, int position, int *removed_val);
void display_list(const Node *head);
void cleanup_list(Node **head_ref);

/**
 * Creates and allocates memory for a single node
 */
Node* create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("[Fatal] Memory allocation failure.\n");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

/**
 * Counts total nodes currently present in the list
 */
int get_node_count(const Node *head) {
    int total = 0;
    const Node *curr = head;
    while (curr != NULL) {
        total++;
        curr = curr->next;
    }
    return total;
}

/**
 * Appends a node to the end of the list for building/testing
 */
void append_node(Node **head_ref, int value) {
    Node *new_node = create_node(value);
    if (new_node == NULL) return;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node *curr = *head_ref;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
}

/**
 * Removes the first node from the list
 */
int delete_from_head(Node **head_ref, int *removed_val) {
    if (*head_ref == NULL) {
        printf("[Underflow] List is empty! Nothing to delete.\n");
        return 0;
    }
    Node *temp = *head_ref;
    *removed_val = temp->data;
    *head_ref = (*head_ref)->next;
    free(temp);
    return 1;
}

/**
 * Removes the final node from the list
 */
int delete_from_tail(Node **head_ref, int *removed_val) {
    if (*head_ref == NULL) {
        printf("[Underflow] List is empty! Nothing to delete.\n");
        return 0;
    }

    /* Single node scenario */
    if ((*head_ref)->next == NULL) {
        *removed_val = (*head_ref)->data;
        free(*head_ref);
        *head_ref = NULL;
        return 1;
    }

    Node *curr = *head_ref;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    Node *tail_node = curr->next;
    *removed_val = tail_node->data;
    curr->next = NULL;
    free(tail_node);
    return 1;
}

/**
 * Removes a node from a specified 1-based position
 */
int delete_from_position(Node **head_ref, int position, int *removed_val) {
    int total = get_node_count(*head_ref);

    if (*head_ref == NULL) {
        printf("[Underflow] List is empty! Nothing to delete.\n");
        return 0;
    }

    if (position < 1 || position > total) {
        printf("[Error] Invalid position. Valid range is 1 to %d.\n", total);
        return 0;
    }

    if (position == 1) {
        return delete_from_head(head_ref, removed_val);
    }

    Node *prev = *head_ref;
    for (int i = 1; i < position - 1; i++) {
        prev = prev->next;
    }

    Node *target = prev->next;
    *removed_val = target->data;
    prev->next = target->next;
    free(target);
    return 1;
}

/**
 * Prints all elements in the linked list
 */
void display_list(const Node *head) {
    if (head == NULL) {
        printf("[List] List is currently empty.\n");
        return;
    }
    printf("[Linked List]: ");
    const Node *curr = head;
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/**
 * Clears all nodes to prevent memory leaks
 */
void cleanup_list(Node **head_ref) {
    Node *curr = *head_ref;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head_ref = NULL;
}

int main(void) {
    Node *list_head = NULL;
    int choice, val, pos, deleted;

    while (1) {
        printf("\n============================================\n");
        printf("   PRACTICAL 7: SINGLY LINKED LIST DELETION  \n");
        printf("============================================\n");
        printf("1. Insert Element (Append at End)\n");
        printf("2. Delete from Beginning (Head)\n");
        printf("3. Delete from End (Tail)\n");
        printf("4. Delete from Specified Position\n");
        printf("5. Display List\n");
        printf("6. Exit Program\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                append_node(&list_head, val);
                display_list(list_head);
                break;

            case 2:
                if (delete_from_head(&list_head, &deleted)) {
                    printf("[Success] Deleted head node with value: %d\n", deleted);
                    display_list(list_head);
                }
                break;

            case 3:
                if (delete_from_tail(&list_head, &deleted)) {
                    printf("[Success] Deleted tail node with value: %d\n", deleted);
                    display_list(list_head);
                }
                break;

            case 4:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &pos);
                if (delete_from_position(&list_head, pos, &deleted)) {
                    printf("[Success] Deleted node at position %d with value: %d\n", pos, deleted);
                    display_list(list_head);
                }
                break;

            case 5:
                display_list(list_head);
                break;

            case 6:
                cleanup_list(&list_head);
                printf("Exiting Practical 7. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice from 1 to 6.\n");
        }
    }

    cleanup_list(&list_head);
    return 0;
}
