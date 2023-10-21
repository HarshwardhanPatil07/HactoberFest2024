//GitHub - Divyansh200102
// Aim:  A basic stack data structure with push and pop operations. 
// Date: October 20, 2023
#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Define a stack structure
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int data) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow: Cannot push %d\n", data);
    } else {
        stack->arr[++stack->top] = data;
        printf("%d pushed to the stack\n", data);
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top < 0) {
        printf("Stack underflow: Stack is empty\n");
        return -1; // Return a sentinel value to indicate underflow
    } else {
        return stack->arr[stack->top--];
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d popped from the stack\n", pop(&stack));
    printf("%d popped from the stack\n", pop(&stack));
    printf("%d popped from the stack\n", pop(&stack));
    printf("%d popped from the stack\n", pop(&stack); // Try to pop when the stack is empty

    return 0;
}
