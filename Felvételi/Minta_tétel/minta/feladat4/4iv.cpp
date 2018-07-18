#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int k = 0;
	// c++ban nem kotelezo feltetelt adni a ciklusnak
	for (int i = 1;; ++i) {	
		for (int j = 1; j <= i; ++j) {
			// ellenorizni kell hogy mennyi szamot irtunk ki
			if (k < n) {
				cout << j;
				// kiiratas utan noveljuk a valtozot hogy
				// egyet mar kiirtunk
				++k;
			} else {
				break;
			}
		}
		// itt is, mert ket ciklus van => 2 break kell!!
		if (k >= n) {
			break;
		}
	}
	cout << endl;
	return 0;
}