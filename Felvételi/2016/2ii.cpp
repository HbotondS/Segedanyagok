#include <iostream>

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << max(max(a, b), c) << endl;
	return 0;
}