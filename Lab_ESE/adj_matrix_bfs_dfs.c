#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 100

int time = 1;
typedef struct node
{
    int vertex;
    struct node *next;
} Node;

typedef struct graph
{
    int matrix[MAX][MAX];
    int numVertices;
} Graph;

typedef struct stack
{
    int top;
    int stackArray[MAX];
} Stack;

typedef struct q
{
    int front;
    int rear;
    int queueArray[MAX];
} Queue;

int push(Stack *s, int data)
{
    if (s->top == MAX - 1)
    {
        return -1;
    }
    s->top++;
    s->stackArray[s->top] = data;
    return 1;
}

int pop(Stack *s)
{
    int x;
    if (s->top == -1)
    {
        return -1;
    }
    x = s->stackArray[s->top];
    s->top--;
    return x;
}

int stackTop(Stack *s)
{
    if (s->top != -1)
        return s->stackArray[s->top];
}

int isEmptyStack(Stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int isEmptyQueue(Queue *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}
int enque(Queue *q, int data)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue Is Full\n");
        return -1;
    }
    if (q->front == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->queueArray[q->rear] = data;

    return 1;
}
int deque(Queue *q)
{
    int node;
    if (q->front == -1)
    {
        printf("Queue Is Empty\n");
        return -1;
    }
    node = q->queueArray[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return node;
}

int searchQueue(Queue *q, int key)
{
    int start = q->front;
    int end = q->rear;
    int i;
    for (i = start; i <= end; i++)
    {
        if (q->queueArray[i] == key)
            return 1;
    }
    return 0;
}
Node *createNode(int key)
{
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = key;
    newNode->next = NULL;
    return newNode;
}
Graph *createGraph(int v)
{
    int i;
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = v;
    for (i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            g->matrix[i][j] = 0;
    return g;
}

void printAdjencencyMatrix(Graph *g)
{
    int i, j;
    printf("The Adjencecy Matrix For The Graph Is As Follows : \n");
    for (i = 0; i < g->numVertices; i++)
    {

        for (j = 0; j < g->numVertices; j++)
        {
            if (g->matrix[i][j] != 1)
                g->matrix[i][j] = 0;
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

void BFS(Graph *g, int startNode)
{
    int n = g->numVertices;
    int visited[n], bfs[n], k = 0;
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    enque(q, startNode);
    bfs[k++] = startNode;
    visited[startNode]=1;
    while (!isEmptyQueue(q))
    {
        int x = deque(q);
        for (i = 0; i < n; i++)
        {
            if (g->matrix[x][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enque(q, i);
                bfs[k++] = i;
            }
        }
    }
    printf("BFS : ");
    for (i = 0; i < n; i++)
        printf("%d ", bfs[i]);
    printf("\n");
}

void DFS(Graph *g, int startNode)
{
    int time = 1;
    int n = g->numVertices;
    int visited[n], dfs[n], startTime[n], endTime[n], k = 0, i, j, x;

    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    for(i=0;i<n;i++)
        visited[i]=0;
    // 1st node
    push(s, startNode);
    dfs[k++] = startNode;
    startTime[startNode] = time++;
    visited[startNode] = 1;

    while (!isEmptyStack(s))
    {
        x = stackTop(s);
        int hasUnvisited = 0;
        for (i = 0; i < n; i++)
        {
            if (g->matrix[x][i] == 1 && !visited[i])
            {
                hasUnvisited = 1;
                visited[i] = 1;
                dfs[k++] = i;
                startTime[i] = time++;
                push(s, i);
                break;
            }
        }
        if (!hasUnvisited)
        {
            int popped = pop(s);
            endTime[popped] = time++;
        }
    }
    printf("DFS Traversal :\n ");
    for (i = 0; i < n; i++)
        printf("%d ",dfs[i]);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Node = %d : St = %d  Et = %d\n", i, startTime[i], endTime[i]);

    }
}
int main()
{
    int i, j, numVertices, edges, start, src, dest;
    printf("Enter Number Of Vertices In Graph : ");
    scanf("%d", &numVertices);
    printf("Enter Number Of Edges In Graph : ");
    scanf("%d", &edges);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g = createGraph(numVertices);
    for (i = 0; i < edges; i++)
    {
        printf("For Edge %d :\n", i + 1);
        printf("Enter Src and Dest : ");
        scanf("%d %d", &src, &dest);
        g->matrix[src][dest] = g->matrix[dest][src] = 1;
    }
    printAdjencencyMatrix(g);
    do
    {
        printf("Enter The Starting Node For BFS Traversal : ");
        scanf("%d", &start);
        if (start != -1)
            BFS(g, start);
    } while (start != -1);
    do
    {
        printf("Enter The Starting Node For DFS Traversal : ");
        scanf("%d", &start);
        if (start != -1)
            DFS(g, start);
    } while (start != -1);

    return 0;
}
