#include <stdio.h>
#include <stdlib.h>
// megkeresi a legkisebb sulyozott fat

typedef struct Node {
    int parent, child;
    float weight;
}Node;

void NodeOut(Node* array, int numberOfEdge) {
    int i;
    for(i = 0; i < numberOfEdge; ++i) {
        printf("%d %d %.2f\n", array[i].parent, array[i].child, array[i].weight);
    }
}

int int_cmp(const void* a, const void* b) {
    if( ((Node*)a)->weight > ((Node*)b)->weight )
        return 1;
    else if( ((Node*)a)->weight < ((Node*)b)->weight )
            return -1;
    else
        return 0;
}

void add(int* t, int numberOfNode, int node1, int node2) {
    int i;
    for(i = 0; i < numberOfNode; ++i) {
        if(t[i] == node2) {
            t[i] = node1;
        }
    }
}

void Kruskal(Node* t, int numberOfEdge, int numberOfNode) {

    qsort( t, numberOfEdge, sizeof(Node), int_cmp );
    // printf("After sort.\n");
    // NodeOut(t, numberOfEdge);

    int* tree;
    int i;
    if( !(tree = (int*)malloc((numberOfNode+2) * sizeof(int))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= numberOfNode; ++i) { // melyik csomopont melyik
        tree[i] = i;                    // kezdetben minden csomopont sajatmagaval alkot egy fat
    }                                  // ezutan tesszuk be az eleket, ugy hogy ne legyen kor
    int totalWeight = 0;
    for(i = 0; i < numberOfEdge; ++i) {
        int node1 = tree[ t[i].parent ];
        int node2 = tree[ t[i].child ];
        if(node1 != node2) {
            totalWeight += t[i].weight;
            printf("%d %d %.2f\n", t[i].parent, t[i].child, t[i].weight);
            add(tree, numberOfNode, node1, node2);
        }
    }
    printf("Total weight: %d\n", totalWeight);

    free(tree);
}

int main() {
    FILE* in;
    if( !(in = fopen("kruskal.txt", "r")) ) {
        printf("The file doesn't exist.\n");
        return 1;
    }
    int numberOfNode, numberOfEdge;
    fscanf(in, "%d%d", &numberOfNode, &numberOfEdge);
    Node* array;
    if( !(array = (Node*)malloc((numberOfEdge+1) * sizeof(Node))) ) {
        printf("Allocation failed.\n");
        return 1;
    }

    int i;
    for(i = 0; i < numberOfEdge; ++i) {
        fscanf(in, "%d%d%f", &array[i].parent, &array[i].child, &array[i].weight);
    }
    close(in);

    // NodeOut(array, numberOfEdge);

    Kruskal(array, numberOfEdge, numberOfNode);

    free(array);
    return 0;
}
