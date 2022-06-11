#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define INF 1234567891

vector<pa> g[501];
ll d[501];
bool visited[501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, N, M, W, i, j, u, v, w;
	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
		for (i=1;i<=N;i++) {
			g[i].clear();
			d[i] = INF;
		}
		for (i=0;i<M;i++) {
			cin >> u >> v >> w;
			g[u].push_back(pa(w, v));
			g[v].push_back(pa(w, u));
		}
		for (i=0;i<W;i++) {
			cin >> u >> v >> w;
			g[u].push_back(pa(-w, v));
		}
		bool found = false;
			d[1] = 0;
			for (i=1;i<=N;i++) {
				for (j=1;j<=N;j++) {
					for (auto &p : g[j]) {
						ll next = p.second;
						ll dist = p.first;
						if (d[next] > d[j]+dist) {
							d[next] = d[j] + dist;
							if (i == N) 
								found = true;
						}
					}
				}
			}
		if (found)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
