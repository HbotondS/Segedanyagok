#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n > 9)	// addig vagjuk le az utlso szamjegyet
		n /= 10;	// amig a szam kisebb nem lesz mint 10
	cout << n;		// vagyis a legelso szamjegyet kapjuk meg
	return 0;
}