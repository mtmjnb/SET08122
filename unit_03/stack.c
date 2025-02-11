#include <stdio.h>
#include "stack.h"

#define MAX 11

struct stack {
    int array[MAX];
    int top;
};

void main() {
    struct stack stack;

    init(&stack);

    push(&stack, 11);
    push(&stack, 23);
    push(&stack, -8);
    push(&stack, 16);
    push(&stack, 27);
    push(&stack, 14);
    push(&stack, 20);
    push(&stack, 39);
    push(&stack, 2);
    push(&stack, 15);
    push(&stack, 7);

    int *i = NULL;

    for (int j=0; j<11; j++) {
        i = pop(&stack);
        if (i) {
            printf("Item popped: %d\n", *i);
        }
    }
}

void init(struct stack *stack) {
    stack->top =-1;
}

void push(struct stack *stack, int item) {
    if (stack->top == MAX-1) {
        printf("Stack is full. Couldn't push '%d' onto stack\n", item);
        return;
    }
    stack->top++;
    stack->array[stack->top] = item;
}

int *pop(struct stack *stack) {
    int *data;
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return NULL;
    }
    data = &stack->array[stack->top];
    stack->top--;
    return data;
}
