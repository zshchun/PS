#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;

vector<pa> g[20001];
int d[20001];
bool visited[20001];
#define INF 123456789
void dijkstra(int s) {
	priority_queue<pa, vector<pa>, greater<pa> > pq;
	fill(d, d+20001, INF);
	d[s] = 0;
	pq.push(pa(0, s));
	int cur_dist, cur_node;
	while (!pq.empty()) {
		tie(cur_dist, cur_node) = pq.top();
		pq.pop();
		if (visited[cur_node]) continue;
		visited[cur_node] = 1;
		for (auto &p : g[cur_node]) {
			int dist = p.first;
			int next = p.second;
			if (d[next] > d[cur_node] + dist) {
				d[next] = d[cur_node] + dist;
				pq.push(pa(d[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int V, E, i, s, u, v, w;
	cin >> V >> E;
	cin >> s;
	for (i=0;i<E;i++) {
		cin >> u >> v >> w;
		g[u].push_back(pa(w, v));
	}
	dijkstra(s);
	for (i=1;i<=V;i++) {
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}
	return 0;
}

