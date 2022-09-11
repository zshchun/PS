#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;

#define INF 123456789

bool visited[1001];
int d[1001];
int N, M, start, target;
vector<P> g[1001];
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > pq;
	fill_n(d, 1001, INF);
	d[s] = 0;
	pq.push(P(0, s));
	while (!pq.empty()) {
		P p = pq.top();
		pq.pop();
		int cur = p.second;
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto &n : g[cur]) {
			int next_dist = n.first;
			int next = n.second;
			if (d[next] > d[cur] + next_dist) {
				d[next] = d[cur] + next_dist;
				pq.push(P(d[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int u, v, x, i;
	for (i=0;i<M;i++) {
		cin >> u >> v >> x;
		g[u].push_back(P(x, v));
	}
	cin >> start >> target;
	dijkstra(start);
	cout << d[target] << '\n';

	return 0;
}
