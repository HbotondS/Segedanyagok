#include <iostream>
#include <stdlib.h>

using namespace std;

int lnko(int a, int b) {
	return b == 0 ? a : lnko(b, a % b);
}

int main() {
	int n, erdeszi, erdeszj;
	cin >> n;
	cin >> erdeszi;
	cin >> erdeszj;
	int t[n+1][n+1];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			t[i][j] = 1;
	t[erdeszi][erdeszj] = 2;
	// erdesz sora es oszlopa beallitasa
	for (int i = 1; i < erdeszj - 1; ++i)
		t[erdeszi][i] = 0;
	for (int i = erdeszj+2; i <= n; ++i) 
		t[erdeszi][i] = 0;
	for (int i = 1; i < erdeszi - 1; ++i)
		t[i][erdeszj] = 0;
	for (int i = erdeszi+2; i <= n; ++i)
		t[i][erdeszj] = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((t[i][j] == 1) && (i != erdeszi) && (j != erdeszj)) {
				int abs1 = abs(erdeszi - i);
				int abs2 = abs(erdeszj - j);
				 if (lnko(abs1, abs2) != 1)
				 	t[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << t[i][j] << " ";
		cout << endl;
	}
	return 0;
}