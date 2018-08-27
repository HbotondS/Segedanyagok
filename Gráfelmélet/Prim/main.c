#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// megkeresi a legkisebb sulyozott fat

#define INFINITY INT_MAX
#define WHITE 0
#define BLACK 1

typedef struct Node {
    int* neight;
    int degree;
    int parent;
    double weight;
    int color;
}Node;

int getMinNode(Node* t, int numberOfNode) {
    int i, neight, minWeight = INFINITY, minNode = 0;
    for(i = 1; i <= numberOfNode; ++i) {
        if(t[i].weight < minWeight && t[i].color == WHITE) {
            minWeight = t[i].weight;
            minNode = i;
        }
    }
    return minNode;
}

void NodeOut(Node* array, int numberOfNode) {
    int i, j;
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d: ", i);
        for(j = 0; j < array[i].degree; ++j) {
            printf("%d ", array[i].neight[j]);
        }
        printf("\n");
    }
}

void printdist(Node* t, int numberOfNode) {
    int i;
    // printf("\n");
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d %d: %.1lf\n", t[i].parent, i, t[i].weight);
    }
}

void printParent(Node* t, double** weight, int numberOfNode) {
    int i;
    for(i = 1; i <= numberOfNode; ++i) {
        printf("%d %d %.2f\n", i, t[i].parent, weight[i][t[i].parent]);
    }
}

void Prim(Node* nodes, double** weight, int numberOfNode) {
    nodes[1].parent = 0;
    nodes[1].weight = 0;
    int node_left = numberOfNode, i, neight, actualNode;
    while(node_left) {
        actualNode = getMinNode(nodes, numberOfNode);
        // printf("\n%d\n", actualNode);
        // printdist(nodes, numberOfNode); hogy lassam a valtozast part1
        --node_left;
        for(i = 0; i < nodes[actualNode].degree; ++i) {
            neight = nodes[actualNode].neight[i];
            if(weight[actualNode][neight] < nodes[neight].weight) {
                nodes[neight].weight = weight[actualNode][neight];
                nodes[neight].parent = actualNode;
            }
        }
        nodes[actualNode].weight = 0;
        // printf("|\n\\/\n");
        // printdist(nodes, numberOfNode); hogy lassam a valtozast part2
        nodes[actualNode].color = BLACK;
    }
}

double getTotalWeight(Node* t, int numberOfNode, double** weight) {
    double totalWeight;
    int i;
    for(i = 1; i <= numberOfNode; ++i) {
        totalWeight += weight[t[i].parent][i];
    }
    return totalWeight;
}

int main() {
    FILE* in;
    if( !(in = fopen("prim.txt", "r")) ) {
        printf("The file doesn't exist.\n");
        return 1;
    }
    int numberOfNode, numberOfEdge, i, j, node1, node2;
    fscanf(in, "%d%d", &numberOfNode, &numberOfEdge);
    Node* array;
    if( !(array = (Node*)malloc((numberOfEdge+1) * sizeof(Node))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= numberOfNode; ++i) {
        array[i].neight = (int*)malloc((numberOfNode+1) * sizeof(int));
        array[i].degree = 0;
        array[i].weight = INFINITY-1;
        array[i].color = WHITE;
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
    for(i = 0; i < numberOfEdge; ++i) {
        fscanf(in, "%d%d", &node1, &node2);
        array[node1].neight[ array[node1].degree++ ] = node2;
        array[node2].neight[ array[node2].degree++ ] = node1;
        fscanf(in, "%lf", &weight[node1][node2]);
        weight[node2][node1] = weight[node1][node2];
    }
    close(in);

    // NodeOut(array, numberOfNode);
    // printWeight(weight, numberOfNode);
    Prim(array, weight, numberOfNode);
    printParent(array, weight, numberOfNode);
    printf("Total wight: %.1lf\n", getTotalWeight(array, numberOfNode, weight));

    for(i = 0; i < numberOfNode; ++i) {
        free(weight[i]);
    }
    free(weight);
    free(array);
    return 0;
}
