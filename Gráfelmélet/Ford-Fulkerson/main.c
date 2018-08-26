///maximalis folyam megkeresese

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <windef.h>

void print(int** t, int numberOfNode) {
    for (int i = 0; i < numberOfNode; ++i) {
        for (int j = 0; j < numberOfNode; ++j) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}

/// Return true if there is a path form @source to @sink
/// Also fill the parent array to store the path
bool bfs(int** t, int numberOfNode, int source, int sink, int* parent) {
    bool visited[numberOfNode];
    for (int i = 0; i < numberOfNode; ++i) {
        visited[i] = false;
    }
    int queue[numberOfNode]; ///sor
    int first = 0, last = 0;
    queue[last++] = source; ///push
    visited[source] = true;
    parent[source] = -1;

    while (first < last) {
        int u = queue[first++]; ///front and pop

        for (int i = 0; i < numberOfNode; ++i) {
            if(visited[i] == false && t[u][i] > 0) {
                queue[last++] = i;
                parent[i] = u;
                visited[i] = true;
            }
        }
    }

    return (visited[sink] == true);
}

/// Return the maximum flow from @source to @sink in the given graph
int FordFulkerson(int** t, int numberOfNode, int source, int sink) {
    int u;
    int** rt = NULL;

    if ( !(rt = (int**)calloc(numberOfNode, sizeof(int*))) ) {
        printf("Allocation failed.");
        return 1;
    }
    for (int i = 0; i < numberOfNode; ++i) {
        if( !(rt[i] = (int*)calloc(numberOfNode, sizeof(int))) ) {
            printf("Allocation failed.");
            return 1;
        }
    }

    for (int i = 0; i < numberOfNode; ++i) {
        for (int j = 0; j < numberOfNode; ++j) {
            rt[i][j] = t[i][j];
        }
    }


    int* parent = NULL;

    if ( !(parent = (int*)calloc(numberOfNode, sizeof(int))) ) {
        printf("Allocation failed.");
        return 1;
    }

    int maxFlow = 0;

    while (bfs(rt, numberOfNode, source, sink, parent)) {
        int pathFlow = INT_MAX;
        for (int i = sink; i != source; i = parent[i]) {
            u = parent[i];
            pathFlow = min(pathFlow, rt[u][i]);
        }

        for (int i = sink; i != source; i = parent[i]) {
            u = parent[i];
            rt[u][i] -= pathFlow;
            rt[i][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    FILE* in;
    if ( !(in = fopen("BFS.txt", "r")) ) {
        printf("The file doesn't found.");
        return 1;
    }
    int numberOfNode, numberOfEdge;
    fscanf(in, "%d%d", &numberOfNode, &numberOfEdge);
    int** t;
    if ( !(t = (int**)calloc(numberOfNode, sizeof(int*))) ) {
        printf("Allocation failed.");
        return 1;
    }
    for (int i = 0; i < numberOfNode; ++i) {
        if( !(t[i] = (int*)calloc(numberOfNode, sizeof(int))) ) {
            printf("Allocation failed.");
            return 1;
        }
    }
    for (int i = 0; i < numberOfEdge; ++i) {
        int node1, node2;
        fscanf(in, "%d%d", &node1, &node2);
        fscanf(in, "%d", &t[node1][node2]);
    }

    printf("The maximum flow is %d", FordFulkerson(t, numberOfNode, 0, 5));

    fclose(in);
    for (int j = 0; j < numberOfNode; ++j) {
        free(t[j]);
    }
    free(t);
    return 0;
}
