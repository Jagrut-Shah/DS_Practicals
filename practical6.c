/**
 * Practical 6: Singly Linked List - Node Creation and Insertion Operations
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
Node* create_new_node(int value);
int get_list_length(const Node *head);
void insert_at_head(Node **head_ref, int value);
void insert_at_tail(Node **head_ref, int value);
int insert_at_position(Node **head_ref, int value, int position);
void print_linked_list(const Node *head);
void free_linked_list(Node **head_ref);

/**
 * Dynamically allocates and initializes a new linked list node
 */
Node* create_new_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("[Fatal] Memory allocation failed!\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

/**
 * Counts total number of nodes in the linked list
 */
int get_list_length(const Node *head) {
    int count = 0;
    const Node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

/**
 * Inserts a new element at the very front of the list
 */
void insert_at_head(Node **head_ref, int value) {
    Node *new_node = create_new_node(value);
    if (new_node == NULL) {
        return;
    }
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("[Success] Inserted %d at the beginning of the list.\n", value);
}

/**
 * Inserts a new element at the end of the list
 */
void insert_at_tail(Node **head_ref, int value) {
    Node *new_node = create_new_node(value);
    if (new_node == NULL) {
        return;
    }
    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("[Success] Inserted %d as head node.\n", value);
        return;
    }
    Node *curr = *head_ref;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    printf("[Success] Inserted %d at the end of the list.\n", value);
}

/**
 * Inserts a new element at an arbitrary 1-based position
 */
int insert_at_position(Node **head_ref, int value, int position) {
    int length = get_list_length(*head_ref);

    if (position < 1 || position > length + 1) {
        printf("[Error] Position out of bounds! Valid range: 1 to %d.\n", length + 1);
        return 0;
    }

    if (position == 1) {
        insert_at_head(head_ref, value);
        return 1;
    }

    Node *new_node = create_new_node(value);
    if (new_node == NULL) {
        return 0;
    }

    Node *curr = *head_ref;
    for (int i = 1; i < position - 1; i++) {
        curr = curr->next;
    }

    new_node->next = curr->next;
    curr->next = new_node;
    printf("[Success] Inserted %d at position %d.\n", value, position);
    return 1;
}

/**
 * Traverses and displays the singly linked list visually
 */
void print_linked_list(const Node *head) {
    if (head == NULL) {
        printf("[List] List is currently empty.\n");
        return;
    }
    printf("[List]: ");
    const Node *curr = head;
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/**
 * Frees all allocated memory nodes in the list
 */
void free_linked_list(Node **head_ref) {
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
    int choice, val, pos;

    while (1) {
        printf("\n============================================\n");
        printf("   PRACTICAL 6: SINGLY LINKED LIST INSERTION \n");
        printf("============================================\n");
        printf("1. Insert at Beginning (Head)\n");
        printf("2. Insert at End (Tail)\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Display Linked List\n");
        printf("5. Exit Program\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_at_head(&list_head, val);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_at_tail(&list_head, val);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                printf("Enter position (1-based): ");
                scanf("%d", &pos);
                insert_at_position(&list_head, val, pos);
                break;

            case 4:
                print_linked_list(list_head);
                break;

            case 5:
                free_linked_list(&list_head);
                printf("Exiting Practical 6. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice from 1 to 5.\n");
        }
    }

    free_linked_list(&list_head);
    return 0;
}
