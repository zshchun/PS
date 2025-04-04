#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll s, c, ans;
ll a[1000001];

ll check(ll x) {
	ll ret = 0;
	for (ll i=0;i<s;i++)
		ret += a[i] / x;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, l, r, m, sum = 0;
	cin >> s >> c;
	for (i=0;i<s;i++) {
		cin >> a[i];
		sum += a[i];
	}

	l = 1;
	r = sum;
	// binary search
	while (l <= r) {
		m = (l+r) / 2;
		if (check(m) >= c)
			l = m + 1;
		else
			r = m - 1;
	}

	cout << sum - (r * c) << endl;

	return 0;
}
