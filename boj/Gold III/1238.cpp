#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> g[1001];
int visited[1001];
int dist, node, N;

int bfs(int from, int to) {
	queue<int> q;
	q.push(from);
	visited[from] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i=0;i<(int)g[v].size();i++) {
			int x = g[v][i].first;
			int y = g[v][i].second;
			if (visited[x] && visited[x] <= visited[v]+y) continue;
			visited[x] = visited[v] + y;
			q.push(x);
		}
	}
	return visited[to] - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int M, X, i, a, b, t;
	cin >> N >> M >> X;
	for (i=1;i<=M;i++) {
		cin >> a >> b >> t;
		g[a].emplace_back(pair<int,int>(b, t));
	}
	int ans = 0;
	for (i=1;i<=N;i++) {
		memset(visited, 0, sizeof(visited));
		int home_to_party = bfs(i, X);
		memset(visited, 0, sizeof(visited));
		int party_to_home = bfs(X, i);
		ans = max(ans, home_to_party+party_to_home);
	}
	cout << ans << '\n';
	return 0;
}
