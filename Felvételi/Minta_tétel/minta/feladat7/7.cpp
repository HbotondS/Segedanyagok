// https://www.geeksforgeeks.org/traveling-salesman-problem-tsp-implementation/
#include <bits/stdc++.h>
using namespace std;

int travllingSalesmanProblem(int **graph, int n, int s) {
    // kolun taroljuk a csucsokat hogy majd tudjuk permutalni
    vector<int> vertex;
    for (int i = 0; i < n; i++)
        if (i != s)
            vertex.push_back(i);
 
    // minimum tavolsag tarolasa
    int min_path = 999;
    do {
 
        // jelenlegi ut hossza
        int current_pathweight = 0;
         
        // jelenlegi ut hosszanak kiszamitasa
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
        	cout << k;
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 		cout << endl;
        
    } while (next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}

int main() {
    int n;
    cin >> n;
    // dinamikus tomb letrehozasa
    int** graph = new int*[n];
    for (int i = 0; i < n; ++i) 
    	graph[i] = new int[n];
    // beolvasas
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j)
    		cin >> graph[i][j];

    cout << travllingSalesmanProblem(graph, n, 0) << endl;
    return 0;
}