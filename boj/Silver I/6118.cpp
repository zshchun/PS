#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
vector<int> g[20001];
int visited[20001];
int dist[20001];
int N, M;

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : g[cur]) {
			if (visited[next] <= visited[cur] + 1)
				continue;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, ans = 0, start;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (i=1;i<=N;i++)
		visited[i] = INF;
	bfs();
	for (i=1;i<=N;i++) {
		int d = visited[i];
		if (d == INF)
			continue;
		if (ans < d) {
			ans = d;
			start = i;
		}
		dist[d]++;
	}
	cout << start << ' ' << ans << ' ' << dist[ans] << endl;

	return 0;
}
