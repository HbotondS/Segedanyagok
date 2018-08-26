#include <stdio.h>
#include <stdlib.h>

int stack[20];
int pointer = 0;

void push (int x) {
    stack[pointer++] = x;
}

void pop () {
    stack[pointer--] = 0;
}

int ending(int** t, int numberOfNodes) {
    int k = 0;
    for(int i = 0; i < numberOfNodes; i++) {
        for (int j = 0; j < numberOfNodes; j++) {
            if (t[i][j]) {
                k++;
            }
        }
    }
    if (k > 0) {
        return 0;
    } else {
        return 1;
    }
}

void printRoute() {
    for (int i = 0; i < pointer; i++) {
        printf("%d ", stack[i] + 1);
    }
    printf("\n");
}

void euler(int** t, int start, int numberOfNodes) {
    for (int i = 0; i < numberOfNodes; i++) {
        if (t[start][i]) {
            push(start);
            t[start][i] = t[i][start] = 0;
            euler(t, i, numberOfNodes);
            pop();
            t[start][i] = t[i][start] = 1;
        }
    }
    if (ending(t, numberOfNodes)) {
        push(start);
        printRoute();
        pop();
    }
}

int main() {
    FILE * in = fopen("be.txt", "r");
    int numberOfNodes, numberOfEdges;

    fscanf(in, "%d%d", &numberOfNodes, &numberOfEdges);

    int** t;
    if ( !(t = (int**)calloc(numberOfNodes, sizeof(int*))) ) {
        printf("Allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < numberOfNodes; i++) {
        if ( !(t[i] = (int*)calloc(numberOfNodes, sizeof(int))) ) {
            printf("Allocation failed.\n");
            return 1;
        }
    }

    int node1, node2;

    for (int i = 0; i < numberOfEdges; i++) {
        fscanf(in, "%d%d", &node1, &node2);
        t[node1][node2] = 1;
        t[node2][node1] = 1;
    }
    fclose(in);

    int par=1;
    for (int i = 0; i < numberOfNodes; i++) {
        int k = 0;
        for (int j = 0; j < numberOfNodes; j++) {
            if (t[i][j]) {
                k++;
            }
        }
        if (k%2 == 1) {
            par = 0;
            break;
        } else {
            par = 1;
        }
    }

    int start = 0;
    if (par == 1) {
        euler(t, start, numberOfNodes);
    }

    for (int i = 0; i < numberOfNodes; ++i) {
        free(t[i]);
    }
    free(t);

    return 0;
}
