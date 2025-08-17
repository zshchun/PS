#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, n, m, i, j;
	dp[1][1] = dp[2][1] = dp[3][1] = 1;

	for (i=2;i<=1000;i++) {
		for (j=2;j<=1000;j++) {
			dp[j][i] += dp[j-1][i-1];
			dp[j][i] += dp[j-2][i-1];
			if (j >= 3)
				dp[j][i] += dp[j-3][i-1];
			dp[j][i] %= 1000000009;
		}
	}

	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << dp[n][m] << endl;
	}

	return 0;
}
