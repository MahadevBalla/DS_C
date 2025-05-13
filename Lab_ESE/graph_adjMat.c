#include <stdio.h>
#include <stdlib.h>

void initAdjL(int **adjL, int v){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            adjL[i][j] = 0;
        }
    }
}

void addEdge(int **adjL, int s, int t){
    adjL[s][t] = 1;
}

void _DFS_(int **adjL, int *visited, int v, int start){
    printf("%d  ", start);
    visited[start] = 1;

    for(int i=0; i<v; i++){
        if(adjL[start][i]==1 && visited[i]==0){
            _DFS_(adjL, visited, v, i);
        }
    }
}

void DFS(int **adjL, int *visited, int v){
        for(int i=0; i<v; i++){
            if(visited[i]==0){
                _DFS_(adjL, visited, v, i);
            }
        }
}

void _BFS_(int **adjL, int *visited, int v, int start){
    int queue[v], front = 0, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while(!(rear<front)){
        int curr = queue[front++];
        printf("%d  ", curr);

        for(int i=0; i<v; i++){
            if(adjL[curr][i]==1 && visited[i]==0){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void BFS(int **adjL, int *visited, int v){
        for(int i=0; i<v; i++){
            if(visited[i]==0){
                _BFS_(adjL, visited, v, i);
            }
        }
}

void printAdjL(int **adjL, int v){
    for(int i=0; i<v; i++){
        printf("Vertex %d : ", i);
        for(int j=0; j<v; j++){
            printf("%d  ", adjL[i][j]);
        }
        printf("\n");
    }
}

void freeAdjL(int **adjL, int v){
    for (int i=0; i<v; i++) {
        free(adjL[i]);
    }
    free(adjL);
}

int main(){
    int v=0, e=0, s, t;
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    
    int **adjL = (int **)malloc(v * sizeof(int *));
    for(int i=0; i<v; i++){
        adjL[i] = (int *)malloc(v * sizeof(int));
    }
    initAdjL(adjL, v);

    int *visited = (int *)malloc(v * sizeof(int));

    printf("Enter the number of edges : ");
    scanf("%d", &e);

    printf("Enter the edges as pairs of vertices (source target) - \n");
    for(int i=0; i<e; i++){
        printf("Edge %d : ", i+1);
        scanf("%d %d", &s, &t);
        addEdge(adjL, s, t);
    }
    
    printf("\nAdjacency Matrix :\n");
    printAdjL(adjL, v);
    printf("\n");

    for(int i=0; i<v; i++){
        visited[i] = 0;
    }
    printf("DFS Traversal : ");
    DFS(adjL, visited, v);
    printf("\n");

    for(int i=0; i<v; i++){
        visited[i] = 0;
    }
    printf("BFS Traversal : ");
    BFS(adjL, visited, v);
    printf("\n");

    freeAdjL(adjL, v);
    free(visited);
    return 0;
}