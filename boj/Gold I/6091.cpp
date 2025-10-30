#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;

#define endl "\n"
#define INF 123456789
int n;
int p[1025];
vector<tup> g;
vector<int> ans[1025];
vector<int> mst;

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
	int i, j, x, a, b, c;
	cin >> n;
	fill_n(p, 1025, -1);
	for (i=0;i<n-1;i++) {
		for (j=i+1;j<n;j++) {
			cin >> x;
			g.push_back(tup(x, i, j));
		}
	}

	// Kruskal MST, Minimum Spanning Tree
	sort(g.begin(), g.end());
	for (tup &t : g) {
		if (mst.size() == n - 1) break;
		tie(c, a, b) = t;
		if (find(a) != find(b)) {
			_union(a, b);
			mst.push_back(c);
			ans[a].push_back(b);
			ans[b].push_back(a);
		}
	}

	for (i=0;i<n;i++) {
		cout << ans[i].size() << ' ';
		sort(ans[i].begin(), ans[i].end());
		for (int v : ans[i])
			cout << v+1 << ' ';
		cout << endl;
	}
	return 0;
}
