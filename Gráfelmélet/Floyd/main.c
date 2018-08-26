#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
///minden pont kozott a legrovidebb ut
///negativ kor nelkul
///iranyitott graffal dolgozunk

#define WHITE 0
#define GREY 1
#define BLACK 2
#define True 1
#define False 0
#define INF INT_MAX

typedef struct Node{
    int degree;
    int* neight;
    int color;
    float distance;
    int parent;
}Node;

void nodeOut(Node* t, int numberOfNode) {
    for (int i = 1; i <= numberOfNode; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < t[i].degree; ++j) {
            printf("%d ", t[i].neight[j]);
        }
        printf("\n");
    }
}

void intiWeight(double** t, int numberOfNode){
    for (int i = 0; i <= numberOfNode; ++i) {
        for (int j = 0; j <= numberOfNode; ++j) {
            if(i == j){
                t[i][j] = 0;
            }
            else {
                t[i][j] = INF;
            }
        }
    }
}

void weightOut(double** t, int numberOfNode) {
    int i, j;
    for(i = 1; i <= numberOfNode; ++i) {
        for(j = 1; j <= numberOfNode; ++j) {
            if(t[i][j] >= INF/2) {
                printf("infin ");
            }
            else {
                printf("%5.1lf ", t[i][j]);
            }
        }
        printf("\n");
    }
}

void lru(int i, int j, int **pInt) {
    if(i != j) {
        lru(i, pInt[i][j], pInt);
    }
    printf("%d ", j);
}

void Floyd(double** weight, int numberOfNode) {
    int** ue = (int**)malloc((numberOfNode + 1) * sizeof(int*));
    for(int i = 1; i <= numberOfNode; ++i){
        ue[i] = (int*)malloc((numberOfNode+1) * sizeof(int));
    }
    for (int i = 1; i <= numberOfNode; ++i) {
        for (int j = 1; j <= numberOfNode; ++j) {
            if(weight[i][j] != INF && i!=j) {
                ue[i][j] = i;
            } else{
                ue[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= numberOfNode; ++k) {
        for (int j = 1; j <= numberOfNode; ++j) {
            for (int i = 1; i <= numberOfNode; ++i) {
                if(i != k && j != k) {
                    if(weight[i][k] + weight[k][j] < weight[i][j]) {
                        weight[i][j] = weight[i][k] + weight[k][j];
                        ue[i][j] = ue[k][j];
                    }
                }
            }
        }
    }
    for (int i = 1; i <= numberOfNode; ++i) {
        for (int j = 1; j <= numberOfNode; ++j) {
            if(ue[i][j] != 0) {
                lru(i, j, ue);
                printf("\n");
            }
            else {
                if(i != j) {
                    printf("There is no route from %d to %d.\n", i, j);
                }
            }
        }
    }

    for (int j = 0; j <=numberOfNode ; ++j) {
        free(ue[j]);
    }
    free(ue);
}

int main() {
    FILE *f;
    if( !(f = fopen("in.txt", "r")) ) {
        printf("The file doesn't exist.\n");
        return 1;
    }
    int numberOfNode, numberOfEdge;
    fscanf(f, "%d", &numberOfNode);
    fscanf(f, "%d", &numberOfEdge);
    Node* t;
    if( !(t = (Node*)malloc((numberOfNode + 1) * sizeof(Node)))) {
        printf("Allocation failed.\n");
        return 1;
    }
    for (int i = 0; i <= numberOfNode; ++i) {
        t[i].neight = (int*)malloc(numberOfNode);
        t[i].color = WHITE;
        t[i].degree = 0;
        t[i].distance = INF;
        t[i].parent = 0;
    }

    double **weight;
    if( !(weight = (double**)malloc((numberOfNode + 1) * sizeof(double*)))) {
        printf("Allocation failed.\n");
        return 1;
    }
    for (int i = 0; i <= numberOfNode; ++i) {
        if( !(weight[i] = (double*)malloc((numberOfNode+1) * sizeof(double))) ) {
            printf("Allocation failed.\n");
            return 1;
        }
    }
    intiWeight(weight, numberOfNode);
    int node1, node2;
    for (int i = 1; i <= numberOfEdge ; ++i) {
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neight[ t[node1].degree++ ] = node2;
        fscanf(f, "%lf", &weight[node1][node2]);
    }
    fclose(f);
    ///nodeOut(t, numberOfNode);
    ///weightOut(weight, numberOfNode);
    Floyd(weight, numberOfNode);

    for (int j = 0; j <=numberOfNode ; ++j) {
        free(weight[j]);
    }
    free(weight);
    free(t);
    return 0;
}