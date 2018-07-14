#include <iostream>

using namespace std;

int szamjegyossz(int a) {
	int sum = 0;
	while (a > 0) {
		// utolso szamjegy
		sum += a % 10;
		// utolso szamjegy levagasa
		a = a / 10;
	}
	return sum;
}

int main() {
	int n, a, sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		sum += szamjegyossz(a);
	}
	cout << sum << endl;
	return 0;
}