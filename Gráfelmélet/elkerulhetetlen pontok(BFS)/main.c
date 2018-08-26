#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int degreeIn;
    int degreeOut;
    int* neightIn; ///a csomopont szomszedjai
    int* neightOut;
    int color; ///0 = feher(meg nem jartunk ott); 1 = szurke(most vagyunk ott)\
                    2 = fekete(mar jartunk ott)
    ///int distance;
}Node;

void nodeOut(Node* t, int n){
    int i, j;
    for(i = 1; i <= n; ++i){
        printf("%d: In: ", i);
        for(j = 0; j < t[i].degreeIn; ++j){
            printf("%d ", t[i].neightIn[j]);
        }
        printf("Befokszam: %d", t[i].degreeIn);
        printf("\n  Out: ");
        for(j = 0; j < t[i].degreeOut; ++j){
            printf("%d ", t[i].neightOut[j]);
        }
        printf("Kifokszam: %d", t[i].degreeOut);
        printf("\n");
    }
}

int main()
{
    FILE* f;
    if(!(f = fopen("pont.txt", "r"))){
        printf("The file doesn't exist.\n");
        return 1;
    }
    int i, j, n, m; /// n - csomopontok szama; m - elek szama

    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    Node* t;
    if(!(t = (Node*)malloc((n + 1) * sizeof(Node)))){
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= n; ++i){
        t[i].neightIn = (int*)malloc(n);
        t[i].neightOut = (int*)malloc(n);
        t[i].color = 0; ///feher
        t[i].degreeIn = 0;
        t[i].degreeOut = 0;
    }
    int node1, node2;
    for(i = 1; i <= m; ++i){
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neightOut[t[node1].degreeOut++] = node2;
        t[node2].neightIn[t[node2].degreeIn++] = node1;
    }
    for(i = 1; i <= n; ++i){
        if(!(t[i].neightIn = realloc(t[i].neightIn, (t[i].degreeIn + 1) * sizeof(int)))){
            printf("Reallocation failed.\n");
            return 1;
        }
        if(!(t[i].neightOut = realloc(t[i].neightOut, (t[i].degreeOut + 1) * sizeof(int)))){
            printf("Reallocation failed.\n");
            return 1;
        }
    }
    nodeOut(t, n);

    int* fifo = (int*)calloc(n+1, sizeof(int));
    int first = 0, last = 1, lastNode, firstNode, startNode = 1, endNode = 10;
    fifo[first] = startNode;
    t[fifo[first]].color = 1;
    while(first < last) {
        firstNode = fifo[first];
        if(last - 1 == first){
            printf("%d ", firstNode);
        }
        for(i = 0; i < t[firstNode].degreeOut; ++i) {
            lastNode = t[firstNode].neightOut[i];
            if(t[lastNode].color == 0) {
                fifo[last++] = lastNode;
                t[lastNode].color = 1;
            }
        }
        t[firstNode].color = 2;
        ++first;
    }

    for(i = 0; i <= n; ++i) {
        free(t[i].neightOut);
        free(t[i].neightIn);
    }
    free(t);
    close(f);
    return 0;
}
