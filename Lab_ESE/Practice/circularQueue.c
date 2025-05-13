#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circularQueue{
    int *arr, front, rear, size;
}circularQueue;

circularQueue *createQueue(int max_size){
    circularQueue *cq = (circularQueue *)malloc(sizeof(circularQueue));
    cq->size = max_size;
    cq->front = 0, cq->rear = 0;
    cq->arr = (int *)malloc(sizeof(cq->size * sizeof(int)));
    return cq;
}

int isEmpty(circularQueue *cq){
    return cq->front==cq->rear;
}

bool isFull(circularQueue *cq){
    return (cq->rear+1)%cq->size==cq->front;
}

void enqueue(circularQueue *cq, int val){
    if(isFull(cq)){
        printf("Can't enqueue...is full!");
        return;
    }
    cq->arr[cq->rear] = val;
    cq->rear = (cq->rear+1)%cq->size;
}

int dequeue(circularQueue *cq){
    if(isEmpty(cq)){
        printf("Queue is empty!");
        return -1;
    }
    int temp = cq->arr[cq->front];
    cq->front = (cq->front+1)%cq->size;
    return temp;
}

int front(circularQueue *cq){
    if(isEmpty(cq)){
        printf("Queue is empty!");
        return -1;
    }
    return cq->arr[cq->front];
}

int rear(circularQueue *cq){
    if(isEmpty(cq)){
        printf("Queue is empty!");
        return -1;
    }
    return cq->arr[cq->rear];
}

void displayQueue(circularQueue *cq){
    if(isEmpty(cq)){
        printf("Queue is empty!");
        return;
    }

    for(int i=cq->front; i!=cq->rear; i=(i+1)%cq->size){
        printf("%d  ", cq->arr[i]);
    }
    printf("\n");
}

void freeQueue(circularQueue *cq){
    free(cq->arr);
    free(cq);
}

int main(){
    circularQueue *cq = createQueue(10);
    enqueue(cq, 1);
    enqueue(cq, 2);
    enqueue(cq, 3);

    displayQueue(cq);
    dequeue(cq);
    dequeue(cq);
    enqueue(cq, 4);
    enqueue(cq, 5);
    displayQueue(cq);

    freeQueue(cq);
    return 0;
}