/**
 * Practical 2: Array Operations (Traversal, Insertion, Deletion, Linear & Binary Search)
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>

#define MAX_CAPACITY 100

/* Function prototypes */
void print_elements(const int arr[], int size);
int insert_element(int arr[], int *size, int value, int position);
int delete_element(int arr[], int *size, int position, int *removed_item);
int linear_search(const int arr[], int size, int key);
int is_sorted_ascending(const int arr[], int size);
int binary_search(const int arr[], int size, int key);

/**
 * Traverses and displays all active elements in the array
 */
void print_elements(const int arr[], int size) {
    if (size <= 0) {
        printf("[Status] Array is currently empty.\n");
        return;
    }
    printf("[Array Content] (Size: %d): [ ", size);
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i == size - 1) ? "" : ", ");
    }
    printf(" ]\n");
}

/**
 * Inserts a value at a 1-based position in the array
 */
int insert_element(int arr[], int *size, int value, int position) {
    if (*size >= MAX_CAPACITY) {
        printf("[Error] Overflow: Array capacity (%d) reached.\n", MAX_CAPACITY);
        return 0;
    }
    if (position < 1 || position > *size + 1) {
        printf("[Error] Invalid position. Allowed range: 1 to %d.\n", *size + 1);
        return 0;
    }

    int idx = position - 1;
    for (int i = *size; i > idx; i--) {
        arr[i] = arr[i - 1];
    }
    arr[idx] = value;
    (*size)++;
    return 1;
}

/**
 * Removes an element from a 1-based position in the array
 */
int delete_element(int arr[], int *size, int position, int *removed_item) {
    if (*size <= 0) {
        printf("[Error] Underflow: Array contains no elements to delete.\n");
        return 0;
    }
    if (position < 1 || position > *size) {
        printf("[Error] Invalid position. Allowed range: 1 to %d.\n", *size);
        return 0;
    }

    int idx = position - 1;
    *removed_item = arr[idx];
    for (int i = idx; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return 1;
}

/**
 * Linear Search: Scans sequentially through the array
 * Returns 0-based index or -1 if not found
 */
int linear_search(const int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

/**
 * Helper to verify whether array is sorted before binary search
 */
int is_sorted_ascending(const int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Binary Search: Divide-and-conquer search on a sorted array
 * Returns 0-based index or -1 if not found
 */
int binary_search(const int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int array[MAX_CAPACITY];
    int count = 0;
    int choice, val, pos, removed, index;

    printf("Enter number of initial elements (0 to %d): ", MAX_CAPACITY);
    if (scanf("%d", &count) == 1 && count > 0) {
        if (count > MAX_CAPACITY) {
            count = MAX_CAPACITY;
        }
        printf("Enter %d space-separated integers: ", count);
        for (int i = 0; i < count; i++) {
            scanf("%d", &array[i]);
        }
    } else {
        count = 0;
    }

    while (1) {
        printf("\n============================================\n");
        printf("         PRACTICAL 2: ARRAY OPERATIONS      \n");
        printf("============================================\n");
        printf("1. Display Array Elements\n");
        printf("2. Insert Element at Position\n");
        printf("3. Delete Element from Position\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search (Requires Sorted Array)\n");
        printf("6. Exit Program\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection.\n");
            break;
        }

        switch (choice) {
            case 1:
                print_elements(array, count);
                break;

            case 2:
                printf("Enter integer value to insert: ");
                scanf("%d", &val);
                printf("Enter insertion position (1 to %d): ", count + 1);
                scanf("%d", &pos);
                if (insert_element(array, &count, val, pos)) {
                    printf("[Success] Element %d inserted at position %d.\n", val, pos);
                }
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", count);
                scanf("%d", &pos);
                if (delete_element(array, &count, pos, &removed)) {
                    printf("[Success] Deleted element %d from position %d.\n", removed, pos);
                }
                break;

            case 4:
                printf("Enter target element for Linear Search: ");
                scanf("%d", &val);
                index = linear_search(array, count, val);
                if (index != -1) {
                    printf("[Result] Key %d found at index %d (Position %d).\n", val, index, index + 1);
                } else {
                    printf("[Result] Key %d was not found in the array.\n", val);
                }
                break;

            case 5:
                if (!is_sorted_ascending(array, count)) {
                    printf("[Notice] Binary Search requires sorted array. Current array is unsorted.\n");
                }
                printf("Enter target element for Binary Search: ");
                scanf("%d", &val);
                index = binary_search(array, count, val);
                if (index != -1) {
                    printf("[Result] Key %d found at index %d (Position %d).\n", val, index, index + 1);
                } else {
                    printf("[Result] Key %d was not found in the array.\n", val);
                }
                break;

            case 6:
                printf("Exiting Practical 2. Goodbye!\n");
                return 0;

            default:
                printf("Invalid selection! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
