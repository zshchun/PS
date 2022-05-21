#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N, mx, m, mv, v, c;
	cin >> T;
	while(T--) {
		cin >> N;
		m = -1;
		mv = 1;
		for (i=0;i<N;i++) {
			cin >> a[i];
		}
		for (i=1;i<N;i++) {
			v = a[i] - a[i-1];
			if (v >= 0) {
				if (m != -1 && m != v) {
					goto invalid;
				}
				m = v;
			} else {
				if (mv != 1 && mv != v) {
					goto invalid;
				}
				mv = v;
			}
		}
		if (N <= 1 || (m == 0 && mv == 1)) {
			cout << "0\n";
		} else if (m > 0 && mv < 0) {
			c = m - mv;
			bool valid = true;
			for (i=0;i<N-1;i++) {
				if (a[i] >= c || (a[i]+m) % c != a[i+1]) {
					valid = false;
					break;
				}
			}
			if (valid)
				cout << c << " " << m << "\n";
			else
				cout << "-1\n";
		} else if (m > 0 || (m && mv < 0)) {
			cout << "0\n";
		} else {
invalid:
			cout << "-1\n";
		}
	}

	return 0;
}
