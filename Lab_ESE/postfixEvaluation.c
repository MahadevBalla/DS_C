#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

#define MAX 50
typedef struct stack
{
    int top;
    int stackArray[MAX];
}Stack;

int push(Stack *s,int data)
{
    if(s->top==MAX-1){
        return 0;
    }
    (s->top)++;
    s->stackArray[s->top]=data;
    return 1;
}

int pop(Stack *s)
{
    char x;
    if(s->top==-1){
        return ' ';
    }
    x = s->stackArray[s->top];
    (s->top)--;
    return x;
}

char peek(Stack *s){
    if(s->top==-1){
        return ' ';
    }else
        return s->stackArray[s->top];
}

int isEmpty(Stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isAlphaNumeric(char c)
{
    if(c>='A'&&c<='Z')
        return 1;
    return 0;
}
void toUpperCase(char arr[])
{
    int i,n = strlen(arr);
    for(i=0;i<n;i++)
    {
        if(arr[i]>='a' && arr[i]<='z')
        {
            arr[i] -= 32; 
        }
    }
}
int postfixEvaluation(char postfix[],int *values,int numOfVar)
{
    toUpperCase(postfix);
    int i,val=0;
    char x1,x2;
    int n = strlen(postfix);
    char symbol,operator;
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top=-1;
    for(i=0;i<n;i++)
    {
        symbol = postfix[i];
        if(isAlphaNumeric(symbol))
        {
            push(s,symbol);
            s->stackArray[s->top] = values[(int)symbol-65];
        }
        else
        {
            x1 = pop(s);
            x2 = pop(s);

            switch(symbol)
            {
                case '+':
                val = x2+x1;
                break;
                
                case '-':
                val = x2-x1;
                break;

                case '*':
                val = x2*x1;
                break;

                case '/':
                val = x2/x1;
                break;
            }
            push(s,val);
        }
    }
    return pop(s);
}

    
int main()
{
    int *values;
    int i,numOfVar,result;
    char postfix[MAX];
    char c = 'A';

    printf("Enter total number of variables : ");
    fflush(stdin);
    scanf("%d",&numOfVar);
    fflush(stdin);

    printf("Enter Postfix String : ");
    gets(postfix);
    fflush(stdin);
    values = (int*)malloc(sizeof(int)*numOfVar);

    for(i=0;i<numOfVar;i++)
    {
        printf("Enter Value Of %c : ",c+i);
        scanf("%d",&values[i]);
    }
        

    result = postfixEvaluation(postfix,values,numOfVar);

    printf("Final Answer : %d\n",result);
}
