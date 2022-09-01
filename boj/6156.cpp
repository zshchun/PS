#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 123456789LL

// floyd-warshall
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, i, j, k, u, v, ans = 0;
	cin >> n >> m;
	vector<vector<ll>> a(n+1, vector<ll>(n+1, INF));

	for (i=1;i<=n;i++)
		a[i][i] = 0;
	for (i=0;i<m;i++) {
		cin >> u >> v;
		a[u][v] = 1;
	}
	for (k=1;k<=n;k++) {
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) {
				if (a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}

	for (i=1;i<=n;i++) {
		ll cnt = 0;
		for (j=1;j<=n;j++) {
			if (i == j) continue;
			if (a[i][j] != INF || a[j][i] != INF)
				cnt++;
		}
		if (cnt == n-1)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
