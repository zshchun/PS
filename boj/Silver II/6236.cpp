#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, M;
ll a[100001];

ll check(ll k) {
	ll i, j, sum = 0;
	for (i=0,j=0;i<N;i++) {
		if (a[i] > k)
			return M + 1;
		if (sum < a[i]) {
			sum = k;
			j++;
		}
		sum -= a[i];
	}
	return j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, l, m, r = 0, ans;
	cin >> N >> M;

	for (i=0;i<N;i++) {
		cin >> a[i];
		r += a[i];
	}
	// binary search
	l = 1;
	
	while (l <= r) {
		m = (l + r) / 2;
		ll ret = check(m);
		if (ret > M) {
			l = m + 1;
		} else {
			ans = m;
			r = m - 1;
		}
	}
	cout << ans << endl;

	return 0;
}
