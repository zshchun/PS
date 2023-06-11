#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll N, S = 0, T = 25;
vector<ll> g[52];
ll c[52][52];
ll f[52][52];
ll pp[52];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, u, v, x, cur, p, flow, ans = 0;
	char c1, c2;
	cin >> N;

	for (i=0;i<N;i++) {
		cin >> c1 >> c2 >> x;
		if (c1 <= 'Z') u = c1 - 'A';
		else u = c1 - 'a' + 26;
		if (c2 <= 'Z') v = c2 - 'A';
		else v = c2 - 'a' + 26;
		c[u][v] += x;
		c[v][u] += x;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	while (1) {
		queue<ll> q;
		q.push(S);
		fill(pp, pp+52, -1);
		while (!q.empty() && pp[T] == -1) {
			cur = q.front();
			q.pop();
			for (ll next : g[cur]) {
				if (c[cur][next] > f[cur][next] && pp[next] == -1) {
					q.push(next);
					pp[next] = cur;
					if (next == T) break;
				}
			}
		}
		if (pp[T] == -1)
			break;
		flow = INF;
		for (i=T;i>S;i=pp[i]) {
			p = pp[i];
			flow = min(flow, c[p][i]-f[p][i]);
		}
		for (i=T;i>S;i=pp[i]) {
			p = pp[i];
			f[p][i] += flow;
			f[i][p] -= flow;
		}
		ans += flow;
	}

	cout << ans << endl;
	return 0;
}
