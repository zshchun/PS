#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
#define MAX_DEPTH 17
int N, K;
vector<pa> g[100001];
int p[100001][MAX_DEPTH];
int d[100001];
bool visited[100001];
int mn[100001][MAX_DEPTH];
int mx[100001][MAX_DEPTH];

void setup() {
	for (int i=1;i<MAX_DEPTH;i++) {
		for (int j=1;j<=N;j++) {
			int pp = p[j][i-1];
			p[j][i] = p[pp][i-1];
			if (p[pp][i-1] == 0) continue;
			mn[j][i] = min(mn[pp][i-1], mn[j][i-1]);
			mx[j][i] = max(mx[pp][i-1], mx[j][i-1]);
		}
	}
}

void dfs(int cur, int depth) {
	int dist, next;
	visited[cur] = 1;
	d[cur] = depth;
	for (pa &x : g[cur]) {
		tie(next, dist) = x;
		if (visited[next]) continue;
		p[next][0] = cur;
		mx[next][0] = mn[next][0] = dist;
		dfs(next, depth+1);
	}
}

// Lowest Common Ancestor (LCA)
pa lca(int a, int b) {
	int _max = 0;
	int _min = INF;
	if (d[a] < d[b]) swap(a, b);
	for (int i=MAX_DEPTH-1;i>=0;i--) {
		if (d[a] - d[b] >= (1<<i)) {
			_max = max(_max, mx[a][i]);
			_min = min(_min, mn[a][i]);
			a = p[a][i];
		}
	}
	if (a == b) return pa(_min, _max);
	for (int i=MAX_DEPTH-1;i>=0;i--) {
		if (p[a][i] != p[b][i]) {
			_max = max({_max, mx[a][i], mx[b][i]});
			_min = min({_min, mn[a][i], mn[b][i]});
			a = p[a][i];
			b = p[b][i];
		}
	}
	_max = max({_max, mx[a][0], mx[b][0]});
	_min = min({_min, mn[a][0], mn[b][0]});
	return pa(_min, _max);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int i, j, a, b, c, d, e, ans_min, ans_max;
	fill_n(mn[0], 100001 * MAX_DEPTH, INF);

	for (i=0;i<N-1;i++) {
		cin >> a >> b >> c;
		g[a].push_back(pa(b, c));
		g[b].push_back(pa(a, c));
	}

	dfs(1, 0);
	setup();

	cin >> K;
	for (i=0;i<K;i++) {
		cin >> d >> e;
		tie(ans_min, ans_max) = lca(d, e);
		cout << ans_min << ' ' << ans_max << endl;
	}
	return 0;
}
