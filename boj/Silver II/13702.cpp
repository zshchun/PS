#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, K, ans;
ll a[10001];

ll calculate(int m) {
	ll ret = 0;
	if (m == 0)
		return 0;
	for (int i=0;i<N;i++) {
		ret += a[i] / m;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, l, r, m, mx = 0;
	cin >> N >> K;

	for (i=0;i<N;i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	
	l = 1;
	r = mx;
	while (l <= r) {
		m = (l + r) / 2;
		if (calculate(m) < K) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << r << endl;

	return 0;
}
