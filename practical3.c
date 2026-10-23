/**
 * Practical 3: Implementation of Stack using Array (PUSH, POP, PEEP, CHANGE, DISPLAY)
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>

#define STACK_CAPACITY 5

typedef struct {
    int data[STACK_CAPACITY];
    int top;
} Stack;

/* Function prototypes */
void stack_init(Stack *s);
int stack_is_full(const Stack *s);
int stack_is_empty(const Stack *s);
int stack_push(Stack *s, int value);
int stack_pop(Stack *s, int *popped_value);
int stack_peep(const Stack *s, int pos_from_top, int *peeped_value);
int stack_change(Stack *s, int pos_from_top, int new_value, int *old_value);
void stack_display(const Stack *s);

/**
 * Initializes stack with top set to -1
 */
void stack_init(Stack *s) {
    s->top = -1;
}

/**
 * Checks if stack has reached maximum capacity
 */
int stack_is_full(const Stack *s) {
    return s->top >= STACK_CAPACITY - 1;
}

/**
 * Checks if stack contains zero elements
 */
int stack_is_empty(const Stack *s) {
    return s->top == -1;
}

/**
 * Inserts an element onto the top of the stack
 */
int stack_push(Stack *s, int value) {
    if (stack_is_full(s)) {
        printf("[Overflow] Stack is full! Cannot push %d.\n", value);
        return 0;
    }
    s->top++;
    s->data[s->top] = value;
    printf("[Success] %d pushed to stack.\n", value);
    return 1;
}

/**
 * Removes and returns the top element from the stack
 */
int stack_pop(Stack *s, int *popped_value) {
    if (stack_is_empty(s)) {
        printf("[Underflow] Stack is empty! No element to pop.\n");
        return 0;
    }
    *popped_value = s->data[s->top];
    s->top--;
    return 1;
}

/**
 * Inspects element at the i-th position relative to top (1 = top element)
 * Formula: target_index = top - i + 1
 */
int stack_peep(const Stack *s, int pos_from_top, int *peeped_value) {
    if (stack_is_empty(s)) {
        printf("[Error] Stack is empty.\n");
        return 0;
    }
    int target_idx = s->top - pos_from_top + 1;
    if (pos_from_top <= 0 || target_idx < 0) {
        printf("[Error] Invalid position. Position from top must be between 1 and %d.\n", s->top + 1);
        return 0;
    }
    *peeped_value = s->data[target_idx];
    return 1;
}

/**
 * Modifies element at the i-th position relative to top
 * Formula: target_index = top - i + 1
 */
int stack_change(Stack *s, int pos_from_top, int new_value, int *old_value) {
    if (stack_is_empty(s)) {
        printf("[Error] Stack is empty.\n");
        return 0;
    }
    int target_idx = s->top - pos_from_top + 1;
    if (pos_from_top <= 0 || target_idx < 0) {
        printf("[Error] Invalid position. Position from top must be between 1 and %d.\n", s->top + 1);
        return 0;
    }
    *old_value = s->data[target_idx];
    s->data[target_idx] = new_value;
    return 1;
}

/**
 * Visualizes stack from top to bottom
 */
void stack_display(const Stack *s) {
    if (stack_is_empty(s)) {
        printf("[Display] Stack is currently empty.\n");
        return;
    }
    printf("\n--- Stack Contents (Top -> Bottom) ---\n");
    for (int i = s->top; i >= 0; i--) {
        if (i == s->top) {
            printf(" | %4d | <-- TOP\n", s->data[i]);
        } else {
            printf(" | %4d |\n", s->data[i]);
        }
    }
    printf(" -------\n");
}

int main(void) {
    Stack my_stack;
    stack_init(&my_stack);

    int choice, value, position, popped, old_val;

    while (1) {
        printf("\n============================================\n");
        printf("         PRACTICAL 3: STACK ADT (ARRAY)     \n");
        printf("============================================\n");
        printf("1. PUSH (Insert onto stack)\n");
        printf("2. POP (Delete from stack)\n");
        printf("3. PEEP (Inspect i-th from top)\n");
        printf("4. CHANGE (Update i-th from top)\n");
        printf("5. DISPLAY (Show stack layout)\n");
        printf("6. Exit Program\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                stack_push(&my_stack, value);
                break;

            case 2:
                if (stack_pop(&my_stack, &popped)) {
                    printf("[Success] Popped element: %d\n", popped);
                }
                break;

            case 3:
                printf("Enter position from top (1 = current top): ");
                scanf("%d", &position);
                if (stack_peep(&my_stack, position, &value)) {
                    printf("[Result] Element at position %d from top is %d.\n", position, value);
                }
                break;

            case 4:
                printf("Enter position from top (1 = current top): ");
                scanf("%d", &position);
                printf("Enter new replacement value: ");
                scanf("%d", &value);
                if (stack_change(&my_stack, position, value, &old_val)) {
                    printf("[Success] Element %d at position %d changed to %d.\n", old_val, position, value);
                }
                break;

            case 5:
                stack_display(&my_stack);
                break;

            case 6:
                printf("Exiting Practical 3. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice between 1 and 6.\n");
        }
    }

    return 0;
}
