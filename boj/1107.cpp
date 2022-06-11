#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, m, d, v, l, valid;
	fill_n(a, 10, 1);
	cin >> n >> m;
	for (i=0;i<m;i++) {
		cin >> l;
		a[l] = 0;
	}
	d = 1234567891;
	for (i=0;i<=1000000;i++) {
		if (i == 0 && !a[0]) continue;
		if (i == 0) l = 1;
		else l = 0;
		v = i;
		valid = true;
		while (v) {
			if (!a[v % 10]) {
				valid = false;
				break;
			}
			v /= 10;
			l++;
		}
		if (!valid) continue;
		if (abs(n-i) + l < d) {
			d = abs(n-i) + l;
		}
	}
	cout << min(d, abs(100-n)) << "\n";
	return 0;
}
