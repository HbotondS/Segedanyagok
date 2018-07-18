#include <iostream>

using namespace std;

// kiirja novekvo sorrendbe a harom szamot
void novKiir(int a, int b, int c) {
	if (a > b) {
		// ket valtozo kicserelese harmadik nelkul
		a = a+b;
		b = a-b;
		a = a-b;
	}
	if (b > c) {
		b = b+c;
		c = b-c;
		b = b-c;
	}
	if (a > b) {
		a = a+b;
		b = a-b;
		a = a-b;
	}
	cout << a << b << c << endl;
}

int main(){
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	novKiir(a, b, c);
	return 0;
}