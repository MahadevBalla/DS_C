#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX 100

int time = 1;
typedef struct node{
    int vertex;
    struct node *next;
}Node;

typedef struct graph{
    Node * adjListStart[MAX];
    Node * adjListEnd[MAX];
    int numVertices;
}Graph;

typedef struct stack{
    int top;
    int stackArray[MAX];
}Stack;

typedef struct q{
    int front;
    int rear;
    int queueArray[MAX];
}Queue;

int push(Stack*s,int data){
    if(s->top==MAX-1){
        return -1;
    }
    s->top++;
    s->stackArray[s->top]=data;
    return 1;
}

int pop(Stack *s){
    int x;
    if(s->top==-1){
        return -1;
    }
    x = s->stackArray[s->top];
    s->top--;
    return x;
}

int stackTop(Stack *s)
{
    if(s->top!=-1)
        return s->stackArray[s->top];
}

int isEmptyStack(Stack *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

int isEmptyQueue(Queue *q)
{
    if(q->front==-1)
        return 1;
    return 0;
}
int enque(Queue *q,int data)
{
    if(q->rear==MAX-1){
        printf("Queue Is Full\n");
        return -1;
    }
    if(q->front==-1){
        q->front=q->rear=0;
    }else{
        q->rear++;
    }
    q->queueArray[q->rear]=data;

    return 1;
}
int deque(Queue *q)
{
    int node;
    if(q->front==-1){
        printf("Queue Is Empty\n");
        return -1;
    }
    node  = q->queueArray[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }else{
        q->front++;
    }
    return node;
}

int searchQueue(Queue *q,int key)
{
    int start = q->front;
    int end = q->rear;
    int i;
    for(i=start;i<=end;i++)
    {
        if(q->queueArray[i]==key)
            return 1;
    }
    return 0;
}
Node * createNode(int key)
{
    Node * newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex=key;
    newNode->next=NULL;
    return newNode;
}
Graph *createGraph(int v)
{
    int i;
    Graph * g = (Graph*)malloc(sizeof(Graph));
    g->numVertices=v;
    for(i=0;i<v;i++)
    {
        g->adjListStart[i]=NULL;
        g->adjListEnd[i]=NULL;

    }
    return g;
}
void joinEdge(Graph *g,int src,int dest)
{
    //src to dest
    Node * node = createNode(dest);
    Node * node2 = createNode(src);
    
    if(g->adjListStart[src]==NULL)
    {
        g->adjListStart[src]=g->adjListEnd[src]=node;
    }else{

        g->adjListEnd[src]->next=node;
        g->adjListEnd[src] = node;
    }

    //dest to src
    if(g->adjListStart[dest]==NULL)
    {
        g->adjListStart[dest]=g->adjListEnd[dest]=node2;
    }else{
        g->adjListEnd[dest]->next=node2;
        g->adjListEnd[dest] = node2;

    }

}
void printAdjencencyMatrix(Graph *g)
{
    int i,j,n = g->numVertices;
    int matrix[n][n];
    Node*temp=NULL;
    for(i=0;i<n;i++)
    {
        temp = g->adjListStart[i];
        while(temp!=NULL)
        { 
            matrix[i][temp->vertex]=1;
            temp=temp->next;
        }
    }
    printf("The Adjencecy Matrix For The Graph Is As Follows : \n");
    for(i=0;i<n;i++)
    {
        
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]!=1)
                matrix[i][j]=0;
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void BFS(Graph *g,int startNode)
{
    int n = g->numVertices;
    int i,k=0,x,visited[n],bfs[n];
    Queue *q = (Queue*)malloc(sizeof(Queue));
    Node *temp;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    q->front=q->rear=-1;

    //1st node
    enque(q,startNode);
    visited[startNode]=1;
    bfs[k++]=startNode;

    while(!isEmptyQueue(q))
    {
        x = deque(q);
        temp = g->adjListStart[x];
        while(temp!=NULL)
        {
            if(visited[temp->vertex]!=1 && searchQueue(q,temp->vertex)==0)
            {
                enque(q,temp->vertex);
                visited[temp->vertex]=1;
                bfs[k++]=temp->vertex;
            }
            temp=temp->next;
        }

    }
    printf("BFS Traversal : ");
    for(i=0;i<k;i++)
    {
        printf("%d ",bfs[i]);
    }
    printf("\n");
}

void DFS(Graph *g,int startNode)
{
    int n = g->numVertices;
    int visited[n],dfs[n],startTime[n],endTime[n];
    int i,x,k=0;
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top=-1;
    Node *temp;
    if(g->adjListStart[startNode]==NULL)
    {
        printf("No Node Is Connected To %d",startNode);
        return;
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    //1st node
    push(s,startNode);
    visited[startNode]=1;
    dfs[k++]=startNode;
    startTime[startNode]=time;
    time++;

    while(!isEmptyStack(s))
    {
        x = stackTop(s);
        int hasUnvisited =0;
        temp = g->adjListStart[x];
        while(temp!=NULL)
        {
            int vertex = temp->vertex;
            if(!visited[vertex])
            {
                push(s,vertex);
                startTime[vertex]=time;
                visited[vertex]=1;
                time++;
                hasUnvisited=1;
                dfs[k++]=vertex;
                break;
            }
            temp=temp->next;
        }

        if(!hasUnvisited)
        {
            x = pop(s);
            endTime[x]=time;
            time++;
        }
    }
    printf("DFS Traversal : \n");
    for ( i = 0; i < k; i++)
    {
        printf("Node = %d ST = %d ET = %d\n",dfs[i],startTime[i],endTime[i]);
        
    }
    
    printf("\n");

}

void DFS_Recursion(Graph*g,int k,int *visited)
{
    int j;
    visited[k]=1;
    printf("%d ",k);
    Node *temp = g->adjListStart[k];
    while(temp)
    {
        j=temp->vertex;
        if(visited[j]==0)
            DFS_Recursion(g,j,visited);
        temp=temp->next;
    }
}
int main()
{
    int i,src,dest,numVertices,edges,start;
    Graph *g;
    printf("Enter Number Of Vertices In Graph : ");
    scanf("%d",&numVertices);
    printf("Enter Number Of Edges In Graph : ");
    scanf("%d",&edges);
    g = createGraph(numVertices);
    for(i=0;i<edges;i++)
    {
        do
        {
            printf("For Edge %d :\n",i+1);
            printf("Enter Source And Destination (0 to %d): ",numVertices-1);
            scanf("%d %d",&src,&dest);
            if(src<0 || src>numVertices || dest<0 || dest>numVertices)
            {
                printf("Invalid Edge ! Try Againn\n");
            }
        } while (src<0 || src>numVertices || dest<0 || dest>numVertices);
        joinEdge(g,src,dest);
    }
    
    printAdjencencyMatrix(g);
    do
    {
        printf("Enter The Starting Node For BFS Traversal : ");
        scanf("%d",&start);
        if(start!=-1)
            BFS(g,start);
    } while (start!=-1);
    do
    {
        printf("Enter The Starting Node For DFS Traversal : ");
        scanf("%d",&start);
        if(start!=-1)
        {
            int *a = (int*)malloc(sizeof(int)*numVertices);
            DFS(g,start);
            for(i=0;i<numVertices;i++)
                a[i]=0;
            printf("DFS Using Recusrsion :\n");
            DFS_Recursion(g,start,a);
        }
            
            
    } while (start!=-1);
    
    
    return 0;
}
