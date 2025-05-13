#include <stdio.h>
#include <stdlib.h>

typedef struct Nod{
    int val;
    struct Node* next;
}Node;

 Node* createNode(int val){
    Node* new = (Node *)malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    return new;
}

typedef struct Grap{
    int v;
    Node** adjL;
}Graph;

Graph *createGraph(int v){
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->v = v;
    g->adjL = malloc(v * sizeof(struct Node*));
    for(int i=0; i<v; i++){
        g->adjL[i] = NULL;
    }
    return g;
}

void addEdge(Graph *g, int s, int t){
    Node *new = createNode(t);
    new->next = g->adjL[s];
    g->adjL[s] = new;
}

void printGraph(Graph* g){
    for (int i = 0; i < g->v; i++){
        Node* temp = g->adjL[i];
        printf("Vertex %d -> ", i);
        while(temp){
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFS(Graph* g, int v, int visited[]){
    printf("%d", v);
    visited[v] = 1;

    Node *queue[sizeof(visited)/sizeof(int)]; 
    int front = 0, rear = -1;
    
        //incomplete
}

void DFS(Graph* g, int v, int visited[]){
    printf("%d  ", v);
    visited[v] = 1;

    Node* temp = g->adjL[v];
    while(temp!=NULL){
        if(!visited[temp->val]){
            DFS(g, temp->val, visited);
        }
        temp = temp->next;
    }
}

int main(){
    int v=0, e=0, s=0, t=0;

    printf("Enter the number of vertices : ");
    scanf("%d", &v);

    Graph* graph = createGraph(v);

    printf("Enter the number of edges : ");
    scanf("%d", &e);

    for(int i=0; i<e; i++){
        printf("Enter edge %d vertices : ", (i+1));
        scanf("%d %d", &s, &t);
        addEdge(graph, s, t);
    }
    printf("Adjacency List -\n");
    printGraph(graph);

    int visited[v];
    for(int i=0; i<v; i++){
        visited[i] = 0;
    }
    printf("\nDFS Traversal : ");
    DFS(graph, 0, visited);

    free(graph->adjL);
    free(graph);
    return 0;
}