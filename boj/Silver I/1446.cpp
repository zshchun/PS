#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, d;
vector<pa> g[10001];
int visited[10001];

void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur > d) continue;
		for (pa &p : g[cur]) {
			int next = p.first;
			int dist = p.second;
			if (visited[next] > visited[cur]+dist) {
				visited[next] = visited[cur]+dist;
				q.push(next);
			}

		}
		if (visited[cur+1] > visited[cur] + 1) {
			visited[cur+1] = visited[cur]+1;
			q.push(cur+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, x;
	cin >> n >> d;
	fill_n(visited, 10001, INF);
	for (i=0;i<n;i++) {
		cin >> u >> v >> x;
		g[u].push_back(pa(v, x));
	}

	bfs();
	cout << visited[d] << endl;

	return 0;
}
