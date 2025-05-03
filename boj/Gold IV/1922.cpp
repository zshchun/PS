#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789

int N, M, ans;
int p[1001];
vector<tup> g;

int find(int x) {
	if (p[x] < 0)
		return x;
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
	int i, a, b, c;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> a >> b >> c;
		a--; b--;
		if (a == b) continue;
		g.push_back(tup(c, a, b));
	}

	// Kruskal MST (Minimum Spanning Tree)
	fill_n(&p[0], 1001, -1);
	sort(g.begin(), g.end());
	vector<int> mst;

	for (tup &t : g) {
		if (mst.size() == N - 1) break;
		tie(c, a, b) = t;
		if (find(a) != find(b)) {
			_union(a, b);
			mst.push_back(c);
			ans += c;
		}
	}

	cout << ans << endl;
	return 0;
}
