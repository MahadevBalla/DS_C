#include<stdio.h>
#define MAX 50

//struct for the queue
typedef struct {
    int front;
    int rear;
    int *arr;
    int id;
    int max_size;
} Queue;

//Initalizing struct 
Queue initializeQueue(int *arr, int id, int max_size, int start, int end) {
    Queue q;
    q.front = start;
    q.rear = end;
    q.arr = arr;
    q.id = id;
    q.max_size = max_size;
    return q;
}

//function to check if Queue is empty
int isEmpty(Queue* q) {
    if(q->front == q->rear - 1) return 1;
    return 0;
}

//function to check if Queue is empty
int isFull(Queue* q) {
    if(q->rear==q->max_size) return 1;
    return 0;
}

//function to enqueue in queue
void enqueue(Queue* q, int data) {
    if(isFull(q)) {
        printf("Queue %d has overflowed \n",q->id);
        return;
    }
    q->arr[q->rear++]=data;
}

//function to dequeue in queue 
void dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue %d is empty \n",q->id);
        return;
    }
    q->arr[q->front++]=0;
}

//function to print a queue
void printQueue(Queue* q)
{
    if (isEmpty(q)) {
        printf("Queue %d is empty\n",q->id);
        return;
    }
    printf("Current Queue %d: ", q->id);
    for (int i = q->front + 1; i <=q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

//function to get Queue choice 
int getQueueChoice() {
    int choice;
    printf("Enter which queue: 1:Queue 1 | 2: Queue 2 | 3: Queue 3 | 3: Queue 3 | 4: Queue 4 | 5: Queue 5 \n");
    scanf("%d",&choice);
    if(choice < 1 || choice >5) {
        printf("Please enter a correct queue index \n");
        return getQueueChoice();
    }
    return choice-1;
}

//function to get full array
void getFullArr(int *arr) {
    printf("Full array (0 means empty) \n");
    for(int i=0; i<MAX; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//function of run a menu
void runMenu(Queue *qArr, int *arr) {
    int choiceQ, data;
    int option=-1;
    do {
        printf("Enter a choice -> 1: Enqueue | 2: Dequeue | 3: Display Queue | 4: Display Full | 5: Exit \n");
        scanf("%d",&option);
        if(option==5) return;
        switch(option) {
            case 1: 
                choiceQ = getQueueChoice();
                printf("Enter number to enqueue: ");
                scanf("%d",&data);
                enqueue(&(qArr[choiceQ]),data);
                break;
            case 2: 
                dequeue(&(qArr[getQueueChoice()]));
                break;
            case 3:
                printQueue(&(qArr[getQueueChoice()]));
                break;
            case 4:
                getFullArr(arr);
                break;
            default:
                printf("Enter correct index \n");
        }
    } while(option!=5);
    return;
}

int main() {
    int queueArray[MAX] = {0};
    int qMax = 10;
    
    Queue qArray[] = {
        initializeQueue(queueArray, 1, qMax, -1, 0),
        initializeQueue(queueArray, 2, qMax, 10, 11),
        initializeQueue(queueArray, 3, qMax, 20, 21),
        initializeQueue(queueArray, 4, qMax, 30, 31),
        initializeQueue(queueArray, 5, qMax, 40, 41)
    };
    
    runMenu(qArray, queueArray);
    return 0;
}
