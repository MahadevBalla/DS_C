#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct Stack{
    int top;
    char *arr;
}Stack;

Stack *createStack(){
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->arr = (char *)malloc(MAX * sizeof(char));
    st->top = -1;
    return st;
}

bool isEmpty(Stack *st){
    return st->top==-1;
}

bool isFull(Stack *st){
    return st->top==MAX-1;
}

char top(Stack *st){
    if(isEmpty(st)){
        printf("Stack is empty!\n");
        return '\0';
    }
    return st->arr[st->top];
}

void push(Stack *st, char c){
    if(isFull(st)){
        printf("Stack is full...can't push!\n");
    }
    st->arr[++st->top] = c;
}

void pop(Stack *st){
    if(isEmpty(st)){
        printf("Stack is empty...can't pop!\n");
        return;
    }
    st->arr[st->top--];
}

void freeStack(Stack *st){
    free(st->arr);
    free(st);
}

int precedence(char c){
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return 0;
}

void infixToPostfix(char *s, char *ans){
    Stack *st = createStack();
    int j = 0;
    for(int i=0; i<strlen(s); i++){
        if(isalnum(s[i])){
            ans[j++] = s[i];
        }
        else if(s[i]=='('){
            push(st, s[i]);
        }
        else if(s[i]==')'){
            while(!isEmpty(st) && top(st)!='('){
                char temp = top(st);
                pop(st);
                ans[j++] = temp;
            }
            pop(st);
        }
        else{
            while(!isEmpty(st) && precedence(s[i])<=precedence(top(st))){
                char temp = top(st);
                pop(st);
                ans[j++] = temp;
            }
            push(st, s[i]);
        }
    }

    while(!isEmpty(st)){
        char temp = top(st);
        pop(st);
        ans[j++] = temp;
    }
    ans[j]='\0';
    freeStack(st);
}

int main(){
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression : ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression : %s\n", postfix);
    return 0;
}