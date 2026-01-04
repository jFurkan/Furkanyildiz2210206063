#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


char stack[MAX];
int top = -1;


void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack dolu!\n");
    } else {
        stack[++top] = item;
    }
}


char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}


int oncelik(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}


int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0; 
    int j = 0; 
    char x;

    while (infix[i] != '\0') {
       
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        
        else if (infix[i] == '(') {
            push(infix[i]);
        }
       
        else if (infix[i] == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
       
        else if (isOperator(infix[i])) {
           
            while (top != -1 && oncelik(peek()) >= oncelik(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

   
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Infix ifadeyi giriniz (Orn: A+B*C): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Hali: %s\n", postfix);

    return 0;
}
