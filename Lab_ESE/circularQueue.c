#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int front, rear, size;
    int *array;
} CircularQueue;

CircularQueue* createQueue(int x){
    CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
    queue->size = x;
    queue->front = queue->rear = 0;
    queue->array = (int *)malloc(queue->size * sizeof(int));
    return queue;
}

int isFull(CircularQueue *queue){
    return ((queue->rear + 1) % queue->size == queue->front);
}

int isEmpty(CircularQueue *queue){
    return (queue->front == queue->rear);
}

void enqueue(CircularQueue *queue, int item){
    if (isFull(queue)) {
        printf("Queue is full. Can't enqueue %d!\n", item);
        return;
    }
    queue->array[queue->rear] = item;
    queue->rear = (queue->rear + 1) % queue->size;
}

int dequeue(CircularQueue *queue){
    if (isEmpty(queue)) {
        printf("Queue is empty!. Can't dequeue!\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->size;
    return item;
}

int front(CircularQueue *queue){
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(CircularQueue *queue){
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->array[(queue->rear - 1 + queue->size) % queue->size];
}

void displayQueue(CircularQueue *queue){
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    for(int i=queue->front; i!=queue->rear; i=(i+1)%queue->size){
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

void freeQueue(CircularQueue *queue){
    free(queue->array);
    free(queue);
}

int main(){
    int x;
    printf("Enter the max. size of the queue: ");
    scanf("%d", &x);
    CircularQueue *queue = createQueue(x);

    int t=1, o, temp;
    do{
        printf("Choose an operation to perform - 1. Enqueue     2. Dequeue     3. Front     4. Rear     5. Print     6. Exit\nEnter your choice : ");
        scanf("%d", &o);
        switch(o){
            case 1:
                printf("Enter the value to be enqueued : ");
                scanf("%d", &temp);
                enqueue(queue, temp);
                break;
            
            case 2:
                temp = dequeue(queue);
                if(temp!=-1){
                    printf("Dequeued element : %d\n", temp);
                }
                break;

            case 3:
                temp = front(queue);
                if(temp!=-1){
                    printf("Front element : %d\n", temp);
                }
                break;

            case 4:
                temp = rear(queue);
                if(temp!=-1){
                    printf("Rear element : %d\n", temp);
                }
                break;

            case 5:
                printf("Circular Queue : ");
                displayQueue(queue);
                break;
            
            case 6:
                printf("Exiting...");
                t=0;
                break;

            default:
                printf("Enter a valid input!");
        }
    }
    while(t);
    freeQueue(queue);
    return 0;
}