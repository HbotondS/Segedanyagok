#include <iostream>

using namespace std;

int min(int a, int b) {
	// ha a < b akkor a-t terit vissza, hanem b-t
	return (a < b) ? a : b;
}

int main(){
	int a, b;
	cin >> a;
	cin >> b;
	cout << min(a, b);
	return 0;
}