#include <bits/stdc++.h>
using namespace std;
int main() {
	int i, n;
	double m;
	cin >> n;
	double *a = new double[n];
	double *nn = new double[n];
	m = 0;
	for (i=0;i<n;i++) {
		cin >> a[i];
		if (a[i] > m)
			m = a[i];
	}
	double s = 0;
	for (i=0;i<n;i++) {
		nn[i] = a[i] / m * 100.0;
		s += nn[i];
	}
	cout << setprecision(9) << (s / (double)n) << "\n";
	return 0;

}

