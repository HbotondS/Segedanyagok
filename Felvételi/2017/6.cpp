#include <iostream>

using namespace std;

int torol(int t[], int n, int x) {
	for (int i = 0; i < n; ++i)
		if (x == t[i]) {
			t[i] = t[n-1];	// utolso elemet betesszuk e helyere
			break;			// kilepunk mert nem ismetlodik
		}
	return --n;				// csokentjuk a darabszamot
}

int main() {
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	int x;
	cin >> x; // keresett szam - amit torolni kell
	n = torol(t, n, x);
	cout << n;
	return 0;
}