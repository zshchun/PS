#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int V, E, cnt;
vector<int> g[10001];
int visited[10001];
int low[10001];
set<int> ans;

void dfs(int u, bool root) {
	visited[u] = low[u] = ++cnt;
	int child = 0;

	for (int &v : g[u]) {
		if (visited[v]) {
			low[u] = min(low[u], visited[v]);
			continue;
		}
		child++;
		dfs(v, false);
		low[u] = min(low[u], low[v]);
		if (!root && low[v] >= visited[u])
			ans.insert(u);
	}
	if (root && child >= 2)
		ans.insert(u);
}

// Articulation points
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> V >> E;
	for (i=0;i<E;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (i=1;i<=V;i++)
		if (!visited[i])
			dfs(i, true);

	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << ' ';
	cout << endl;

	return 0;
}
