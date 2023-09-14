#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789
int N, M;
int dist[1001][1001];
vector<int> t[1001];
int visited[1001];

int bfs(int from, int to) {
	queue<int> q;
	q.push(from);
	visited[from] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int &next : t[cur]) {
			if (visited[next])
				continue;
			visited[next] = visited[cur] + dist[cur][next];
			if (next == to)
				return visited[next] - 1;
			q.push(next);
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int i, u, v, d, ans;
	for (i=0;i<N-1;i++) {
		cin >> u >> v >> d;
		t[u].push_back(v);
		t[v].push_back(u);
		dist[u][v] = d;
		dist[v][u] = d;
	}
	for (i=0;i<M;i++) {
		cin >> u >> v;
		ans = bfs(u, v);
		cout << ans << endl;
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}
