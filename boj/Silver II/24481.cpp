#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, m, r;
int visited[100001];
vector<int> g[100001];

void dfs(int cur, int l) {
	if (visited[cur] > -1) {
		return;
	}
	visited[cur] = l;
	for (int &next : g[cur])
		dfs(next, l+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> n >> m >> r;

	fill_n(visited, 100001, -1);
	for (i=0;i<m;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (i=1;i<=n;i++)
		sort(g[i].begin(), g[i].end());

	dfs(r, 0);
	for (i=1;i<=n;i++)
		cout << visited[i] << endl;
	return 0;
}
