#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, u, v, x;
	queue<int> q;
	cin >> n >> m;
	vector<int> g[n+1];
	int *visited = new int[n+1];
	vector<pair<int,int>> ans;
	for (i=1;i<=m;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (i=1;i<=n;i++) {
		memset(visited, 0, sizeof(int)*(n+1));
		q.push(i);
		visited[i] = 1;
		while (!q.empty()) {
			x = q.front();
			q.pop();
			for (vector<int>::iterator it = g[x].begin(); it != g[x].end(); ++it) {
				if (visited[*it]) continue;
				q.push(*it);
				visited[*it] = visited[x] + 1;
			}
		}
		ans.push_back(pair<int,int>(i, accumulate(visited, visited+n+1, 0)));
	}
	sort(ans.begin(), ans.end(), [](const auto& lhs, const auto& rhs) {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		else
			return lhs.second < rhs.second;
	});
	cout << ans[0].first << '\n';

	return 0;
}
