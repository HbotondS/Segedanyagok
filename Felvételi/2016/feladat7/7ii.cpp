#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int t[n][m] = {0};
	int v, i = 0, j = 0;
	do {
		cin >> v;			// beolvassuk a szomt
		t[i][j] = v; 
		++j;				// noveljuk az oszlop valtozot
		if (j > (m-1)) {	// ha egyenlo m-el akkor nullazuk
			j = 0;			// es noveljuk a sor valtozot
			++i;
		}
		if (i > n)			// ha nullat olvasunk be vagy megtelt 
			break;			// a tomb akkor befejezzuk a ciklust
	} while (v != 0);

	int maxo = 0, max = 0;
	for (int j = 0; j < m; ++j) {
		int gy[16] = {0};	// tomb inicializalasa
		for (int i = 0; i < n; ++i)
			++gy[t[i][j]];	// szinek gyakorisaganak szamolasa
		int maxsz = 0;		// maximum kereses a szin gyakorisagban
		for (int i = 0; i < 16; ++i)
			if (maxsz < gy[i])
				maxsz = gy[i];
		if (max < maxsz) {	// oszlobna levo maximum nagyobb-e az 
			max = maxsz;	// eddigi maxumumnal?
			maxo = j;
		}
	}
	cout << maxo << endl;
	return 0;
}