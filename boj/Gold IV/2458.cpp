#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll g[501][501];
ll N, M, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, u, v;
	cin >> N >> M;

	for (i=0;i<M;i++) {
		cin >> u >> v;
		g[u][v] = 1;
	}

	// floyd-warshall
	for (k=1;k<=N;k++) {
		for (i=1;i<=N;i++) {
			for (j=1;j<=N;j++) {
				if (g[i][k] && g[k][j])
					g[i][j] = 1;
			}
		}
	}

	for (i=1;i<=N;i++) {
		ll cnt = 0;
		for (j=1;j<=N;j++) {
			if (g[i][j] || g[j][i])
				cnt++;
		}
		if (cnt == N-1)
			ans++;
	}

	cout << ans << endl;


	return 0;
}
