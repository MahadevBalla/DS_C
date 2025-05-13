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

bool isOperator(char c){
    return c=='+' || c=='-' || c=='*' || c=='/';
}

int ans;

void evalPost(char *s){
    Stack *st = createStack();
    int top1, top2;
    for(int i=0; i<strlen(s); i++){
        if(isdigit(s[i])){
            push(st, s[i]-'0');
        }
        else if(isOperator(s[i])){
            top1 = top(st);
            pop(st);
            top2 = top(st);
            pop(st);
            switch(s[i]){
                case '+':
                    push(st, top2+top1);
                    break;
                case '-':
                    push(st, top2-top1);
                    break;
                case '*':
                    push(st, top2*top1);
                    break;
                case '/':
                    push(st, top2/top1);
                    break; 
            }
        }
    }
    ans = top(st);
    freeStack(st);
}

int main(){
    char postfix[MAX];

    printf("Enter postfix expression : ");
    scanf("%s", postfix);

    evalPost(postfix);
    printf("Answer : %d\n", ans);
    return 0;
}