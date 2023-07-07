#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int, int,int> tup;
#define endl "\n"
#define INF 123456789
int N, M;
vector<tup> g;
int p[100001];

int find(int x) {
	if (p[x] < 0)
		return x;
	p[x] = find(p[x]);
	return p[x];
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
	int u, v, d, i, ans = 0;
	vector<int> mst;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> u >> v >> d;
		g.push_back(tup(u, v, d));
	}

	sort(g.begin(), g.end(), [&](const tup &lhs, const tup &rhs) {
		return get<2>(lhs) < get<2>(rhs);
	});

	fill(p, p+N+1, -1);

	// kruskal, MST
	for (tup t : g) {
		if (mst.size() == N - 1)
			break;
		tie(u, v, d) = t;
		if (find(u) != find(v)) {
			_union(u, v);
			mst.push_back(d);
			ans += d;
		}
	}

	cout << ans - mst.back() << endl;
	return 0;
}
