#include <iostream>

using namespace std;

int main() {
	int n, k = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (k >= n)
				break;
			cout << j;
			k++;
		}
	}
	return 0;
}