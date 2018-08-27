#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// kormentes grafra mukodik, van benne negatic el is
// legrovidebb ut problemaja
// legrovidebb utat is kiir

#define WHITE 0
#define GREY 1
#define BLACK 2
#define True 1
#define False 0

typedef struct Node{
    int degree;
    int* neight;
    int color;
    float distance;
    int parent;
}Node;

void nodeOut(Node* t, int numberOfNode) {
    int i, j;
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d: ", i);
        for(j = 0; j < t[i].degree; ++j) {
            printf("%d ", t[i].neight[j]);
        }
        printf("\n");
    }
}

void weightOut(double** t, int numberOfNode) {
    int i, j;
    for(i = 1; i <= numberOfNode; ++i) {
        for(j = 1; j <= numberOfNode; ++j) {
            printf("%3.1lf ", t[i][j]);
        }
        printf("\n");
    }
}

void parentOut(Node* t, int numberOfNode) {
    int i;
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d %d\n", i, t[i].parent);
    }
}

void distanceOut(Node* t, int numberOfNode) {
    int i;
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d %.1f\n", i, t[i].distance);
    }
}

int isEmpty(Node* t, int numberOfNode) {
    int i, counter = 0;
    for(i = 1; i <= numberOfNode; ++i) {
        if(t[i].color == BLACK) {
            ++counter;
        }
    }
    if(numberOfNode == counter)
        return True;
    return False;
}

int out(Node* t, int numberOfNode) {
    int i, min = INT_MAX, minNode = 0;
    for(i = 1; i <= numberOfNode; ++i) {
        if(t[i].distance < min && t[i].color == WHITE){
            min = t[i].distance;
            minNode = i;
        }
    }
    t[minNode].color = BLACK;
    return minNode;
}

void Dijkstra(Node* t, double** weight, int numberOfNode, int startNode) {
    t[startNode].distance = 0.0;
    int actualNode, i, neight;
    while(!isEmpty(t, numberOfNode)) {
        actualNode = out(t, numberOfNode);
        if(actualNode != 0) {
            for(i = 0; i < t[actualNode].degree; ++i) {
                neight = t[actualNode].neight[i];
                if(t[neight].color == WHITE && (t[actualNode].distance + weight[actualNode][neight] < t[neight].distance)) {
                    t[neight].parent = actualNode;
                    t[neight].distance = t[actualNode].distance + weight[actualNode][neight];
                }
            }
        }
    }
}

void printRoute(Node* t, int actualNode) {
    if(t[actualNode].parent) {
        printRoute(t, t[actualNode].parent);
    }
    printf("%d ", actualNode);
}

void printRouteMain(Node* t, int numberOfNode) {
    int i;
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d %.1f: ", i, t[i].distance);
        if(t[i].parent) {
            printRoute(t, t[i].parent);
        }
        printf("\n");
    }
}

int main() {
    FILE* f;
    if( !(f = fopen("in.txt", "r")) ) {
        printf("The file doesn't exist.\n");
        return 1;
    }
    int i, numberOfNode, numberOfEdge;
    fscanf(f, "%d", &numberOfNode);
    fscanf(f, "%d", &numberOfEdge);
    Node* t;
    if( !(t = (Node*)malloc((numberOfNode + 1) * sizeof(Node))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= numberOfNode; ++i) {
        t[i].neight = (int*)malloc(numberOfNode);
        t[i].color = WHITE;
        t[i].degree = 0;
        t[i].distance = INT_MAX;
        t[i].parent = 0;
    }
    double** weight;
    if( !(weight = (double**)malloc((numberOfNode+1) * sizeof(double*))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 0; i <= numberOfNode; ++i) {
        if( !(weight[i] = (double*)malloc((numberOfNode+1) * sizeof(double))) ) {
            printf("Allocation failed.\n");
            return 1;
        }
    }
    int node1, node2;
    for(i = 1; i <= numberOfEdge; ++i) {
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neight[ t[node1].degree++ ] = node2;
        fscanf(f, "%lf", &weight[node1][node2]);
    }
    close(f);
    // weightOut(weight, numberOfNode);
    Dijkstra(t, weight, numberOfNode, 1);
    // distanceOut(t, numberOfNode);
    printRouteMain(t, numberOfNode);

    for(i = 0; i < numberOfNode; ++i) {
        free(weight[i]);
    }
    free(weight);
    free(t);
    return 0;
}
