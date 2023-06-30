#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll n, m, ans;
ll visited[501];
vector<ll> g[501];

void bfs() {
	ll cur;
	queue<ll> q;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		ans++;
		for (ll next : g[cur]) {
			if (!visited[next] && visited[cur] < 3) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll u, v, i;
	cin >> n >> m;
	for (i=0;i<m;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	cout << ans - 1 << endl;

	return 0;
}
