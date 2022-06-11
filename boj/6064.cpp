#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll xgcd(ll a, ll b, ll &x, ll &y) {
	ll r1=a, r2=b, q, r, s, t, s1=1, s2=0, t1=0, t2=1;
	while (r2) {
		q = r1 / r2;
		r = r1 - r2*q;
		r1 = r2;
		r2 = r;
		s = s1 - s2*q;
		s1 = s2;
		s2 = s;
		t = t1 - t2*q;
		t1 = t2;
		t2 = t;
	}
	x = s1; y = t1;
	return r1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, M, N, x, y, x1, y1, g, lcm, ans;
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		g = xgcd(M, N, x1, y1);
		if ((x-y)%g != 0) {
			cout << "-1\n";
			continue;
		}
		lcm = M * N / g;
		ans = (y-x) * x1 / g * M + x;
		ans %= lcm;
		if (ans < 0) ans += lcm;
		cout << ans << '\n';
	}

	return 0;
}
