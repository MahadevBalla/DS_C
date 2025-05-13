#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define stackSize 100

typedef struct{
    int topp;
    int *arr;
}Stack;

Stack *initStack(){
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->topp = -1;
    stack->arr = (int*)malloc(stackSize * sizeof(int));
    return stack;
}

void push(Stack *stack, int n){
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

void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}

int evaluatePrefix(char* s){
    Stack* stack = initStack();
    for(int i=strlen(s)-1; i>=0; i--){
        if(isdigit(s[i])){
            push(stack, s[i]-'0');
        }
        else{
            int t1 = top(stack);
            pop(stack);
            int t2 = top(stack);
            pop(stack);
            switch(s[i]){
            case '+': push(stack, (t1+t2)); break;
            case '-': push(stack, (t1-t2)); break;
            case '*': push(stack, (t1*t2)); break;
            case '/': 
                if(t2==0){
                    printf("Division by zero encountered...exiting!\n");
                    freeStack(stack);
                    return -1;
                }
                push(stack, (t1/t2));
                break;
            default: printf("Encountered an invalid character!\n");
            }
        }
    }

    if(size(stack)>1){
        printf("Enter a valid prefix expression!\n");
        return -1;
    }
    int temp = top(stack);
    freeStack(stack); 
    return temp;
}

int main(){
    char s[100];
    printf("Enter input : ");
    scanf("%s", s);
    int ans = evaluatePrefix(s);
    if(ans!=-1){
        printf("Answer : %d", ans);
    }
    return 0;
}