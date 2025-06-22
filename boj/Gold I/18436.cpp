#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, M;
ll a[100001];
ll tree[262145]; // odd count

ll segment_tree(ll s, ll e, ll n) {
	if (s == e) return tree[n] = a[s] & 1;
	ll m = (s + e) / 2;
	return tree[n] = segment_tree(s, m, n*2) + segment_tree(m+1, e, n*2+1);
}

ll query(ll s, ll e, ll n, ll l, ll r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[n];
	ll m = (s + e) / 2;
	return query(s, m, n*2, l, r) + query(m+1, e, n*2+1, l, r);
}

void update(ll s, ll e, ll n, ll idx, ll d, ll orig) {
	if (idx < s || e < idx) return;
	tree[n] += (d & 1) - (orig & 1);
	if (s == e) return;
	ll m = (s + e) / 2;
	update(s, m, n*2, idx, d, orig);
	update(m+1, e, n*2+1, idx, d, orig);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, x, y, z;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];
	
	segment_tree(0, N-1, 1);

	cin >> M;
	for (i=0;i<M;i++) {
		cin >> x >> y >> z;
		if (x == 1) {
			y--;
			update(0, N-1, 1, y, z, a[y]);
			a[y] = z;
		} else if (x == 2) {
			y--; z--;
			cout << (z - y + 1) - query(0, N-1, 1, y, z) << endl;
		} else if (x == 3) {
			y--; z--;
			cout << query(0, N-1, 1, y, z) << endl;
		}
	}

	return 0;
}
