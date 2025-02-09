#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789
int n, m, k, ans;
int g[301][301];
int dp[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int u, v, i, j, k, x;
	cin >> n >> m >> k;
	for (i=0;i<k;i++) {
		cin >> u >> v >> x;
		if (u > v) continue;
		if (g[u][v] < x) {
			g[u][v] = max(g[u][v], x);
			if (u == 1)
				dp[v][2] = x;
		}
	}

	for (k=2;k<=m;k++) {
		for (i=1;i<=n;i++) {
			if (!dp[i][k]) continue;
			for (j=1;j<=n;j++) {
				if (!g[i][j]) continue;
				dp[j][k+1] = max(dp[j][k+1], dp[i][k] + g[i][j]);
			}
		}
	}

	for (j=1;j<=m;j++) {
		ans = max(ans, dp[n][j]);
	}

	cout << ans << endl;

	return 0;
}
