#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M;
#define MAX_DEPTH 16
vector<pa> g[40001];
int p[40001][MAX_DEPTH];
int len[40001][MAX_DEPTH];
int d[40001]; // depth
bool visited[40001];

// Lowest Common Ancestor
int lca(int a, int b) {
	int ret = 0;
	if (d[a] < d[b]) swap(a, b);

	for (int i=MAX_DEPTH-1;i>=0; i--) {
		if (d[a] - d[b] >= (1<<i)) {
			ret += len[a][i];
			a = p[a][i];
		}
	}
	if (a == b) return ret;

	for (int i=MAX_DEPTH-1;i>=0; i--) {
		if (p[a][i] != p[b][i]) {
			ret += len[a][i] + len[b][i];
			a = p[a][i];
			b = p[b][i];
		}
	}
	ret += len[a][0] + len[b][0];
	return ret;
}

void dfs(int cur, int depth) {
	int dist, next;
	visited[cur] = 1;
	d[cur] = depth;
	for (pa &x : g[cur]) {
		tie(next, dist) = x;
		if (visited[next]) continue;
		p[next][0] = cur;
		len[next][0] = dist;
		dfs(next, depth+1);
	}
}

void setup() {
	for (int i=1;i<MAX_DEPTH;i++) {
		for (int j=1;j<=N;j++) {
			int pp = p[j][i-1];
			p[j][i] = p[pp][i-1];
			if (p[pp][i-1] != 0)
				len[j][i] = len[j][i-1] + len[pp][i-1];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, x;
	cin >> N;
	for (i=0;i<N-1;i++) {
		cin >> u >> v >> x;
		g[u].push_back(pa(v, x));
		g[v].push_back(pa(u, x));
	}

	dfs(1, 0);
	setup();

	cin >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		cout << lca(u, v) << endl;
	}
	return 0;
}
