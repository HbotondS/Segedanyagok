#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
///kormentes grafra mukodik, amiben nincs negativ el!!!
///legrovidebbb ut problemaja
///ki is kell iratni a legrovidebb utakat

#define WHITE 0
#define GREY 1
#define BLACK 2

typedef struct Node{
    int degree;
    int* neight;
    int color;
    float distance;
    int parent;
}Node;

typedef struct TOPO{
    int* t;
    int degree;
}TOPO;

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
            if((int)ceil(t[i][j]) > 0)
                printf("%d %d: %.1lf\n", i, j, t[i][j]);
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

void printTopo(TOPO* topo, int numberOfNode) {
    int i;
    for(i = 0; i < topo[0].degree; ++i) {
        printf("%d ", topo[0].t[i]);
    }
    printf("\n");
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

void depth(Node* t, double** weight, int actualNode, TOPO* topo) {
    t[actualNode].color = GREY;
    topo[0].t[topo[0].degree++] = actualNode;
    int i, neight;
    for(i = 0; i < t[actualNode].degree; ++i) {
        neight = t[actualNode].neight[i];
        if((t[actualNode].distance + weight[actualNode][neight]) < t[neight].distance) {
            ///printf("%0.1f < %f.1\n", (t[actualNode].distance + weight[actualNode][neight]), t[neight].distance);
            t[neight].distance = t[actualNode].distance + weight[actualNode][neight];
            t[neight].parent = actualNode;
        }
    }
    for(i = 0; i < t[actualNode].degree; ++i) {
        neight = t[actualNode].neight[i];
        if(t[neight].color == WHITE) {
            depth(t, weight, neight, topo);
        }
    }
    t[actualNode].color = BLACK;
}

void DFS(Node* t, double** weight, int numberOfNode, TOPO* topo) {
    int i;
    for(i = 1; i <= numberOfNode; ++i) {
        if(t[i].color == WHITE) {
            t[i].distance = 0;
            depth(t, weight, i, topo);
        }
    }
}

int main()
{
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
    TOPO* topo;
    topo = (TOPO*)malloc(1*sizeof(TOPO));
    if( !(topo->t = (int*)malloc((numberOfNode) * sizeof(int))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    topo->degree = 0;
    ///nodeOut(t, numberOfNode);
    ///weightOut(weight, numberOfNode);
    DFS(t, weight, numberOfNode, topo);
    ///printTopo(topo, numberOfNode);
    ///distanceOut(t, numberOfNode);
    printRouteMain(t, numberOfNode);
    ///parentOut(t, numberOfNode);

    for(i = 0; i < numberOfNode; ++i) {
        free(weight[i]);
    }
    free(weight);
    free(t);
    return 0;
}
