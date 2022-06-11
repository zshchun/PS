#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n, i, t, l, r, v;
	int a[100001];
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	cin >> t;
	for (i=0;i<t;i++) {
		cin >> v;
		l = 0;
		r = n-1;
		while (l <= r) {
			m = (l+r) / 2;
			if (v < a[m]) {
				r = m-1;
			} else if (v > a[m]) {
				l = m+1;
			} else {
				break;
			}
		}
		if (a[m] == v) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}

	return 0;
}
