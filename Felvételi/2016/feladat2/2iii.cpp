#include <iostream>

using namespace std;

int main() {
	// a, b, c - a legkisebb harom szam
	// d - az aktualisan beolvasott szam
	// n - sorozat hossza
	int a, b, c, d, n;
	cin >> n;
	cin >> a;
	cin >> b;
	// elso ket elem rendzese, ha szukseges
	if (b < a) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	// elso harom elem rendzese, ha szukseges
	cin >> c;
	if (c < b) {
		if (c < a) {
			int tmp1 = a;
			int tmp2 = b;
			a = c;
			b = tmp1;
			c = tmp2;
		} else {
			int tmp = b;
			b = c;
			c = tmp;
		}
	}
	// az aktualis elemet beolvassuk es megnezzuk,
	// hogy be kell-e tenni a "sorba"
	// ha igen a tobbi elemet arrab toljuk
	for(int i = 3; i < n; ++i) {
		cin >> d;
		if (d < c) {
			if (d < b) {
				if (d < a) {
					int tmp1 = a, tmp2 = b;
					a = d;
					b = tmp1;
					c = tmp2;
				} else {
					int tmp = b;
					b = d;
					c = tmp;
				}
			} else {
				c = d;
			}
		}
	}
	cout << a << b << c << endl;
	return 0;
}