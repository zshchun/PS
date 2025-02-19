#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890123ULL
ll N, M;
ll m[100001];
ll d[100001];
vector<pa> g[100001];

void dijkstra() {
	ll cur, cur_dist;
	fill_n(d, 100001, INF);
	priority_queue<pa, vector<pa>, greater<pa>> pq;
	pq.push(pa(0, 0));
	d[0] = 0;

	while (!pq.empty()) {
		tie(cur, cur_dist) = pq.top();
		pq.pop();
		if (d[cur] < cur_dist) continue;
		for (pa &x : g[cur]) {
			ll next = x.first;
			ll dist = x.second;
			if (d[next] > cur_dist + dist) {
				d[next] = cur_dist + dist;
				pq.push(pa(next, d[next]));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, a, b, t;
	cin >> N >> M;

	for (i=0;i<N;i++)
		cin >> m[i];

	m[N-1] = 0;
	for (i=0;i<M;i++) {
		cin >> a >> b >> t;
		if (m[b] || m[a]) continue;
		g[a].push_back(pa(b, t));
		g[b].push_back(pa(a, t));
	}

	dijkstra();

	if (d[N-1] == INF)
		cout << "-1\n";
	else
		cout << d[N-1] << endl;

	return 0;
}
