#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    char data[1000];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char ch) {
    stack->data[++stack->top] = ch;
}

char pop(struct Stack *stack) {
    return stack->data[stack->top--];
}

bool isValid(char *s) {
    struct Stack st;
    initialize(&st);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&st, s[i]);
        } else {
            if (st.top == -1 || (s[i] == ')' && pop(&st) != '(') || (s[i] == '}' && pop(&st) != '{') || (s[i] == ']' && pop(&st) != '[')) {
                return false;
            }
        }
    }

    return st.top == -1;
}

int main() {
    char expression[1000];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isValid(expression)) {
        printf("Valid parentheses!\n");
    } else {
        printf("Invalid parentheses!\n");
    }

    return 0;
}
