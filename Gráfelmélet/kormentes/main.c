#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int degree;
    int* neight;
    int color; ///0 = feher(meg nem jartunk ott); 1 = szurke(most vagyunk ott)\
                    2 = fekete(mar jartunk ott)
    int reach; /// mikor erjuk el, arra kell hogy megtudjuk hogy allapitani az eleket
    int parent;
    int leave;
}Node;

void nodeOut(Node* t, int n){
    int i, j;
    for(i = 1; i <= n; ++i){
        printf("%d: ", i);
        for(j = 0; j < t[i].degree; ++j){
            printf("%d ", t[i].neight[j]);
        }
        printf("parent: %d\n", t[i].parent);
    }
}

void timeOut(Node* t, int n){
    int i;
    for(i = 1; i <= n; ++i){
        printf("%d: %d\n", i, t[i].reach);
    }
}

void depth(Node* t, int i, int time){
    ///printf("%d ", i);
    t[i].color = 1;
    ++time;
    t[i].reach = time;
    int j, neight;
    for(j = 0; j < t[i].degree; ++j){
        neight = t[i].neight[j];
        if(t[neight].color == 1 && neight != t[i].parent){
            ///printf("%d %d\n", i, neight);
            printf("Van benne kor");
        }
        if(t[neight].color == 0){
            t[neight].parent = i;
            depth(t, neight, time);
        }
    }
    t[i].color = 2;
    ++time;
    t[i].leave = time;
}

void DFS(Node* t, int n){
    int i;
    for(i = 1; i <= n; ++i){
        if(t[i].color == 0){
            depth(t, i, 0);
        }
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
    for(i = 1; i <= n; ++i){ ///inicializalas
        t[i].neight = (int*)malloc(n);
        t[i].color = 0; ///feher
        t[i].degree = 0;
        t[i].parent = 0;
        t[i].reach = 0;
        t[i].leave = 0;
    }
    int node1, node2;
    for(i = 1; i <= m; ++i){
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neight[t[node1].degree++] = node2;
        t[node2].neight[t[node2].degree++] = node1;
    }
    for(i = 1; i <= n; ++i){
        if(!(t[i].neight = realloc(t[i].neight, (t[i].degree + 1) * sizeof(int)))){
            printf("Reallocation failed.\n");
            return 1;
        }
    }
    ///nodeOut(t, n);
    DFS(t, n);
    ///timeOut(t, n);
    ///nodeOut(t, n);

    for(i = 0; i <= n; ++i) {
        free(t[i].neight);
    }
    free(t);
    close(f);
    return 0;
}
