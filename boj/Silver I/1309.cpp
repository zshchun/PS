#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int dp[100001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, ans = 0;
	dp[1][1] = dp[1][0] = 1;
	cin >> n;
	for (i=2;i<=n;i++) {
		dp[i][0] += dp[i-1][1] * 2 + dp[i-2][1] + 1;
		dp[i][1] += dp[i-1][0] * 2 + dp[i-2][0] + 1;
		dp[i][0] %= 9901;
		dp[i][1] %= 9901;
	}
	ans = dp[n][0] + dp[n][1] + 1;
	ans %= 9901;
	cout << ans << endl;
	return 0;
}
