#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int isAlnum(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void infixToPostfix(char *infix, char *postfix) {
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

	if (isAlnum(token)) {
            postfix[j++] = token;
	} else if (token == '(') {
            push(token);
    } else if (token == ')') {
        while (top != -1 && stack[top] != '(')
            postfix[j++] = pop();
            pop();
    } else {
            while (top != -1 && precedence(stack[top]) >= precedence(token))
        	postfix[j++] = pop();
            push(token);
    }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Ekspresi infix: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Ekspresi postfix: %s\n", postfix);

    return 0;
}
