#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789012345ull
ll n, m, k, ans, city;
vector<pa> g[100001];
vector<int> a;
ll d[100001];

void dijkstra() {
	ll cur, cur_dist;
	priority_queue<pa, vector<pa>, greater<pa>> pq;
	for (int &s : a) {
		pq.push(pa(0, s));
		d[s] = 0;
	}

	while (!pq.empty()) {
		tie(cur_dist, cur) = pq.top();
		pq.pop();
		if (d[cur] < cur_dist) continue;
		for (auto &[next, dist] : g[cur]) {
			if (cur_dist + dist < d[next]) {
				d[next] = cur_dist + dist;
				pq.push(pa(d[next], next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, u, v, c;
	cin >> n >> m >> k;
	for (i=0;i<m;i++) {
		cin >> u >> v >> c;
		g[v].push_back(pa(u, c));
	}

	a.resize(k);
	for (i=0;i<k;i++)
		cin >> a[i];

	fill_n(d, 100001, INF);
	dijkstra();

	for (i=1;i<=n;i++) {
		if (ans < d[i]) {
			city = i;
			ans = d[i];
		}
	}

	cout << city << endl;
	cout << ans << endl;
	return 0;
}
