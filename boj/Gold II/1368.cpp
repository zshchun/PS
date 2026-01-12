#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789
int N, W, ans;
int a[301];
int w[301][301];
int p[302];
vector<tup> g;

// Kruskal MST
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
	int i, j, k, v, mn = INF;
	cin >> N;
	fill_n(p, 302, -1);
	for (i=0;i<N;i++) {
		cin >> w[i][i];
		mn = min(mn, w[i][i]);
	}
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			if (i == j) {
				cin >> v;
				g.push_back(tup(w[i][j], i, 301));
			} else {
				cin >> w[i][j];
				g.push_back(tup(w[i][j], i, j));
			}
		}
	}
	sort(g.begin(), g.end());
	vector<int> mst;
	for (tup &t : g) {
		if (mst.size() == N) break;
		auto &[d, y, x] = t;
		if (find(y) != find(x)) {
			_union(y, x);
			ans += d;
			mst.push_back(d);
		}
	}
	cout << ans << endl;
	return 0;
}
