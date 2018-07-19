#include <iostream>

using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int sormin(int t[], int n) {
	int tmp = 999;
	for (int i = 0; i < n; ++i)
		tmp = min(tmp, t[i]);
	return tmp;
}

int sormax(int t[], int n) {
	int tmp = -999;
	for (int i = 0; i < n; ++i) 
		tmp = max(tmp, t[i]);
	return tmp;
}

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	int t[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> t[i][j];
	for (int i = 0; i < n; ++i)
		if (i % 2 == 0)
			cout << sormax(t[i], m);
		else
			cout << sormin(t[i], m);
	return 0;
}
