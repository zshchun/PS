#include <bits/stdc++.h>
using namespace std;
int x[51], y[51], r[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> x[i] >> y[i];
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (i == j) continue;
			if (x[j] > x[i] && y[j] > y[i])
				r[i]++;
		}
	}
	for (i=0;i<n;i++) {
		if (i) cout << " ";
		cout << r[i]+1;
	}
	cout << "\n";

	return 0;
}
