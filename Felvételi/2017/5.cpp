#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n == 2017)
		cin >> n;
	if (n < 2017)
		for (int i = n; i <= 2017; ++i)
			cout << i;
	else
		for (int i = n; i >= 2017; --i)
			cout << i;
	return 0;
}