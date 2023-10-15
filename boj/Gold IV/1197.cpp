#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"

vector<tup> g;
int V, E;
ll ans;
int p[10001];

// union find
int find(int x) {
	if (p[x] < 0)
		return x;
	return (p[x] = find(p[x]));
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
	int i, u, v, d;
	cin >> V >> E;

	for (i=0;i<E;i++) {
		cin >> u >> v >> d;
		g.push_back(tup(u, v, d));
	}

	// Krustal MST (Minimum Spanning Tree)
	fill(p, p+10001, -1);
	sort(g.begin(), g.end(), [&](const tup &lhs, const tup &rhs) {
		return get<2>(lhs) < get<2>(rhs);
	});
	vector<int> mst;
	for (tup &t : g) {
		if (mst.size() == V - 1)
			break;
		tie(u, v, d) = t;
		if (find(u) != find(v)) {
			_union(u, v);
			mst.push_back(d);
			ans += d;
		}
	}

	cout << ans << endl;
	return 0;
}
