#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll dp[3][33334];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, n, x;
	cin >> n;
	dp[2][2] = dp[1][2] = dp[0][2] = 2;
	for (i=3;i<=n;i++) {
		x = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) % 1'000'000'009;
		for (j=0;j<3;j++)
			dp[j][i] = x;
	}
	cout << dp[0][n] << endl;
	return 0;
}
