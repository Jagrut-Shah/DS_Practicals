/**
 * Practical 5: Implementation of Linear Queue using Array (INSERT, DELETE, DISPLAY)
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>

#define QUEUE_CAPACITY 5

typedef struct {
    int buffer[QUEUE_CAPACITY];
    int front;
    int rear;
} LinearQueue;

/* Function prototypes */
void queue_init(LinearQueue *q);
int queue_is_full(const LinearQueue *q);
int queue_is_empty(const LinearQueue *q);
int queue_enqueue(LinearQueue *q, int element);
int queue_dequeue(LinearQueue *q, int *removed_element);
void queue_display(const LinearQueue *q);

/**
 * Initializes empty queue state
 */
void queue_init(LinearQueue *q) {
    q->front = -1;
    q->rear = -1;
}

/**
 * Checks if queue has hit maximum boundary
 */
int queue_is_full(const LinearQueue *q) {
    return q->rear == QUEUE_CAPACITY - 1;
}

/**
 * Checks if queue is currently empty
 */
int queue_is_empty(const LinearQueue *q) {
    return (q->front == -1 || q->front > q->rear);
}

/**
 * Inserts an element at the rear of the queue
 */
int queue_enqueue(LinearQueue *q, int element) {
    if (queue_is_full(q)) {
        printf("[Overflow] Queue is full! Cannot insert %d.\n", element);
        return 0;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->buffer[q->rear] = element;
    printf("[Success] Enqueued element: %d\n", element);
    return 1;
}

/**
 * Removes and retrieves the element at the front of the queue
 */
int queue_dequeue(LinearQueue *q, int *removed_element) {
    if (queue_is_empty(q)) {
        printf("[Underflow] Queue is empty! No element to delete.\n");
        return 0;
    }
    *removed_element = q->buffer[q->front];
    q->front++;

    /* Reset indices when queue becomes empty to reclaim space */
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return 1;
}

/**
 * Displays all elements between front and rear indices
 */
void queue_display(const LinearQueue *q) {
    if (queue_is_empty(q)) {
        printf("[Display] Queue is currently empty.\n");
        return;
    }
    printf("Queue elements (Front to Rear): [ ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d%s", q->buffer[i], (i == q->rear) ? "" : ", ");
    }
    printf(" ] (Front index: %d, Rear index: %d)\n", q->front, q->rear);
}

int main(void) {
    LinearQueue my_queue;
    queue_init(&my_queue);

    int choice, value, removed;

    while (1) {
        printf("\n============================================\n");
        printf("         PRACTICAL 5: LINEAR QUEUE ADT      \n");
        printf("============================================\n");
        printf("1. ENQUEUE (Insert element)\n");
        printf("2. DEQUEUE (Delete element)\n");
        printf("3. DISPLAY (View elements)\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter integer value to insert: ");
                scanf("%d", &value);
                queue_enqueue(&my_queue, value);
                break;

            case 2:
                if (queue_dequeue(&my_queue, &removed)) {
                    printf("[Success] Dequeued element: %d\n", removed);
                }
                break;

            case 3:
                queue_display(&my_queue);
                break;

            case 4:
                printf("Exiting Practical 5. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice from 1 to 4.\n");
        }
    }

    return 0;
}
