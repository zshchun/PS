#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, TC, i, j, ans;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	for (i=4;i<=1000;i++) {
		for (j=2;j<=1000;j++)
			dp[i][j] = (dp[i][j] + dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % 1'000'000'009;
	}
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		ans = 0;
		for (i=1;i<=M;i++)
			ans = (ans + dp[N][i]) % 1'000'000'009;
		cout << ans << endl;;
	}

	return 0;
}
