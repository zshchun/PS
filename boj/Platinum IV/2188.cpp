#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M, S = 0, T = 401;
int c[402][402];
int f[402][402];
vector<int> g[402];
int path[402];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, x, u, v, cur, next, flow, ans = 0;
	cin >> N >> M;
	for (u=1;u<=N;u++) {
		g[S].push_back(u);
		g[u].push_back(S);
		c[S][u] = 1;
		cin >> x;
		for (j=0;j<x;j++) {
			cin >> v;
			v += 200;
			c[u][v] = 1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	for (u=201;u<201+M;u++) {
		g[u].push_back(T);
		g[T].push_back(u);
		c[u][T] = 1;
	}

	while (1) {
		queue<int> q;
		q.push(S);
		fill(path, path+402, -1);
		while (!q.empty() && path[T] == -1) {
			cur = q.front();
			q.pop();
			for (int next : g[cur]) {
				if (c[cur][next] > f[cur][next] && path[next] == -1) {
					q.push(next);
					path[next] = cur;
					if (next == T)
						break;
				}
			}
		}
		if (path[T] == -1) break;

		flow = INF;
		for (v=T;v>S;v=u) {
			u = path[v];
			flow = min(flow, c[u][v]-f[u][v]);
		}

		for (v=T;v>S;v=u) {
			u = path[v];
			f[u][v] += flow;
			f[v][u] -= flow;
		}
		ans += flow;
	}
	cout << ans << endl;

	return 0;
}
