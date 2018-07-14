#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a;
	cin >> b;
	if (a == b)
		cout << "a ket szam egyenlo" << endl;
	else if (a < b)
		cout << a << " kisebb mint " << b << endl;
	else if (a > b)
		cout << a << " nagyobb mint " << b << endl;
	return 0;
}