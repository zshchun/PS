#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, k, i, j, n, m, v, x, y;
	cin >> TC;
	for (k=1;k<=TC;k++) {
		cin >> n >> m;
		map<ll,ll> a, b;
		for (i=0;i<n;i++) {
			cin >> v;
			for (j=2;j<=sqrt(v);j++) {
				while (v % j == 0) {
					a[j]++;
					v /= j;
				}
			}
			if (v > 1) a[v]++;
		}
		for (i=0;i<m;i++) {
			cin >> v;
			for (j=2;j<=sqrt(v);j++) {
				while (v % j == 0) {
					b[j]++;
					v /= j;
				}
			}
			if (v > 1) b[v]++;
		}
		ll numerator = 1, denominator = 1;
		for (auto it=a.begin();it != a.end();it++) {
			x = it->first;
			y = it->second;
			if (b[x] > 0) {
				v = min(a[x], b[x]);
				a[x] -= v;
				b[x] -= v;
			}
			while (x > 1 && a[x] > 0) {
				numerator *= x;
				a[x]--;
			}
		}
		for (auto it=b.begin();it != b.end();it++) {
			x = it->first;
			y = it->second;
			while (x > 1 && b[x] > 0) {
				denominator *= x;
				b[x]--;
			}
		}
		cout << "Case #" << k << ": " << numerator << " / " << denominator << endl;
	}
	return 0;
}
