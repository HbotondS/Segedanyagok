#include <iostream>

using namespace std;

bool perm(int t[], int n) {
	int b[n] = {0}; // ebben fogjuk szamolni a gyakorisagot
	for (int i = 0; i < n; ++i) {
		++b[t[i]];
		if (b[t[i]] > 1) // ha tobbszor szerepel mint egy akkor nem permutacio
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	cout << perm(t, n);
	return 0;
}