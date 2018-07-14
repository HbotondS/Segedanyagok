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
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	f.close();
	return 0;
}