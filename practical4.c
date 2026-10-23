/**
 * Practical 4: Conversion of Infix Expression to Postfix using Stack
 * Course: Data Structures Laboratory
 * Author: Jagrut Shah
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define EXPR_MAX 256

typedef struct {
    char items[EXPR_MAX];
    int top;
} CharStack;

/* Stack utility functions */
void char_stack_init(CharStack *s) {
    s->top = -1;
}

int char_stack_is_empty(const CharStack *s) {
    return s->top == -1;
}

void char_stack_push(CharStack *s, char ch) {
    if (s->top < EXPR_MAX - 1) {
        s->items[++(s->top)] = ch;
    }
}

char char_stack_pop(CharStack *s) {
    if (!char_stack_is_empty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char char_stack_peek(const CharStack *s) {
    if (!char_stack_is_empty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

/**
 * Returns operator precedence:
 *   '^'       -> 3 (Highest)
 *   '*', '/', '%' -> 2
 *   '+', '-'  -> 1
 *   Others    -> 0
 */
int get_precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

/**
 * Checks if operator is right-associative (exponentiation ^)
 */
int is_right_associative(char op) {
    return (op == '^');
}

/**
 * Checks if character is a valid mathematical operator
 */
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

/**
 * Converts standard infix mathematical expression to postfix notation
 */
void convert_infix_to_postfix(const char *infix, char *postfix) {
    CharStack stack;
    char_stack_init(&stack);

    int out_idx = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        /* Skip spaces and tabs */
        if (isspace((unsigned char)current)) {
            continue;
        }

        /* Operand: append directly to postfix string */
        if (isalnum((unsigned char)current)) {
            postfix[out_idx++] = current;
        }
        /* Left parenthesis: push directly to stack */
        else if (current == '(') {
            char_stack_push(&stack, current);
        }
        /* Right parenthesis: pop until matching '(' is found */
        else if (current == ')') {
            while (!char_stack_is_empty(&stack) && char_stack_peek(&stack) != '(') {
                postfix[out_idx++] = char_stack_pop(&stack);
            }
            if (!char_stack_is_empty(&stack) && char_stack_peek(&stack) == '(') {
                char_stack_pop(&stack); /* Discard the '(' */
            }
        }
        /* Operator encountered */
        else if (is_operator(current)) {
            while (!char_stack_is_empty(&stack) && char_stack_peek(&stack) != '(') {
                char top_op = char_stack_peek(&stack);
                int top_prec = get_precedence(top_op);
                int curr_prec = get_precedence(current);

                if ((!is_right_associative(current) && top_prec >= curr_prec) ||
                    (is_right_associative(current) && top_prec > curr_prec)) {
                    postfix[out_idx++] = char_stack_pop(&stack);
                } else {
                    break;
                }
            }
            char_stack_push(&stack, current);
        }
    }

    /* Pop all remaining operators from the stack */
    while (!char_stack_is_empty(&stack)) {
        char ch = char_stack_pop(&stack);
        if (ch != '(' && ch != ')') {
            postfix[out_idx++] = ch;
        }
    }

    postfix[out_idx] = '\0';
}

int main(void) {
    char infix_expr[EXPR_MAX];
    char postfix_expr[EXPR_MAX];

    printf("=====================================================\n");
    printf("   PRACTICAL 4: INFIX TO POSTFIX CONVERTER (STACK)   \n");
    printf("=====================================================\n");
    printf("Enter Infix Expression [e.g. (A+B)*C-(D-E)]: ");

    if (fgets(infix_expr, sizeof(infix_expr), stdin) != NULL) {
        /* Strip trailing newline */
        infix_expr[strcspn(infix_expr, "\r\n")] = '\0';

        if (strlen(infix_expr) == 0) {
            printf("[Notice] Provided expression is empty.\n");
            return 0;
        }

        convert_infix_to_postfix(infix_expr, postfix_expr);

        printf("\nInput Infix Expression   : %s\n", infix_expr);
        printf("Converted Postfix Result : %s\n", postfix_expr);
    }

    return 0;
}
