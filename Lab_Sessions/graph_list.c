#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

 Node* createNode(int val){
    Node* new = ( Node*)malloc(sizeof( Node));
    new->val = val;
    new->next = NULL;
    return new;
}

typedef struct Graph{
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

    new = createNode(s);
    new->next = g->adjL[t];
    g->adjL[t] = new;  
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->v; i++) {
        Node* temp = g->adjL[i];
        printf("Vertex %d : ", i);
        while (temp) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int DFS(Graph* g, int v, int visited[], int parent) {
    visited[v] = 1;
    Node* temp = g->adjL[v];
    while(temp!=NULL){
        if(!visited[temp->val]){
            if(DFS(g, temp->val, visited, v)){
                return 1;
            }
        }
        else if(temp->val!=parent){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int detectCycle(Graph* g){
    int* visited = (int*)malloc(g->v * sizeof(int));
    for(int i=0; i<g->v; i++){
        visited[i] = 0;
    }

    for(int i=0; i<g->v; i++){
        if(!visited[i]){
            if(DFS(g, i, visited, -1)){
                free(visited);
                return 1;
            }
        }
    }
    free(visited);
    return 0;
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
    printf("O/P : ");
    if(detectCycle(graph)){
        printf("1\n");
    }
    else{
        printf("0\n");
    }

    free(graph->adjL);
    free(graph);
    return 0;
}