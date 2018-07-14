#include <iostream>

using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}

void sort(int& a, int& b, int& c) {
	if(a>b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(a>c){
        int tmp = a;
        a=c;
        c = tmp;
    }
    if(b>c){
        int tmp = b;
        b=c;
        c=tmp;
    }
}

int main() {
	int a, b, c, d, n;
	a = b = c = 0;
	cin >> n;
	cin >> a;
	cin >> b;
	if (b < a) {
		int tmp = a;
		a = b;
		b = tmp;
	}
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