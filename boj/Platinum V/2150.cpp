#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int V, E, cnt;
using ve = vector<int>;
stack<int> st;
bool used[10001];
int low[10001];
int visited[10001];
vector<int> g[10001];
vector<ve> ans;

// tarjan SCC (Strongly Connected Component)
void dfs(int u) {
	visited[u] = low[u] = ++cnt;
	st.push(u);
	used[u] = 1;

	for (int &v : g[u]) {
		if (!visited[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (used[v]) {
			low[u] = min(low[u], visited[v]);
		}
	}
	if (low[u] == visited[u]) {
		ve scc;
		while (!st.empty()) {
			int cur = st.top();
			st.pop();
			used[cur] = 0;
			scc.push_back(cur);
			if (u == cur) break;
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, u, v;
	cin >> V >> E;
	for (i=0;i<E;i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}

	for (i=1;i<=V;i++)
		if (!visited[i])
			dfs(i);

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (ve &e : ans) {
		for (int &x : e)
			cout << x << ' ';
		cout << "-1\n";
	}
	return 0;
}
