#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll T, V, E;
vector<ll> g[20001];
int color[20001];
#define NOCOLOR 0
#define RED  1
#define BLUE -1
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool bfs() {
	ll i;
	for (i=1;i<=V;i++) {
		queue<ll> q;
		if (color[i] != NOCOLOR)
			continue;
		q.push(i);
		color[i] = RED;
		while (!q.empty()) {
			ll cur = q.front();
			q.pop();
			for (ll next : g[cur]) {
				if (color[next] == NOCOLOR) {
					color[next] = color[cur] * -1;
					q.push(next);
				} else if (color[next] == color[cur]) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, u, v;
	cin >> T;
	while (T--) {
		cin >> V >> E;
		for (i=1;i<=V;i++)
			g[i].clear();
		memset(color, 0, sizeof(color));

		for (i=0;i<E;i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		if (bfs())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
