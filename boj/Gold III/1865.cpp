#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define INF 123456789
vector<P> g[501];
int d[501];
int N;
bool negative_cycle;

void bellman(int s) {
	fill(d, d+N+1, INF);
	d[s] = 0;
	int i, j;
	for (i=1;i<=N && !negative_cycle;i++) {
		for (j=1;j<=N && !negative_cycle;j++) {
			for (auto &p : g[j]) {
				int next = p.first;
				int dist = p.second;
				if (d[next] > d[j] + dist) {
					d[next] = d[j] + dist;
					if (i == N) negative_cycle = true;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, M, W, u, v, w, i;
	cin >> T;
	while (T--) {
		for (i=1;i<=N;i++)
			g[i].clear();
		cin >> N >> M >> W;
		for (i=0;i<M;i++) {
			cin >> u >> v >> w;
			g[u].push_back(P(v, w));
			g[v].push_back(P(u, w));
		}
		for (i=0;i<W;i++) {
			cin >> u >> v >> w;
			g[u].push_back(P(v, -w));
		}
		fill(d, d+N+1, INF);
		negative_cycle = false;
		bellman(1);
		if (negative_cycle)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
