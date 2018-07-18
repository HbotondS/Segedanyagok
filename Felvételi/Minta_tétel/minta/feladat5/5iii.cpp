#include <iostream>
#include <stdlib.h>

using namespace std;

int compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int n;
	cin >> n;
	int t[n];
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	qsort(t, n, sizeof(int), compare);
	for (int i = 0; i < n; ++i) {
		cout << t[i];
	}
	return 0;
}