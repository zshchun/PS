#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;

#define INF 1234567891
vector<pa> g[801];
ll d[801];
void dijkstra(ll s) {
	priority_queue<pa, vector<pa>, greater<pa> > q;
	ll cur, cur_dist;
	bool visited[801] = {0, };
	fill(d, d+801, INF);
	q.push(pa(0, s));
	d[s] = 0;
	while (!q.empty()) {
		tie(cur_dist, cur) = q.top();
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto &p : g[cur]) {
			ll dist, next;
			tie(dist, next) = p;
			if (d[next] > cur_dist+dist) {
				d[next] = cur_dist + dist;
				q.push(pa(d[next], next));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, E, i, u, v, w, v1, v2;
	cin >> N >> E;
	for (i=0;i<E;i++) {
		cin >> u >> v >> w;
		g[u].push_back(pa(w, v));
		g[v].push_back(pa(w, u));
	}
	cin >> v1 >> v2;
	ll ans1, ans2;
	dijkstra(1);
	ans1 = d[v1];
	ans2 = d[v2];
	dijkstra(v1);
	ans1 += d[v2];
	ans2 += d[v2];
	dijkstra(N);
	ans1 += d[v2];
	ans2 += d[v1];
	ll ans = min(ans1, ans2);
	if (ans < INF)
		cout << ans << '\n';
	else
		cout << "-1\n";
	return 0;
}

