#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream f;
	f.open("be.txt");
	int n;
	f >> n;
	int t[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			f >> t[i][j];
		}
	}
	for (int k = (n-2); k > 0; --k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				t[i][j] += t[i][j+1] + t[i+1][j] + t[i+1][j+1];
			}
		}
	}
	cout << t[0][0];
	f.close();
	return 0;
}