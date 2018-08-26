#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
///elvago pontok

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF INT_MAX

typedef struct Node{
    int degree;
    int* neight;
    int color;
    int level;
    int parent;
}Node;

void printLevel(Node *t, int numberOfNode);

void nodeOut(Node* t, int numberOfNode) {
    for (int i = 1; i <= numberOfNode; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < t[i].degree; ++j) {
            printf("%d ", t[i].neight[j]);
        }
        printf("\n");
    }
}

int elvagoPont(Node* t, int numberOfNode, int actualNode,  int actualLevel) {
    t[actualNode].color = GREY;
    t[actualNode].level = actualLevel;
    int RFminVM = INF;
    int lost_child = 0, childs = 0;
    for (int i = 0; i < t[actualNode].degree; ++i) {
        int neight = t[actualNode].neight[i];
        if(t[neight].color == WHITE) { ///i utodja az actualNode-nak
            ++childs;
            t[neight].parent = actualNode;
            int UminVM = elvagoPont(t, numberOfNode, neight, actualLevel+1);
            if(UminVM < actualLevel) { ///az actualNode-nak i gyokeru fiu-reszfajanak
                if(UminVM < RFminVM) {///viszamutato ele(ha egyaltalan letezik) v-re
                    RFminVM = UminVM;///nezve is visszamutato
                }
            }
            else { ///nincs visszamutato el => i fiu-reszfa elszakad az actualNode-tol
                ++lost_child;
            }
        }
        else {
            if(t[neight].color == GREY) { ///i "ose" az actualNode-nak
                if(t[neight].level < actualLevel - 1) {
                    if(t[neight].level < RFminVM) {
                        RFminVM = t[neight].level;
                    }
                }
            }
        }
    }
    t[actualNode].color = BLACK;
    if(t[actualNode].parent != 0) {
        if(lost_child > 0) {
            printf("%d lost child(s): %d\n", actualNode, lost_child);
        }
    }
    else {
        if(childs > 1) {
            printf("%d child(s): %d\n", actualNode, childs);
        }
    }
    return RFminVM;
}

void cutOffNode(Node* t, int numberOfNode, int actualNode, int actualLevel) {
    t[actualNode].color = GREY;
    t[actualNode].level = actualLevel;

    for(int i = 0; i < t[actualNode].degree; ++i) {
        int neight = t[actualNode].neight[i];
        if(t[neight].color == WHITE) {
            cutOffNode(t, numberOfNode, neight, actualLevel+1);
        }
    }

    t[actualNode].color = BLACK;
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
        t[i].level = 0;
        t[i].parent = 0;
    }
    int node1, node2;
    for (int i = 1; i <= numberOfEdge ; ++i) {
        fscanf(f, "%d%d", &node1, &node2);
        t[node1].neight[ t[node1].degree++ ] = node2;
        t[node2].neight[ t[node2].degree++ ] = node1;
    }
    fclose(f);
    //nodeOut(t, numberOfNode);
    elvagoPont(t, numberOfNode, 1, 0);
    //cutOffNode(t, numberOfNode, 1, 0);
    //printLevel(t, numberOfNode);
    free(t);
    return 0;
}

void printLevel(Node *t, int numberOfNode) {
    for (int i = 1; i <= numberOfNode; ++i) {
        printf("%d %d\n", i, t[i].level);
    }
}