#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream be;
	be.open("be.txt"); // fajl megnyitasa
	if (be.is_open()) { // sikeres megnyitas ellenorzese
		int n;
		be >> n;
		int t[n][n];
		// tombbeolvasas
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				be >> t[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < i; ++k) {
				int tmp = t[i][n-1]; // utolso elem elmentese
				for (int j = n-1; j > 0; --j) {
					t[i][j] = t[i][j-1]; // jobbra tolsa hatulrol kezdve
				}
				t[i][0] = tmp; // elore betesszuk az utolsot
			}
		}
		// kiiratas
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << t[i][j] << " ";
			}
			cout << endl;
		}
	} else 
		cout << "a fajl nem talalhato" << endl;;
	return 0;
}