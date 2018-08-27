#include <stdio.h>
#include <stdlib.h>

int* sequence;  // ebben mentjuk el a sorrendet es majd visszafele kiirjuk
int ii = 0;

typedef struct Node {
    int degreeIn;   // befokszám
    int degreeOut;  // kifokszám
    int* neightIn;  // a csomopont szomszedjai
    int* neightOut;
    int color;      // 0 = feher(meg nem jartunk ott); 1 = szurke(most vagyunk ott)\
                        2 = fekete(mar jartunk ott)
    int reach;      // mikor erjuk el, arra kell hogy megtudjuk allapitani az eleket
    int parent;     // ki az "apja"
    int leave;      // mikor hadjuk el
}Node;

void nodeOut(Node* t, int n) {
    int i, j;
    for(i = 1; i <= n; ++i) {
        printf("%d: ", i);
        /*printf("Out: ");
        for(j = 0; j < t[i].degreeOut; ++j){
            printf("%d ", t[i].neightOut[j]);
        }
        printf("Kifokszam: %d", t[i].degreeOut);*/
        printf("Parent: %d", t[i].parent);
        printf("\n");
    }
}

void timeOut(Node* t, int n) {
    int i;
    for(i = 1; i <= n; ++i) {
        printf("%d: %d\n", i, t[i].reach);
    }
}

void depth(Node* t, int i, int time) {
    // printf("%d ", i);
    t[i].color = 1;
    ++time;
    t[i].reach = time;
    int j, neight;
    int n = t[i].degreeOut;
    for(j = 0; j < n; ++j) {
        neight = t[i].neightOut[j];
        if(t[neight].color == 0) {
            t[neight].parent = i;
            depth(t, neight, time);
        }
    }
    printf("%d ", i);
    sequence[ii++] = i;
    t[i].color = 2;
    ++time;
    t[i].leave = time;
}

void DFS(Node* t, int n) {
    int i;
    for(i = 1; i <= n; ++i) {
        if(t[i].color == 0) {
            depth(t, i, 0);
        }
    }
}

int main() {
    FILE* f;
    if(!(f = fopen("pont.txt", "r"))) {
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
    if(!(sequence = (int*)malloc((n + 1) * sizeof(int)))) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= n; ++i) { // inicializalas
        t[i].neightIn = (int*)malloc(n);
        t[i].neightOut = (int*)malloc(n);
        t[i].color = 0;
        t[i].degreeIn = 0;
        t[i].degreeOut = 0;
        t[i].parent = 0;
        t[i].reach = 0;
        t[i].leave = 0;
    }
    int node1, node2;
    for(i = 1; i <= m; ++i) {
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neightOut[t[node1].degreeOut++] = node2;
        t[node2].neightIn[t[node2].degreeIn++] = node1;
        if(t[node2].parent == 0) {
            t[node2].parent = node1;
        }
        else {
            if(t[node2].parent > node1) {
                t[node2].parent = node1;
            }
        }
    }
    for(i = 1; i <= n; ++i) { // a tomb felhasznalatlan elemeinek a levagasa
        if(!(t[i].neightIn = realloc(t[i].neightIn, (t[i].degreeIn + 1) * sizeof(int)))) {
            printf("Reallocation failed.\n");
            return 1;
        }
        if(!(t[i].neightOut = realloc(t[i].neightOut, (t[i].degreeOut + 1) * sizeof(int)))) {
            printf("Reallocation failed.\n");
            return 1;
        }
    }
    // nodeOut(t, n);
    DFS(t, n);
    // timeOut(t, n);
    printf("\n");
    for(i = ii-1; i >= 0; --i) {
        printf("%d ", sequence[i]);
    }

    for(i = 0; i <= n; ++i) {
        free(t[i].neightOut);
        free(t[i].neightIn);
    }
    free(t);
    free(sequence);
    close(f);
    return 0;
}
