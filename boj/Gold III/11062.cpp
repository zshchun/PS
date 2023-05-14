#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll a[1001];
ll dp[1001][1001];

ll dfs(ll l, ll r, ll t) {
	if (l > r) return 0;
	if (dp[l][r]) return dp[l][r];

	if (t % 2 == 0) {
		dp[l][r] = max(dfs(l+1, r, t+1) + a[l], dfs(l, r-1, t+1) + a[r]);
	} else {
		dp[l][r] = min(dfs(l+1, r, t+1), dfs(l, r-1, t+1));
	}
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, i, n;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (i=1;i<=n;i++)
			cin >> a[i];
		dfs(1, n, 0);

		cout << dp[1][n] << endl;
	}

	return 0;
}
