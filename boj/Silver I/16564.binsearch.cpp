#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[1000001];
ll n, k;

ll solve(ll x) {
	ll ret = 0;
	for (ll i=0;i<n;i++) {
		if (a[i] > x) break;
		ret += x - a[i];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, l, r, m;
	cin >> n >> k;
	for (i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);

	l = 0;
	r = 2'000'000'000;

	while (l <= r) {
		m = (l + r) / 2;

		if (solve(m) > k) {
			r = m - 1;
		} else {
			l = m + 1;
		}

	}
	cout << r << endl;

	return 0;
}
