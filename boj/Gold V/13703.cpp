#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[64][128];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll k, n, i, j, ans = 0;
	cin >> k >> n;
	dp[0][k] = 1;
	for (i=1;i<=n;i++)
		for (j=1;j<=126;j++)
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
	if (k > 0)
		ans = accumulate(&dp[n][1], &dp[n][127], 0ull);
	cout << ans << endl;

	return 0;
}
