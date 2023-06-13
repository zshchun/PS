#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, p, source=1, sink=2, ans;
vector<int> g[401];
int c[401][401];
int f[401][401];
int _prev[401];

void network_flow() {
	int i;
	while (1) {
		fill(_prev, _prev+n+1, -1);
		queue<int> q;
		q.push(source);
		while (!q.empty() && _prev[sink] == -1) {
			int cur = q.front();
			q.pop();
			for (int next : g[cur]) {
				if (c[cur][next] > f[cur][next] && _prev[next] == -1) {
					_prev[next] = cur;
					if (next == sink)
						break;
					q.push(next);
				}
			}
		}

		if (_prev[sink] == -1) break;

		int flow = INF;

		for (i=sink;i!=source;i=_prev[i]) {
			int u = _prev[i];
			flow = min(flow, c[u][i]-f[u][i]);
		}

		for (i=sink;i!=source;i=_prev[i]) {
			int u = _prev[i];
			f[u][i] += flow;
			f[i][u] -= flow;
		}
		ans += flow;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, u, v;
	cin >> n >> p;
	for (i=0;i<p;i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		c[u][v] = 1;
	}

	network_flow();

	cout << ans << endl;

	return 0;
}
