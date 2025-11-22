#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 700000
int N, M, S, D;

vector<int> bt[501];
vector<pa> g[501];
int dist[501];

void dijkstra() {
	for (int i=0;i<N;i++)
		dist[i] = INF;
	priority_queue<pa, vector<pa>, greater<pa>> pq;
	pq.push(pa(0, S));
	dist[S] = 0;
	int cur_dist, cur;
	while (!pq.empty()) {
		tie(cur_dist, cur) = pq.top();
		pq.pop();
		for (auto [next, next_dist] : g[cur]) {
			if (dist[next] > cur_dist + next_dist) {
				dist[next] = cur_dist + next_dist;
				pq.push(pa(dist[next], next));
				bt[next].clear();
				bt[next].push_back(cur);
			} else if (dist[next] == cur_dist + next_dist) {
				bt[next].push_back(cur);
			}
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(D);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		while (!bt[cur].empty()) {
			int prev = bt[cur].back();
			bt[cur].pop_back();
			for (auto it=g[prev].begin();it != g[prev].end();) {
				if ((*it).first == cur) {
					q.push(prev);
					it = g[prev].erase(it);
					break;
				} else {
					it++;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, p;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> D;
		for (i=0;i<N;i++) {
			g[i].clear();
			bt[i].clear();
		}

		for (i=0;i<M;i++) {
			cin >> u >> v >> p;
			g[u].push_back(pa(v, p));
		}
		dijkstra();
		bfs();
		dijkstra();
		if (dist[D] == INF)
			cout << "-1\n";
		else
			cout << dist[D] << endl;
	}

	return 0;
}
