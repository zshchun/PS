#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

vector<P> g[10001];
int max_node, max_dist, N;

void bfs(int s) {
	queue<int> q;
	int visited[10001] = {0, };
	int cur;
	visited[s] = 1;
	q.push(s);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (visited[cur] > max_dist) {
			max_node = cur;
			max_dist = visited[cur];
		}
		for (auto &p : g[cur]) {
			int next = p.first;
			int dist = p.second;
			if (!visited[next]) {
				visited[next] = visited[cur] + dist;
				q.push(next);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, w;
	cin >> N;
	for (i=1;i<N;i++) {
		cin >> u >> v >> w;
		g[u].push_back(P(v, w));
		g[v].push_back(P(u, w));
	}
	bfs(1);
	bfs(max_node);
	cout << max_dist-1 <<'\n';
	return 0;
}
