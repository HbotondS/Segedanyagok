#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) a > b ? b : a
#define WHITE 0
#define GREY  1
#define BLACK 2

typedef struct Node {
    int* neight;
    int color, parent, level;
}Node;

void nodeOut(Node* t, int n) {
    int i, j;
    for(i = 1; i <= n; ++i) {
        printf("%d: ", i);
        for(j = 1; j <= t[i].neight[0]; ++j) {
            printf("%d ", t[i].neight[j]);
        }
        printf("\n");
    }
}

int int_cmp(const void* a, const void* b) {
    return ( *(int*)a - *(int*)b );
}

int Bridge(Node* t, int actualNode,int level) {
    int i;
    t[actualNode].color = GREY;
    t[actualNode].level = level;
    int minLevel = INT_MAX;

    for(i = 1; i <= t[actualNode].neight[0]; ++i) {
        int neight = t[actualNode].neight[i];
        if(t[neight].color == WHITE) {
           // printf("%i ",szomszed);
            t[neight].parent = actualNode;
            int childMinLevel = Bridge(t, neight, level+1);
            if(childMinLevel < level) {
                if(childMinLevel < minLevel) {
                    minLevel = childMinLevel;
                }
            }
        }
        else {
            if(t[neight].color == GREY) {
                if(t[neight].level < level-1) {
                    if(t[neight].level < minLevel) {
                        minLevel = t[neight].level;
                    }
                }
            }
        }
    }

    t[actualNode].color = BLACK;
    if(t[actualNode].parent) {
        if(minLevel == INT_MAX) {
            printf("Elvago el: %i - %i\n", t[actualNode].parent, actualNode);
        }
    }

    return minLevel;
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
    if( !(t = (Node*)malloc((n + 1) * sizeof(Node))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    for(i = 1; i <= n; ++i) { // inicializalas
        if( !(t[i].neight = (int*)malloc(n+1)) ) {
            printf("Allocation failed.\n");
            return 1;
        }
        t[i].color = WHITE;
        t[i].parent = 0;
        t[i].level = 0;
        t[i].neight[0] = 0;
    }
    int node1, node2;
    for(i = 1; i <= m; ++i) {
        fscanf(f, "%d%d", &node1, &node2);
        // a nulladik elemben tarolom azt hogy hany szomszedja van
        t[node1].neight[0]++;
        t[node1].neight[ t[node1].neight[0] ] = node2;

        t[node2].neight[0]++;
        t[node2].neight[ t[node2].neight[0] ] = node1;
    }
    /**for(i = 1; i <= n; ++i) {
        if(!(t[i].neight = realloc(t[i].neight, (t[i].neight[0] + 1) * sizeof(int)))) {
            printf("Reallocation failed.\n");
            return 1;
        }
    }*/

    for(i = 1; i <= n; ++i) {
        if( t[i].neight[0] ) { // van szomszedja
            qsort( t[i].neight+1, t[i].neight[0], sizeof(int), int_cmp );
        }
    }

    // nodeOut(t, n);
    for(i = 1; i <= n; ++i) {
        if( t[i].color == WHITE ) {
            Bridge(t, i, 0);
        }
    }
    // nodeOut(t, n);

    for(i = 0; i <= n; ++i)  {
        free(t[i].neight);
    }
    free(t);
    close(f);
    return 0;
}
