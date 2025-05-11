#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 50

typedef struct{
    char* arr;
    int front, rear;
}Queue;

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (char *)malloc(MAX * sizeof(char));
    q->front = 0, q->rear = -1;
    return q;
}

bool isFull(Queue *q){
    return q->rear == MAX-1;
}

bool isEmpty(Queue *q){
    return q->rear < q->front;
}

void enqueue(Queue *q, char c){
    if(isFull(q)){
        printf("Queue is full...can't enqueue.\n");
        return;
    }
    else{
        q->rear = q->rear + 1;
        q->arr[q->rear] = c;
    }
}

char dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty...can't dequeue.\n");
        return '\0';
    }
    else{
        char t = q->arr[q->front];
        q->front = q->front + 1;
        return t;
    }
}

void freeQueue(Queue *q){
    free(q->arr);
    free(q);
}

bool isPalindrome(Queue* q1, Queue* q2, char str[]){
    int len = strlen(str);

    for(int i=0; i<len; i++){
        enqueue(q1,str[len-i-1]);
        enqueue(q2,str[i]);
    }
    
    while(!isEmpty(q1) && !isEmpty(q2)){
        if(dequeue(q1)!=dequeue(q2)){
            return false;
        }
    }
    return true;
}

int main(){
    char str[MAX];
    Queue *q1 = createQueue();
    Queue *q2 = createQueue();
    printf("Enter a string : ");
    scanf("%s", str);
    if(isPalindrome(q1, q2, str)){
        printf("Entered string is a palindrome.\n");
    }
    else{
        printf("Entered string isn't a palindrome.\n");
    }
    freeQueue(q1);
    freeQueue(q2);
    return 0;
}