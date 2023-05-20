#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll g[401][401];
ll V, E;

void floyd() {
	ll i, j, k;
	for (k=1;k<=V;k++) {
		for (i=1;i<=V;i++) {
			for (j=1;j<=V;j++) {
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, x, u, v;
	ll ans = INF;
	cin >> V >> E;
	fill(&g[0][0], &g[0][0]+401*401, INF);

	for (i=0;i<E;i++) {
		cin >> u >> v >> x;
		g[u][v] = x;
	}

	for (i=1;i<=V;i++) {
		g[i][i] = 0;
	}

	floyd();

	for (i=1;i<=V;i++) {
		for (j=1;j<=V;j++) {
			if (i == j) continue;
			if (g[i][j] != INF && g[j][i] != INF) {
				ans = min(ans, g[i][j] + g[j][i]);
			}
		}
	}

	if (ans != INF)
		cout << ans << endl;
	else
		cout << "-1\n";

	return 0;
}
