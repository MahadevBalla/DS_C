#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the queue

typedef struct {
    int front, rear, size;
    int *array;
} CircularQueue;

// Function to initialize the queue
CircularQueue* createQueue(int capacity) {
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    queue->size = capacity;
    queue->front = queue->rear = 0;
    queue->array = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % queue->size == queue->front);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *queue) {
    return (queue->front == queue->rear);
}

// Function to enqueue an element
void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }
    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->size;
}

// Function to dequeue an element
int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Return -1 or any sentinel value to indicate an error
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return item;
}

// Function to get the front element
int front(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 or any sentinel value to indicate an error
    }
    return queue->array[queue->front];
}

// Function to display the queue
void displayQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

// Function to free the queue
void freeQueue(CircularQueue *queue) {
    free(queue->array);
    free(queue);
}

int main() {
    CircularQueue *queue = createQueue(MAX);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    displayQueue(queue);

    freeQueue(queue);
    return 0;
}