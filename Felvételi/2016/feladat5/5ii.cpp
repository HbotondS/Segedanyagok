#include <iostream>

using namespace std;

bool prim(int a) {
	if (a % 2 == 0)
		return false;
	else
		for (int i = 3; i < a/2; i+=2)
			if (a % i == 0)
				return false;
	
	return true;
}

int lnko(int a, int b) {
	return (b == 0) ? a : lnko(b, a% b);
}

int main() {
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	for (int i = n-1; i >= 0; --i)
		if (prim(t[i]) && prim(t[i-1]))
			if (lnko(t[i], t[i-1]) == 1)
				cout << t[i] << " " << t[i-1] << endl;
	return 0;
}