#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m, cnt, scc;
vector<vector<int>> g;
stack<int> st;
int visited[2001];
int low[2001];
int sccid[2001];
bool used[2001];

// Tarjan SCC (Strongly Connected Component)
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
		scc++;
		while (!st.empty()) {
			int cur = st.top();
			st.pop();
			used[cur] = 0;
			sccid[cur] = scc;
			if (u == cur) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, i;
	while (cin >> n >> m) {
		g.clear();
		g.resize(2001);
		st = stack<int>();
		scc = cnt = 0;
		memset(low, 0, sizeof(low));
		memset(visited, 0, sizeof(visited));
		memset(sccid, 0, sizeof(sccid));
		memset(used, 0, sizeof(used));
		for (i=0;i<m;i++) {
			cin >> a >> b;
			a = a > 0 ? (a-1)*2 : (~a)*2+1;
			b = b > 0 ? (b-1)*2 : (~b)*2+1;
			g[a^1].push_back(b);
			g[b^1].push_back(a);
		}
		g[1].push_back(0);

		for (i=0;i<n*2;i++)
			if (!visited[i])
				dfs(i);
		for (i=0;i<n;i++)
			if (sccid[i*2] == sccid[i*2+1])
				break;

		if (i == n)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
