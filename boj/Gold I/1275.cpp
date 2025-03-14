#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, q;
ll v[100001];
ll tree[262144 + 1];

ll segment_tree(int s, int e, int n) {
	if (s == e)
		return tree[n] = v[s];
	int m = (s + e) / 2;
	return tree[n] = segment_tree(s, m, n*2) + segment_tree(m+1, e, n*2+1);
}

ll sum(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r)
		return tree[n];
	int m = (s + e) / 2;
	return sum(s, m, n*2, l, r) + sum(m+1, e, n*2+1, l, r);
}

void update(int s, int e, int n, int idx, ll d) {
	if (idx < s || e < idx) return;
	tree[n] += d;
	if (s == e) return;
	int m = (s + e) / 2;
	update(s, m, n*2, idx, d);
	update(m+1, e, n*2+1, idx, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, x, y, a, b;
	cin >> n >> q;
	for (i=0;i<n;i++)
		cin >> v[i];

	segment_tree(0, n-1, 1);

	for (i=0;i<q;i++) {
		cin >> x >> y >> a >> b;
		x--; y--; a--;
		if (x > y) swap(x, y);
		cout << sum(0, n-1, 1, x, y) << endl;
		update(0, n-1, 1, a, b - v[a]);
		v[a] = b;
	}

	return 0;
}
