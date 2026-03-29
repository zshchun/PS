#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define endl "\n"
#define INF 12345678901234567LL
ll N, M, A, B, C, ans = INF;
vector<pl> g[100001];
ll visited[100001];

bool dijkstra(ll m) {
	fill_n(visited, N+1, INF);
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	pq.push(pl(0, A));
	visited[A] = 0;
	while (!pq.empty()) {
		auto [cost, cur] = pq.top();
		pq.pop();
		if (cost > visited[cur]) continue;
		for (auto [ncost, next] : g[cur]) {
			if (ncost > m) break;
			if (cost + ncost > C) continue;
			if (visited[next] <= cost + ncost) continue;
			visited[next] = cost + ncost;
			pq.push(pl(visited[next], next));
		}
	}
	if (visited[B] == INF)
		return false;
	ans = min(ans, m);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll u, v, i, c, l = INF, r = 0, m;
	cin >> N >> M >> A >> B >> C;
	for (i=0;i<M;i++) {
		cin >> u >> v >> c;
		g[u].push_back(pl(c, v));
		g[v].push_back(pl(c, u));
		l = min(l, c);
		r = max(r, c);
	}
	for (i=1;i<=N;i++)
		sort(g[i].begin(), g[i].end());

	// parametric search, binary search
	while(l <= r) {
		m = (l + r) / 2;
		if (dijkstra(m) == true)
			r = m - 1;
		else
			l = m + 1;
	}
	
	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;
	return 0;
}
