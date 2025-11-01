#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[100001];
int tree[524289];
int pos[100001];

int query(int s, int e, int n, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r)
		return tree[n];
	int m = (s+e)/2;
	return query(s, m, n*2, l, r) + query(m+1, e, n*2+1, l, r);
}

void update(int s, int e, int n, int idx, int d) {
	if (idx < s || e < idx) return;
	tree[n] += d;
	if (s == e) return;
	int m = (s+e)/2;
	update(s, m, n*2, idx, d);
	update(m+1, e, n*2+1, idx, d);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, n, m, v;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		memset(tree, 0, sizeof(tree));
		for (i=0;i<n;i++) {
			pos[i] = n-1-i;
			update(0, n+m-1, 1, i, 1);
		}

		for (i=0;i<m;i++) {
			cin >> v;
			v--;
			cout << query(0, n+m-1, 1, pos[v], n+m-1)-1 << ' ';
			update(0, n+m-1, 1, pos[v], -1);
			update(0, n+m-1, 1, n+i, 1);
			pos[v] = n + i;
		}
		cout << endl;
	}
	return 0;
}
