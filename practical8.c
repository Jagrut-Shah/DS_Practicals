/**
 * Practical 8: Doubly Linked List Operations (Insert, Delete, Forward & Backward Traversal)
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

/* Function prototypes */
DNode* create_dnode(int value);
int get_dll_length(const DNode *head);
void insert_front(DNode **head_ref, int value);
void insert_rear(DNode **head_ref, int value);
int insert_at_pos(DNode **head_ref, int value, int position);
int delete_front(DNode **head_ref, int *removed_val);
int delete_rear(DNode **head_ref, int *removed_val);
int delete_at_pos(DNode **head_ref, int position, int *removed_val);
void display_forward(const DNode *head);
void display_backward(const DNode *head);
void free_dll(DNode **head_ref);

/**
 * Creates and initializes a new doubly linked list node
 */
DNode* create_dnode(int value) {
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    if (new_node == NULL) {
        printf("[Fatal] Memory allocation failure!\n");
        return NULL;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

/**
 * Counts total number of nodes in the doubly linked list
 */
int get_dll_length(const DNode *head) {
    int count = 0;
    const DNode *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

/**
 * Inserts a new node at the front (head) of the doubly linked list
 */
void insert_front(DNode **head_ref, int value) {
    DNode *new_node = create_dnode(value);
    if (new_node == NULL) return;

    if (*head_ref != NULL) {
        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
    printf("[Success] Inserted %d at the front.\n", value);
}

/**
 * Inserts a new node at the end (tail) of the doubly linked list
 */
void insert_rear(DNode **head_ref, int value) {
    DNode *new_node = create_dnode(value);
    if (new_node == NULL) return;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("[Success] Inserted %d at the rear.\n", value);
        return;
    }

    DNode *curr = *head_ref;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
    new_node->prev = curr;
    printf("[Success] Inserted %d at the rear.\n", value);
}

/**
 * Inserts a node at a 1-based index position
 */
int insert_at_pos(DNode **head_ref, int value, int position) {
    int total = get_dll_length(*head_ref);

    if (position < 1 || position > total + 1) {
        printf("[Error] Position out of bounds! Valid range: 1 to %d.\n", total + 1);
        return 0;
    }

    if (position == 1) {
        insert_front(head_ref, value);
        return 1;
    }
    if (position == total + 1) {
        insert_rear(head_ref, value);
        return 1;
    }

    DNode *new_node = create_dnode(value);
    if (new_node == NULL) return 0;

    DNode *curr = *head_ref;
    for (int i = 1; i < position - 1; i++) {
        curr = curr->next;
    }

    new_node->next = curr->next;
    new_node->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = new_node;
    }
    curr->next = new_node;

    printf("[Success] Inserted %d at position %d.\n", value, position);
    return 1;
}

/**
 * Removes the front node from the doubly linked list
 */
int delete_front(DNode **head_ref, int *removed_val) {
    if (*head_ref == NULL) {
        printf("[Underflow] List is empty! Nothing to delete.\n");
        return 0;
    }

    DNode *temp = *head_ref;
    *removed_val = temp->data;

    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL) {
        (*head_ref)->prev = NULL;
    }

    free(temp);
    return 1;
}

/**
 * Removes the rear node from the doubly linked list
 */
int delete_rear(DNode **head_ref, int *removed_val) {
    if (*head_ref == NULL) {
        printf("[Underflow] List is empty! Nothing to delete.\n");
        return 0;
    }

    /* Single element */
    if ((*head_ref)->next == NULL) {
        *removed_val = (*head_ref)->data;
        free(*head_ref);
        *head_ref = NULL;
        return 1;
    }

    DNode *curr = *head_ref;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    *removed_val = curr->data;
    curr->prev->next = NULL;
    free(curr);
    return 1;
}

/**
 * Removes node from a specified 1-based position
 */
int delete_at_pos(DNode **head_ref, int position, int *removed_val) {
    int total = get_dll_length(*head_ref);

    if (*head_ref == NULL) {
        printf("[Underflow] List is empty! Nothing to delete.\n");
        return 0;
    }

    if (position < 1 || position > total) {
        printf("[Error] Invalid position. Allowed range: 1 to %d.\n", total);
        return 0;
    }

    if (position == 1) {
        return delete_front(head_ref, removed_val);
    }
    if (position == total) {
        return delete_rear(head_ref, removed_val);
    }

    DNode *curr = *head_ref;
    for (int i = 1; i < position; i++) {
        curr = curr->next;
    }

    *removed_val = curr->data;
    curr->prev->next = curr->next;
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }

    free(curr);
    return 1;
}

/**
 * Traverses forward from head to tail
 */
void display_forward(const DNode *head) {
    if (head == NULL) {
        printf("[Display] Doubly linked list is empty.\n");
        return;
    }
    printf("[Forward Traversal]: NULL <--> ");
    const DNode *curr = head;
    while (curr != NULL) {
        printf("[%d] <--> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/**
 * Traverses backward from tail to head
 */
void display_backward(const DNode *head) {
    if (head == NULL) {
        printf("[Display] Doubly linked list is empty.\n");
        return;
    }
    const DNode *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    printf("[Backward Traversal]: NULL <--> ");
    while (curr != NULL) {
        printf("[%d] <--> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

/**
 * Deallocates entire doubly linked list
 */
void free_dll(DNode **head_ref) {
    DNode *curr = *head_ref;
    while (curr != NULL) {
        DNode *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head_ref = NULL;
}

int main(void) {
    DNode *head = NULL;
    int choice, val, pos, removed;

    while (1) {
        printf("\n============================================\n");
        printf("    PRACTICAL 8: DOUBLY LINKED LIST (DLL)   \n");
        printf("============================================\n");
        printf("1. Insert at Beginning (Front)\n");
        printf("2. Insert at End (Rear)\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Delete from Beginning (Front)\n");
        printf("5. Delete from End (Rear)\n");
        printf("6. Delete from Specified Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit Program\n");
        printf("Enter choice (1-9): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_front(&head, val);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_rear(&head, val);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                insert_at_pos(&head, val, pos);
                break;

            case 4:
                if (delete_front(&head, &removed)) {
                    printf("[Success] Deleted front node with value: %d\n", removed);
                }
                break;

            case 5:
                if (delete_rear(&head, &removed)) {
                    printf("[Success] Deleted rear node with value: %d\n", removed);
                }
                break;

            case 6:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &pos);
                if (delete_at_pos(&head, pos, &removed)) {
                    printf("[Success] Deleted node at position %d with value: %d\n", pos, removed);
                }
                break;

            case 7:
                display_forward(head);
                break;

            case 8:
                display_backward(head);
                break;

            case 9:
                free_dll(&head);
                printf("Exiting Practical 8. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter an integer from 1 to 9.\n");
        }
    }

    free_dll(&head);
    return 0;
}
