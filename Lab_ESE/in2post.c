#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define stackSize 100

typedef struct{
    int topp;
    char *arr;
}Stack;

Stack *initStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->topp = -1;
    stack->arr = (char*)malloc(stackSize * sizeof(char));
    return stack;
}

void push(Stack *stack, char n){
    if(stack->topp>=stackSize-1){
        printf("Overflow\n");
        return;
    }     
    stack->topp++;
    stack->arr[stack->topp]=n;
}

void pop(Stack *stack){
    if(stack->topp<0){
        printf("Underflow\n");
        return;
    }
    stack->topp--;
}

char top(Stack *stack){
    if(stack->topp<0){
        printf("underflow");
        return -1;
    }
    return stack->arr[stack->topp];
}

int size(Stack *stack){
    return stack->topp+1;
}

int isEmpty(Stack *stack){
    return stack->topp == -1;
}

int precedence(char c){
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

void infixToPostfix(Stack *stack,char *s, char *ans){
    ans[0] = '\0';
    for(int i=0; i<strlen(s); i++){
        if(isalnum(s[i])){
            strncat(ans, &s[i], 1);
        }
        else if(s[i] == '('){
            push(stack, '(');
        }
        else if(s[i] == ')'){
            while(!isEmpty(stack) && top(stack)!='('){
                char temp = top(stack);
                strncat(ans, &temp, 1);
                pop(stack);
            }
            pop(stack);
        }
        // else if(isOperator(c)){
        else{
            while(!isEmpty(stack) && precedence(s[i])<=precedence(top(stack))){
                char temp = top(stack);
                strncat(ans, &temp, 1);
                pop(stack);
            }
            push(stack, s[i]);
        }
    }
    while(!isEmpty(stack)){
        char temp = top(stack);
        strncat(ans, &temp, 1);
        pop(stack);
    }
}

int main(){
    char s[50];
    char ans[50];
    printf("Enter input : ");
    scanf("%s", s);
    Stack *stack = initStack();
    infixToPostfix(stack, s, ans);
    printf("Postfix form : %s\n", ans);
    freeStack(stack);
    return 0;
}