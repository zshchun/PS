#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789012ULL
ll V, E, P;
vector<pa> g[5001];
ll visited[5001][2];

void bfs() {
	ll cur, cur_dist, mj, dist, next;
	queue<tup> q;
	q.push(tup(1, 0, 0));
	visited[1][0] = 0;
	while (!q.empty()) {
		tie(cur, cur_dist, mj) = q.front();
		q.pop();

		for (pa &p : g[cur]) {
			tie(next, dist) = p;

			if (visited[next][mj] > cur_dist + dist) {
				visited[next][mj] = cur_dist + dist;
				q.push(tup(next, visited[next][mj], mj));
			}
			if (cur == P && visited[next][1] > cur_dist + dist) {
				visited[next][1] = cur_dist + dist;
				q.push(tup(next, visited[next][1], 1));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll i, j, u, v, d;
	cin >> V >> E >> P;
	fill_n(&visited[0][0], 5001 * 2, INF);

	for (i=0;i<E;i++) {
		cin >> u >> v >> d;
		g[u].push_back(pa(v, d));
		g[v].push_back(pa(u, d));
	}

	bfs();
	if (visited[V][1] <= visited[V][0] && visited[V][1] != INF)
		cout << "SAVE HIM\n";
	else
		cout << "GOOD BYE\n";

	return 0;
}
