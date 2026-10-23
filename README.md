# Data Structures Laboratory Practicals

A curated, comprehensive suite of 10 Data Structures laboratory implementations in C, covering fundamental algorithmic concepts, linear data structures, non-linear hierarchical trees, and pointer-based memory management.

**Author:** [Jagrut Shah](https://github.com/Jagrut-Shah)  
**Repository:** [DS_Practicals](https://github.com/Jagrut-Shah/DS_Practicals)  
**Language:** C (C99 / C11 compatible)

---

## Table of Contents

- [Overview of Practicals](#overview-of-practicals)
- [Directory Structure](#directory-structure)
- [Compilation & Execution Guide](#compilation--execution-guide)
  - [Windows (GCC / MinGW / Clang)](#windows-gcc--mingw--clang)
  - [Linux / macOS](#linux--macos)
- [Practical Summaries & Sample Traces](#practical-summaries--sample-traces)
  - [Practical 1: Pointers & Parameter Passing](#practical-1-pointers--parameter-passing)
  - [Practical 2: Array Operations & Searching](#practical-2-array-operations--searching)
  - [Practical 3: Stack Abstract Data Type](#practical-3-stack-abstract-data-type)
  - [Practical 4: Infix to Postfix Converter](#practical-4-infix-to-postfix-converter)
  - [Practical 5: Linear Queue ADT](#practical-5-linear-queue-adt)
  - [Practical 6: Singly Linked List (Insertion)](#practical-6-singly-linked-list-insertion)
  - [Practical 7: Singly Linked List (Deletion)](#practical-7-singly-linked-list-deletion)
  - [Practical 8: Doubly Linked List Operations](#practical-8-doubly-linked-list-operations)
  - [Practical 9: Binary Search Tree (BST)](#practical-9-binary-search-tree-bst)
  - [Practical 10: Binary Tree Construction & Traversals](#practical-10-binary-tree-construction--traversals)

---

## Overview of Practicals

| Practical | Source File | Core Topics & Operations | Time Complexity |
|---|---|---|---|
| **Practical 1** | `practical1.c` | Pointers, Address Operator, Dereferencing, Call by Value vs Reference | $\mathcal{O}(1)$ |
| **Practical 2** | `practical2.c` | Array Traversal, Insertion, Deletion, Linear Search, Binary Search | Insert/Delete: $\mathcal{O}(n)$, Binary Search: $\mathcal{O}(\log n)$ |
| **Practical 3** | `practical3.c` | Array-based Stack: PUSH, POP, PEEP, CHANGE, DISPLAY | $\mathcal{O}(1)$ per operation |
| **Practical 4** | `practical4.c` | Stack Application: Infix to Postfix Expression Conversion | $\mathcal{O}(n)$ |
| **Practical 5** | `practical5.c` | Array-based Linear Queue: ENQUEUE, DEQUEUE, DISPLAY | $\mathcal{O}(1)$ per operation |
| **Practical 6** | `practical6.c` | Singly Linked List: Insert at Head, Tail, and $k$-th Position | Head: $\mathcal{O}(1)$, Tail/Pos: $\mathcal{O}(n)$ |
| **Practical 7** | `practical7.c` | Singly Linked List: Delete Head, Tail, and $k$-th Position | Head: $\mathcal{O}(1)$, Tail/Pos: $\mathcal{O}(n)$ |
| **Practical 8** | `practical8.c` | Doubly Linked List: Insert, Delete, Forward & Backward Traversals | Insert/Delete Head: $\mathcal{O}(1)$, Pos: $\mathcal{O}(n)$ |
| **Practical 9** | `practical9.c` | Binary Search Tree: Dynamic Insert, Search, Inorder (Sorted) Traversal | Balanced: $\mathcal{O}(\log n)$, Worst: $\mathcal{O}(n)$ |
| **Practical 10** | `practical10.c` | Binary Tree: Recursive Build, Inorder, Preorder, Postorder Traversals | $\mathcal{O}(n)$ for all traversals |

---

## Directory Structure

```text
DS_Practicals/
├── README.md         # Documentation, syllabus map, and run instructions
├── practical1.c      # Pointers and Parameter Passing
├── practical2.c      # Array Operations & Search Algorithms
├── practical3.c      # Stack Implementation (PUSH, POP, PEEP, CHANGE)
├── practical4.c      # Infix to Postfix Expression Translation
├── practical5.c      # Linear Queue Implementation
├── practical6.c      # Singly Linked List (Node Insertion)
├── practical7.c      # Singly Linked List (Node Deletion)
├── practical8.c      # Doubly Linked List (Insert, Delete, Two-Way Traversal)
├── practical9.c      # Binary Search Tree (BST)
└── practical10.c     # Binary Tree Construction & Traversals
```

---

## Compilation & Execution Guide

Each practical is a self-contained, interactive C program with standard ANSI/ISO C compliance and robust input handling.

### Windows (GCC / MinGW / Clang)

Compile with warnings enabled:
```powershell
gcc -Wall -Wextra practical1.c -o practical1.exe
.\practical1.exe
```

### Linux / macOS

```bash
gcc -Wall -Wextra practical1.c -o practical1
./practical1
```

---

## Practical Summaries & Sample Traces

### Practical 1: Pointers & Parameter Passing
Demonstrates direct memory manipulation using pointer variables and compares Call by Value (which works on local copies) with Call by Reference (which modifies caller memory directly).

```text
--- Sample Run ---
Before calling swap_by_reference: x = 15, y = 30
  [Inside swap_by_reference] *ptr1 = 30, *ptr2 = 15
After calling swap_by_reference:  x = 30, y = 15 (SWAPPED)
```

### Practical 2: Array Operations & Searching
Provides menu-driven array manipulation including bounds checking, element shifting for insertion and deletion, linear scanning ($\mathcal{O}(n)$), and binary search ($\mathcal{O}(\log n)$).

```text
--- Sample Run ---
Enter insertion position (1 to 4): 2
[Success] Element 25 inserted at position 2.
[Array Content] (Size: 4): [ 10, 25, 20, 30 ]
```

### Practical 3: Stack Abstract Data Type
Implements a fixed-size LIFO (Last In First Out) structure with overflow/underflow detection, element inspection (`PEEP`) from the top, and dynamic element modification (`CHANGE`).

```text
--- Sample Run ---
1. PUSH  2. POP  3. PEEP  4. CHANGE  5. DISPLAY
Enter choice: 1 -> Value: 40
[Success] 40 pushed to stack.
 |   40 | <-- TOP
 |   20 |
 |   10 |
 -------
```

### Practical 4: Infix to Postfix Converter
Uses operator precedence parsing and an operator stack to convert human-readable infix arithmetic notation into postfix (Reverse Polish) notation, respecting associativity rules (including right-associative exponentiation `^`).

```text
Enter Infix Expression: (A+B)*C-(D-E)
Input Infix Expression   : (A+B)*C-(D-E)
Converted Postfix Result : AB+C*DE--
```

### Practical 5: Linear Queue ADT
Implements a sequential FIFO (First In First Out) queue using an array buffer. Automatically resets indices upon reaching emptiness to reclaim space.

```text
Queue elements (Front to Rear): [ 12, 24, 36 ] (Front index: 0, Rear index: 2)
[Success] Dequeued element: 12
```

### Practical 6: Singly Linked List (Insertion)
Demonstrates dynamic heap allocation with `malloc`, pointer linking, and node insertion at the head, tail, or any valid intermediate position with $\mathcal{O}(1)$ or $\mathcal{O}(n)$ complexity.

```text
[Success] Inserted 100 at position 2.
[List]: [10] -> [100] -> [20] -> [30] -> NULL
```

### Practical 7: Singly Linked List (Deletion)
Implements clean node unlinking and deallocation with `free` for head nodes, tail nodes, and nodes at arbitrary 1-based indices, preventing memory leaks.

```text
[Success] Deleted node at position 2 with value: 100
[Linked List]: [10] -> [20] -> [30] -> NULL
```

### Practical 8: Doubly Linked List Operations
Demonstrates two-way linked list structures featuring both `prev` and `next` pointers. Enables bidirectional traversals (forward and backward) and symmetric insertion/deletion.

```text
[Forward Traversal] : NULL <--> [10] <--> [20] <--> [30] <--> NULL
[Backward Traversal]: NULL <--> [30] <--> [20] <--> [10] <--> NULL
```

### Practical 9: Binary Search Tree (BST)
Creates a dynamically allocated Binary Search Tree where each node preserves the invariant: $\text{left.key} < \text{node.key} < \text{right.key}$. Inorder traversal produces a sorted key sequence.

```text
Inserted keys: 50, 30, 70, 20, 40, 60, 80
Inorder Traversal: [ 20 30 40 50 60 70 80 ]
Key 40 found in BST.
```

### Practical 10: Binary Tree Construction & Traversals
Builds a general binary tree recursively from user input (with `-1` marking empty subtrees) and demonstrates all three standard depth-first traversals (Inorder, Preorder, Postorder) along with tree height and node counts.

```text
Inorder Traversal   : [ 4 2 5 1 6 3 7 ]
Preorder Traversal  : [ 1 2 4 5 3 6 7 ]
Postorder Traversal : [ 4 5 2 6 7 3 1 ]
Total Nodes: 7 | Tree Height: 3
```

---

## License

This repository is maintained for educational purposes. Feel free to use and reference for academic study.
