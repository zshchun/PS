#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
vector<pa> g[801];
#define INF 99999

int d1[801];
int d2[801];

void dijkstra(int *d, int s) {
	int cur_dist, cur_node;
	priority_queue<pa, vector<pa>, greater<pa> > pq;
	pq.push(pa(0, s));
	fill(d, d+801, INF);
	d[s] = 0;
	bool visited[801] = {0, };
	while (!pq.empty()) {
		tie(cur_dist, cur_node) = pq.top();
		pq.pop();
		if (visited[cur_node]) continue;
		visited[cur_node] = 1;
		for (auto &p : g[cur_node]) {
			int dist = p.first;
			int next = p.second;
			if (d[next] > cur_dist+dist) {
				d[next] = cur_dist + dist;
				pq.push(pa(d[next], next));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, E, u, v, w, v1, v2;
	cin >> N >> E;
	for (int i=0;i<E;i++) {
		cin >> u >> v >> w;
		g[u].push_back(pa(w, v));
		g[v].push_back(pa(w, u));
	}
	cin >> v1 >> v2;
	dijkstra(d1, v1);
	dijkstra(d2, v2);
	int ans = min(d1[1]+d1[v2]+d2[N], d2[1]+d2[v1]+d1[N]);
	if (ans < INF)
		cout << ans << '\n';
	else
		cout << "-1\n";
	return 0;
}

