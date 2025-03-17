#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, m, k;
ll v[1'000'000];
ll tree[2097152+1];

ll segment_tree(ll s, ll e, ll n) {
	if (s == e) return tree[n] = v[s];
	ll m = (s+e) / 2;
	return tree[n] = segment_tree(s, m, n*2) * segment_tree(m+1, e, n*2+1) % 1'000'000'007;
}

ll mul(ll s, ll e, ll n, ll l, ll r) {
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return tree[n];
	ll m = (s+e) / 2;
	return mul(s, m, n*2, l, r) * mul(m+1, e, n*2+1, l, r) % 1'000'000'007;
}

void update(ll s, ll e, ll n, ll idx, ll d) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[n] = v[idx] = d;
		return;
	}
	ll m = (s+e) / 2;
	update(s, m, n*2, idx, d);
	update(m+1, e, n*2+1, idx, d);
	tree[n] = tree[n*2] * tree[n*2+1] % 1'000'000'007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, a, b, c;
	cin >> n >> m >> k;
	for (i=0;i<n;i++)
		cin >> v[i];
	segment_tree(0, n-1, 1);

	for (i=0;i<m+k;i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			b--;
			update(0, n-1, 1, b, c);
		} else if (a == 2) {
			b--; c--;
			cout << mul(0, n-1, 1, b, c) << endl;
		}
	}
	
	return 0;
}
