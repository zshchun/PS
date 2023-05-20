#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll a[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, j, x, m, l, r, ans = 0;

	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	sort(a, a+N);

	for (i=0;i<N;i++) {
		bool found = false;
		for (j=0;j<N && !found;j++) {
			if (i == j) continue;
			x = a[i] - a[j];
			l = 0;
			r = N - 1;
			while (l <= r) {
				m = (l + r) / 2;
				if (a[m] == x && m != i && m != j) {
					ans++;
					found = true;
					break;
				}

				if (a[m] > x) {
					r = m - 1;
				} else {
					l = m + 1;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
