#include <iostream>

using namespace std;

int main(){
	// max = maximum elem
	// maxi = maximum elem helye
	// min = minimum elem
	// mimi = minimum elem helye
	int n, max = -999, maxi, min = 999, mini;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		if (t[i] > max) {
			max = t[i];
			maxi = i;
		}
		if (t[i] < min) {
			min = t[i];
			mini = i;
		}
	}
	cout << "max: " << max << " " << maxi << endl;
	cout << "min: " << min << " " << mini << endl;
	return 0;
}