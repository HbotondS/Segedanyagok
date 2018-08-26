#include <stdio.h>
#include <stdlib.h>

int min(int* t, int n){
    int i, m = n, mi;
    for(i = 1; i <= n; ++i){
        if(t[i] < m && t[i] > 0){
            m = t[i];
            mi = i;
        }
    }
    return mi;
}

int main()
{
    FILE* in;
    if(!(in = fopen("fa.txt", "r"))){ ///beolvasas es ellenorzes
        printf("A fajl nem talalhato.");
        return -1;
    }

    int n, i, j, e, v, mi;
    fscanf(in, "%d", &n);
    printf("%d\n", n);
    int** el;
    if(!(el = (int**)calloc(n-1, sizeof(int*)))){ ///helylefoglalas (dinamikusan) es ellenorzes
        printf("A hejlefoglalas sikertelen.");
        return -1;
    }
    for(i = 0; i < n-1; ++i){
        if(!(el[i] = (int*)calloc(2, sizeof(int)))){
            printf("A hejlefoglalas sikertelen.");
            return -1;
        }
    }

    for(i = 0; i < n-1; ++i){ ///beolvasas
        fscanf(in, "%d %d", &e, &v);
        el[i][0] = e;
        el[i][1] = v;
    }
    for(i = 0; i < n-1; ++i){
        printf("%d -> %d\n", el[i][0], el[i][1]);
    }

    int* fok;
    if(!(fok = (int*)calloc(n+1, sizeof(int)))){
        printf("A hejlefoglalas sikertelen.");
        return -1;
    }

    for(i = 0; i < n-1; ++i){ ///fokszamok tarolasa
        ++fok[el[i][0]];
        ++fok[el[i][1]];
    }

    printf("\nPrufer kod: ");
    int* pr = (int*)calloc(n, sizeof(int)); ///prufer kodot taroljuk benne
    int prn = 0;
    for(i = 1; i <= n; ++i){
        mi = min(fok, n); ///a legkisebb fokszamu biztos hogy level
        for(j = 0; j < n-1; ++j){ ///megkeressuk az ellistaban
            if(mi == el[j][0]){
                printf("%d ", el[j][1]);
                pr[prn++] = el[j][1];
                --fok[el[j][0]]; ///fokszamot csokentjuk mert
                --fok[el[j][1]]; ///azt a csomopontot mar levagtuk
                el[j][0] = 0; ///nullazuk az ellhez tartozo csomopontot
                el[j][1] = 0; ///hogy megegyszer ne kapjuk meg
            }
            else{
                if(mi == el[j][1]){
                    printf("%d ", el[j][0]);
                    pr[prn++] = el[j][0];
                    --fok[el[j][0]];
                    --fok[el[j][1]];
                    el[j][0] = 0;
                    el[j][1] = 0;
                }
            }
        }
    }
    printf("\n");
    ///prufer kod visszafejtese
    int* sz = (int*)calloc(n, sizeof(int)); ///az adott csomopont szerepelt-e
    int k, jo;
    for(i = 0; i < prn; ++i){
        for(j = 1; j <= prn; ++j){
           if(sz[j] == 0){
               jo = 1;
               for(k = i; k < prn; ++k){
                   if(j == pr[k]){
                       jo = 0;
                   }
               }
               if(jo){
                   sz[j] = 1;
                   printf("%d -> %d\n", j, pr[i]);
                   break;
               }
           }
        }
    }

    for(i = 0; i < 2; ++i){ ///hely felszabaditasa
        free(el[i]);
    }
    free(el);
    free(fok);
    close(in);
    return 0;
}
