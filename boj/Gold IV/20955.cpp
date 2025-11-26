#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int p[100001];
vector<pa> g[100001];
vector<pa> a;
int N, M, ans, mst;

// union-find
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
	int i, u, v;
	cin >> N >> M;

	fill_n(p, 100001, -1);
	for (i=0;i<M;i++) {
		cin >> u >> v;
		u--; v--;
		a.push_back(pa(u, v));
		_union(u, v);
	}

	for (i=0;i<M;i++) {
		tie(u, v) = a[i];
		int q = find(u);
		g[q].push_back(pa(u, v));
	}

	set<int> grp;
	for (i=0;i<N;i++)
		grp.insert(find(i));

	for (int root : grp) {
		mst = 0;
		fill_n(p, 100001, -1);
		// Kruskal MST, Minimum Spanning Tree
		for (auto &[u, v] : g[root]) {
			if (mst == N - 1)
				break;
			if (find(u) != find(v)) {
				_union(u, v);
				mst++;
			}
		}
		ans += g[root].size() - mst;
	}

	cout << ans + grp.size() - 1 << endl;
	return 0;
}
