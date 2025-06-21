#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[10001];
ll M, N;

ll get_sum(ll mx) {
	ll ret = 0;
	for (ll i=0;i<N;i++)
		ret += min(mx, a[i]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, l = 0, r = 0, m;
	cin >> N;
	for (i=0;i<N;i++) {
		cin >> a[i];
		r = max(a[i], r);
	}
	cin >> M;

	// binary search
	while (l <= r) {
		m = (l + r) / 2;
		if (get_sum(m) <= M) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}

	cout << r << endl;

	return 0;
}
