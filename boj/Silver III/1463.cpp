#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, i, m;
	cin >> x;
	int *a = new int[x+1];
	a[0] = 0;
	a[1] = 0;
	for (i=2;i<=x;i++) {
		m = 1 << 29;
		if ((i % 3 == 0) && a[i/3] < m) {
			m = a[i/3];
		}
		if ((i % 2 == 0) && a[i/2] < m) {
			m = a[i/2];
		}
		if (a[i-1] < m) {
			m = a[i-1];
		}
		a[i] = m + 1;
	}

	cout << a[x] << "\n";
	return 0;
}



