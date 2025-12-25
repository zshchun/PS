#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[1000001];
int b[1000001];
ll tree[500001*4];
ll N, ans;

// Segment tree, Inversion counting
void update(ll s, ll e, ll n, ll idx, ll d) {
	if (idx < s || e < idx) return;
	tree[n] += d;
	if (s == e) return;
	ll m = (s+e) / 2;
	update(s, m, n*2, idx, d);
	update(m+1, e, n*2+1, idx, d);
}

ll sum(ll s, ll e, ll n, ll l, ll r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[n];
	ll m = (s+e) / 2;
	return sum(s, m, n*2, l, r) + sum(m+1, e, n*2+1, l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, v;
	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];
	for (i=0;i<N;i++) {
		cin >> v;
		b[v] = i;
	}
	for (i=0;i<N;i++) {
		j = b[a[i]];
		ans += sum(0, N-1, 1, j, N-1);
		update(0, N-1, 1, j, 1);
	}
	cout << ans << endl;
	return 0;
}
