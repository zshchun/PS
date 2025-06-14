#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M, R;
vector<int> g[100001];
int visited[100001];
void dfs(int s, int d) {
	if (visited[s] >= 0) return;
	visited[s] = d;
	sort(g[s].begin(), g[s].end(), greater<int>());
	for (int &x : g[s])
		dfs(x, d+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> N >> M >> R;
	fill_n(visited, 100001, -1);
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(R, 0);
	for (i=1;i<=N;i++)
		cout << visited[i] << endl;
	return 0;
}
