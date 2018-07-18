#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 0, b = 1, tmp;
	cout << a << b;
	for (int i = 2; i < n; ++i) {
		tmp = a + b;
		cout << tmp;
		a = b;
		b = tmp;
	}
	cout << endl;
	return 0;
}