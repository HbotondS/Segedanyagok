// szomszedsagi listaval dolgozunk
// kiirja az utat a kezdo csomoponttol a tobbibe

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int degree;
    int* neight; // a csomopont szomszedjai
    int color; // 0 = feher(meg nem jartunk ott); 1 = szurke(most vagyunk ott)\
                    2 = fekete(mar jartunk ott)
    int distance;
    int parent;
}Node;

void nodeOut(Node* t, int n) {
    int i, j;
    for(i = 1; i <= n; ++i) {
        printf("%d: ", i);
        for(j = 0; j < t[i].degree; ++j) {
            printf("%d ", t[i].neight[j]);
        }
        printf("fokszam: %d\n", t[i].degree);
    }
}

void parents(Node* t, int n) {
    printf("\nParents:\n");
    int i;
    for(i = 1; i <= n; ++i) {
        printf("%d %d\n", i, t[i].parent);
    }
}

void distance(Node* t, int n) {
    printf("\nDistance:\n");
    int i;
    for(i = 1; i <= n; ++i) {
        printf("%d %d\n", i, t[i].distance);
    }
}

void route(Node* t, int node) {
    if(t[node].parent != 0) {
        route(t, t[node].parent);
    }
    printf("%d ", node);
}

int main() {
    FILE* f;
    if(!(f = fopen("BFS.txt", "r"))) {
        printf("The file doesn't exist.\n");
        return 1;
    }
    int i, j, n, m; // n - csomopontok szama; m - elek szama

    fscanf(f, "%d", &n);
    fscanf(f, "%d", &m);
    Node* t;
    if(!(t = (Node*)malloc((n + 1) * sizeof(Node)))) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= n; ++i) {
        t[i].neight = (int*)malloc(n);
        t[i].color = 0; // feher
        t[i].degree = 0;
        t[i].distance = 0;
        t[i].parent = 0;
    }
    int node1, node2;
    for(i = 0; i <= n; ++i) {
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neight[t[node1].degree] = node2;
        t[node1].degree++;
        t[node2].neight[t[node2].degree] = node1;
        t[node2].degree++;
    }
    for(i = 1; i <= n; ++i) {
        if(!(t[i].neight = realloc(t[i].neight, t[i].degree * sizeof(int)))) {
            printf("Reallocation failed.\n");
            return 1;
        }
    }
    nodeOut(t, n);

    int* fifo = (int*)calloc(n+1, sizeof(int));
    int first = 0, last = 1, lastNode, firstNode, startNode = 0;
    printf("\nKezdo csomopont: ");
    scanf("%d", &startNode);
    fifo[first] = startNode; // melyik csomoponttol indulunk ki

    t[fifo[first]].color = 1;
    while(first < last) {
        for(i = 0; i < t[fifo[first]].degree; ++i) {
            lastNode = t[fifo[first]].neight[i];
            if(t[lastNode].color == 0) { // ha feher, tehat meg nem jartunk ott
               fifo[last] = lastNode; // betesszuk a listaba
               t[lastNode].color = 2; // feketere allitjuk, mivel ott mar jartunk
               t[lastNode].parent = fifo[first];
               t[lastNode].distance = t[fifo[first]].distance + 1;
               printf("Az ut %d-ig: ", lastNode);
               route(t, lastNode);
               printf("\n");
               ++last;
            }
        }
        firstNode = fifo[first];
        ++first;
    }


    free(fifo);
    for(i = 0; i <= n; ++i) {
        free(t[i].neight);
    }
    free(t);
    close(f);
    return 0;
}
