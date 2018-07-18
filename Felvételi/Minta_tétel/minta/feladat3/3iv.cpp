#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int t[10] = {0};
	while (n != 0) {
		++t[n % 10];
		n /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		cout << i << ": " << t[i] << endl;
	}
	return 0;
}