#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int maxHeap[MAX];
int maxSize = 0;
int minHeap[MAX];
int minSize = 0;

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void maxHeapify(int i){
    int left = 2*i;
    int right = (2*i)+1;
    int s=i;

    if(left<=maxSize && maxHeap[left]>maxHeap[s]){
        s = left;
    }

    if(right<=maxSize && maxHeap[right]>maxHeap[s]){
        s = right;
    }

    if(s!=i){
        swap(&maxHeap[s], &maxHeap[i]);
        maxHeapify(s);
    }
}

void minHeapify(int i){
    int left = 2*i;
    int right = (2*i)+1;
    int s=i;

    if(left<=minSize && minHeap[left]<minHeap[s]){
        s = left;
    }

    if(right<=minSize && minHeap[right]<minHeap[s]){
        s = right;
    }

    if(s!=i){
        swap(&minHeap[s], &minHeap[i]);
        minHeapify(s);
    }
}

void insertMax(int val){
    if(maxSize>=MAX-1){
        printf("Max size reached...can't add\n");
        return;
    }
    maxHeap[++maxSize] = val;
    
    int i = maxSize;
    int parent = i/2;
    while(i>1 && maxHeap[i]>maxHeap[parent]){
        swap(&maxHeap[i], &maxHeap[parent]);
        i = parent;
        parent = i/2;
    }
}

void insertMin(int val){
    if(minSize>=MAX-1){
        printf("Max size reached...can't add\n");
        return;
    }
    minHeap[++minSize] = val;
    
    int i = minSize;
    int parent = i/2;
    while(i>1 && minHeap[i]<minHeap[parent]){
        swap(&minHeap[i], &minHeap[parent]);
        i = parent;
        parent = i/2;
    }
}

int extractMax(){
    if(maxSize==0){
        printf("Heap is empty...can't extract max !\n");
        return -1;
    }
    int max = maxHeap[1];
    maxHeap[1] = maxHeap[maxSize--];
    maxHeapify(1);
    return max;
}

int extractMin(){
    if(minSize==0){
        printf("Heap is empty...can't extract min !\n");
        return -1;
    }
    int min = minHeap[1];
    minHeap[1] = minHeap[minSize--];
    minHeapify(1);
    return min;
}

void maxHeapSort(){
    int temp = maxSize;
    while(maxSize>1){
        swap(&maxHeap[1], &maxHeap[maxSize--]);
        maxHeapify(1);
    }
    maxSize = temp;
}

void minHeapSort(){
    int temp = minSize;
    while(minSize>1){
        swap(&minHeap[1], &minHeap[minSize--]);
        minHeapify(1);
    }
    minSize = temp;
}

void printMaxHeap(){
    for(int i=1; i<=maxSize; i++){
        printf("%d  ", maxHeap[i]);
    }
    printf("\n");
}

void printMinHeap(){
    for(int i=1; i<=minSize; i++){
        printf("%d  ", minHeap[i]);
    }
    printf("\n");
}

int main(){
    int t = 1, o, temp;
    do{
        printf("Choose an operation to perform - 1. Insert     2. Extract     3. Heap Sort     4. Print     5. Exit\nEnter your choice : ");
        scanf("%d", &o);
        switch(o){
            case 1 :
                printf("Enter the value to be inserted : ");
                scanf("%d", &temp);
                insertMax(temp);
                insertMin(temp);
                break;

            case 2 :
                temp = extractMax();
                printf("Extracted max : %d\n", temp);
                temp = extractMin();
                printf("Extracted min : %d\n", temp);
                break;

            case 3 :
                maxHeapSort();
                printf("Max Heap after sorting : ");
                printMaxHeap();
                minHeapSort();
                printf("Min Heap after sorting : ");
                printMinHeap();
                break;

            case 4 :
                printf("Max Heap : ");
                printMaxHeap();
                printf("Min Heap : ");
                printMinHeap();
                break;

            case 5 :
                printf("Exiting...");
                t=0;
                break;
                
            default : 
            printf("Enter a valid input !\n");
        }
    }
    while(t);
    return 0;
}