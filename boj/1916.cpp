#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define INF 123456789
vector<P> g[1001];
int d[1001], N;
bool visited[1001];
void dijkstra(int s) {
	int cur, cur_dist;
	priority_queue<P, vector<P>, greater<P> > pq;
	fill(d, d+N+1, INF);
	d[s] = 0;
	pq.push(P(0, s));
	while (!pq.empty()) {
		tie(cur_dist, cur) = pq.top();
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto &p : g[cur]) {
			int next = p.second;
			int next_dist = p.first;
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
	int M, u, v, w, s, e, i;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v >> w;
		g[u].push_back(P(w, v));
	}
	cin >> s >> e;
	dijkstra(s);
	cout << d[e] << '\n';

	return 0;
}

