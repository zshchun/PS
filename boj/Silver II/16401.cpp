#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll M, N;
ll a[1000001];
ll b[1000001];

bool check(ll x) {
	ll j = 0;
	for (ll i=0;i<M;i++) {
		if (b[j] < x)
			j++;
		if (j >= N || b[j] < x)
			return false;
		b[j] -= x;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, x, l, r, m, ans = 0;
	cin >> M >> N;
	r = 0;
	for (i=0;i<N;i++)
		cin >> a[i];

	sort(a, a+N, greater<ll>());

	l = 0;
	r = a[0];

	while (l <= r) {
		m = (l + r) / 2;
		memcpy(b, a, sizeof(ll) * N);
		if (check(m)) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << r << endl;
	return 0;
}
