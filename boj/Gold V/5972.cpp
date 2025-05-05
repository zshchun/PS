#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
#define INF 123456789

int N, M;
vector<pa> g[50001];
int d[50001];

void dijkstra() {
	int next, dist;
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(1);
	fill_n(d, N+1, INF);
	d[1] = 0;

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		for (pa &p : g[cur]) {
			tie(next, dist) = p;

			if (d[next] > d[cur] + dist) {
				d[next] = d[cur] + dist;
				pq.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v, x;
	cin >> N >> M;
	for (i=0;i<M;i++) {
		cin >> u >> v >> x;
		g[u].push_back(pa(v, x));
		g[v].push_back(pa(u, x));
	}

	dijkstra();
	cout << d[N] << endl;

	return 0;
}
