#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789
#define X first
#define Y second

ll N, C, ans;
vector<pa> a;
vector<tup> g;
ll p[2001];

ll distance(pa a, pa b) {
	return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

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
	ll i, j, c;
	cin >> N >> C;
	a.resize(N+1);
	a[0] = {0, 0};
	for (i=1;i<=N;i++)
		cin >> a[i].X >> a[i].Y;

	for (i=1;i<N;i++) {
		for (j=i+1;j<=N;j++) {
			c = distance(a[i], a[j]);
			if (c >= C)
				g.push_back({c, i, j});
		}
	}

	// Kruskal MST (Minimum Spanning Tree)
	fill_n(p, 2001, -1);
	sort(g.begin(), g.end());
	vector<int> mst;

	for (tup &t : g) {
		if (mst.size() == N - 1) break;
		auto [d, u, v] = t;
		if (find(u) != find(v)) {
			_union(u, v);
			mst.push_back(d);
			ans += d;
		}
	}
	if (mst.size() != N - 1)
		cout << "-1\n";
	else
		cout << ans << endl;
	return 0;
}
