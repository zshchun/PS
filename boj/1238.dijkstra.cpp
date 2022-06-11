#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define INF 1234567891

vector<pa> m1[1001];
vector<pa> m2[1001];
int dist1[1001];
int dist2[1001];
bool visited[1001];
void dijkstra(vector<pa> (&m)[], int (&d)[], int x) {
	int cur, cur_dist;
	fill(d, d+1001, INF);
	fill(visited, visited+1001, 0);
	d[x] = 0;
	priority_queue<pa, vector<pa>, greater<pa> > pq;
	pq.push(pa(0, x));
	while (!pq.empty()) {
		tie(cur_dist, cur) = pq.top();
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto &p : m[cur]) {
			int next = p.first;
			int dist = p.second;
			if (d[next] > cur_dist + dist) {
				d[next] = cur_dist + dist;
				pq.push(pa(d[next], next));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, X, i, u, v, t;
	cin >> N >> M >> X;
	for (i=0;i<M;i++) {
		cin >> u >> v >> t;
		m1[u].push_back(pa(v, t));
		m2[v].push_back(pa(u, t));
	}
	dijkstra(m1, dist1, X);
	dijkstra(m2, dist2, X);

	int ans = 0;
	for (i=1;i<=N;i++) {
		ans = max(ans, dist1[i]+dist2[i]);
	}
	cout << ans << '\n';

	return 0;
}
