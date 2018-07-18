#include <iostream>

using namespace std;

int max(int a, int b) {
	// ha a > b akkor a-t terit vissza, hanem b-t
	return (a > b) ? a : b;
}

int main(){
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << max(max(a, b), c);
	return 0;
}