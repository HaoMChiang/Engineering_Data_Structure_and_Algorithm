//
//  main.c
//  EECS114_Lab9
//
//  Created by Hao-Ming Chiang on 3/3/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 12
void DFS(void);
void DFS_visit(int index);
int vertexCount = 0;
int adjMatrix[MAX][MAX];
struct Vertex* lstVertices[MAX];

struct Vertex {
    char label;
    bool visited;
};

void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    vertex -> label = label;
    vertex -> visited = false;
    lstVertices[vertexCount++] = vertex;
}

void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
    printf("%c ", lstVertices[vertexIndex] -> label);
}

int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for(i = 0; i < vertexCount; i++) {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i] -> visited == false) {
            return i;
        }
    }
    return -1;
}

void printAllEdge() {
    printf("All Connections in Graph:\n   ");
    for(int i = 0; i < vertexCount; i++) {
        displayVertex(i);
        printf(" ");
    }
    printf("\n");
    for(int i = 0; i < vertexCount; i++) {
        for(int j = 0; j < vertexCount; j++) {
            if(j == 0) {
                displayVertex(i);
                printf(" ");
            }
            printf("%d  ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void DFS() {
    printf("Depth First Search:\n");
    if(vertexCount == 0) {
        printf("Graph is Empty. \n");
        return;
    }
    for(int i = 0; i < vertexCount; i++) {
        if(lstVertices[i] -> visited == false) {
            DFS_visit(i);
        }
    }
    printf("\n\n");
}

void DFS_visit(int index) {
    printf("%c ", lstVertices[index] -> label);
    lstVertices[index] -> visited = true;
    for(int i = 0; i < MAX; i++) {
        int neighbor = getAdjUnvisitedVertex(index);
        if(neighbor != -1) {
            DFS_visit(neighbor);
        }
    }
}

void makeRandomGraph() {
    printf("Creating a Random Graph with 12 Nodes and 19 Edges...\n\n");
    time_t t;
    srand((unsigned)time(&t));
    for(int i = 0; i < MAX; i++) {
        addVertex('a' + rand() % 26);
    }
    for(int i = 0; i < 20; i++) {
        addEdge(rand() % MAX, rand() % MAX);
    }
    printf("Finished Creating a Graph\n\n");
}

int main(int argc, const char * argv[]) {
//    addVertex('a');
//    addVertex('b');
//    addVertex('c');
//    addVertex('d');
//    addVertex('e');
//
//    addEdge(0,1);
//    addEdge(0,3);
//    addEdge(1,0);
//    addEdge(1,2);
//    addEdge(1,3);
//    addEdge(2,1);
//    addEdge(2,4);
//    addEdge(3,1);
//    addEdge(3,0);
//    addEdge(4,0);
//    addEdge(4,2);
//    printAllEdge();
//    DFS();
    
    makeRandomGraph();
    printAllEdge();
    DFS();
    
    return 0;
}
