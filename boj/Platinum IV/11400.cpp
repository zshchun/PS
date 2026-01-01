#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int V, E, cnt;
set<pa> ans;
vector<int> g[100001];
int visited[100001];
int low[100001];

// Articulation bridge
void dfs(int u, int p) {
	visited[u] = low[u] = ++cnt;
	int child = 0;

	for (int &v : g[u]) {
		if (v == p) continue;
		if (visited[v]) {
			low[u] = min(low[u], visited[v]);
			continue;
		}
		child++;
		dfs(v, u);
		low[u] = min(low[u], low[v]);
		if (low[v] > visited[u])
			if (u < v)
				ans.insert(pa(u, v));
			else
				ans.insert(pa(v, u));
	}
}

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
			dfs(i, i);
	cout << ans.size() << endl;
	for (pa p : ans)
		cout << p.first << ' ' << p.second << endl;

	return 0;
}
