/**
 * Practical 1: Demonstration of Pointers, Call by Value, and Call by Reference
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>

/* Function prototypes */
void demonstrate_pointer_basics(void);
void swap_by_value(int num1, int num2);
void swap_by_reference(int *ptr1, int *ptr2);

/**
 * Illustrates pointer variables, addresses (&), and dereferencing (*)
 */
void demonstrate_pointer_basics(void) {
    int target = 42;
    int *ptr = &target;

    printf("\n=== Pointer Fundamentals ===\n");
    printf("Target variable value       : %d\n", target);
    printf("Address of target (&target) : %p\n", (void *)&target);
    printf("Pointer variable value (ptr): %p\n", (void *)ptr);
    printf("Dereferenced value (*ptr)   : %d\n", *ptr);

    /* Modify value through pointer */
    *ptr = 99;
    printf("\nAfter modifying via pointer (*ptr = 99):\n");
    printf("Updated target value        : %d\n", target);
}

/**
 * Call by Value: Arguments are copied into local parameters.
 * Original caller variables remain unchanged.
 */
void swap_by_value(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
    printf("  [Inside swap_by_value]    num1 = %d, num2 = %d\n", num1, num2);
}

/**
 * Call by Reference: Memory addresses are passed.
 * Mutates caller's actual variables through pointer dereferencing.
 */
void swap_by_reference(int *ptr1, int *ptr2) {
    if (ptr1 == NULL || ptr2 == NULL) {
        return;
    }
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("  [Inside swap_by_reference] *ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
}

int main(void) {
    int option;
    int x, y;

    while (1) {
        printf("\n============================================\n");
        printf("  PRACTICAL 1: POINTERS & PARAMETER PASSING  \n");
        printf("============================================\n");
        printf("1. Pointer Basics & Dereferencing\n");
        printf("2. Call by Value Demonstration\n");
        printf("3. Call by Reference Demonstration\n");
        printf("4. Exit Program\n");
        printf("Select an option (1-4): ");

        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Terminating.\n");
            break;
        }

        switch (option) {
            case 1:
                demonstrate_pointer_basics();
                break;

            case 2:
                printf("\nEnter two integers (x and y): ");
                if (scanf("%d %d", &x, &y) != 2) {
                    printf("Invalid input.\n");
                    break;
                }
                printf("Before calling swap_by_value:    x = %d, y = %d\n", x, y);
                swap_by_value(x, y);
                printf("After calling swap_by_value:     x = %d, y = %d (UNCHANGED)\n", x, y);
                break;

            case 3:
                printf("\nEnter two integers (x and y): ");
                if (scanf("%d %d", &x, &y) != 2) {
                    printf("Invalid input.\n");
                    break;
                }
                printf("Before calling swap_by_reference: x = %d, y = %d\n", x, y);
                swap_by_reference(&x, &y);
                printf("After calling swap_by_reference:  x = %d, y = %d (SWAPPED)\n", x, y);
                break;

            case 4:
                printf("Exiting Practical 1. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a choice between 1 and 4.\n");
        }
    }

    return 0;
}
