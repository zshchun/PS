#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int m, n, ans;
vector<tup> g;
int p[200001];

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
	int u, v, d, i;
	while (1) {
		cin >> m >> n;
		if (!m && !n) break;
		ans = 0;
		g.clear();
		fill_n(p, 200001, -1);

		for (i=0;i<n;i++) {
			cin >> u >> v >> d;
			g.push_back(tup(d, u, v));
			ans += d;
		}
		// Kruskal MST (Minimum Spanning Tree)
		sort(g.begin(), g.end());
		for (tup &t : g) {
			auto [x, y, z] = t;
			if (find(y) != find(z)) {
				_union(y, z);
				ans -= x;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
