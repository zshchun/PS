#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define DEPTH 17
int N, M;
vector<int> g[100001]; 
int p[100001][DEPTH];
int d[100001];

// Lowest Common Ancestor LCA
int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);

	for (int i=DEPTH-1;i>=0;i--) {
		if (d[u] - d[v] >= (1<<i)) {
			u = p[u][i];
		}
	}
	if (u == v) return u;

	for (int i=DEPTH-1;i>=0;i--) {
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}
	return p[u][0];
}

void dfs(int cur, int parent, int depth) {
	d[cur] = depth;
	p[cur][0] = parent;
	for (int &next : g[cur])
		if (next != parent)
			dfs(next, cur, depth+1);
}

void setup_lca() {
	for (int j=1; j < DEPTH;j++)
		for (int i=1;i<=N;i++)
			if (p[i][j-1] != 0)
				p[i][j] = p[p[i][j-1]][j-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N;
	for (i=0;i<N-1;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0, 0);
	setup_lca();

	cin >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		cout << lca(u, v) << endl;
	}
	return 0;
}
