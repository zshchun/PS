#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, M, ans=0, m, l, r, u=0, s;
	cin >> N >> M;
	for (i=0;i<N;i++) {
		cin >> a[i];
		if (a[i] > u) u = a[i];
	}
	l = 0;
	r = u;
	while (l <= r) {
		m = (l+r) / 2;
		s = 0;
		for (i=0;i<N;i++) {
			if (a[i] > m)
				s += a[i] - m;
		}
		if (s >= M) {
			if (ans < m)
				ans = m;
			
			l = m+1;

		} else {
			r = m-1;
		}
	}
	cout << ans << "\n";

	return 0;
}
