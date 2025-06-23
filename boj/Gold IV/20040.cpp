#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
int p[500001];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void _union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, ans = 0;
	cin >> n >> m;
	fill_n(p, 500001, -1);
	for (i=1;i<=m;i++) {
		cin >> u >> v;
		if (find(u) == find(v)) {
			ans = i;
			break;
		}
		_union(u, v);
	}
	cout << ans << endl;
	return 0;
}
