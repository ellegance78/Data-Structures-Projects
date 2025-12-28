#include <stdio.h>
#include <ctype.h> 

int oncelik(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    char stack[100];
    int top = -1;
    int i = 0;
    char sembol;
    printf("Postfix Sonuc: ");
    while ((sembol = infix[i++]) != '\0') {
        if (isalnum(sembol)) {
            printf("%c", sembol);
        } 
        else if (sembol == '(') {
            stack[++top] = sembol;
        } 
        else if (sembol == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            top--;
        } 
        else {
            while (top != -1 && oncelik(stack[top]) >= oncelik(sembol)) {
                printf("%c", stack[top--]);
            }
            stack[++top] = sembol;
        }
    }
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");
}

int main() {
    char ifade[] = "a+b*(c-d)";
    printf("Infix: %s\n", ifade);
    infixToPostfix(ifade);
    return 0;
}
