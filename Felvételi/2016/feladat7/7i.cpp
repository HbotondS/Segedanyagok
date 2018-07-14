#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int t[n][m];
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
	if (i == n)
		cout << "Megfelelo szamu virag erkezett" << endl;
	else
		cout << "Nem erkezett megfelelo szamu virag" << endl;
	return 0;
}