#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
ll dp[101][101];

// pascal's triangle
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, n, m, K;
	cin >> n >> m >> K;

	for (i=0;i<=n;i++) {
		for (j=0;j<=m;j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
			if (dp[i][j] > 1000000001)
				dp[i][j] = 1000000001;
		}
	}

	if (K > dp[n][m]) {
		cout << "-1\n";
		return 0;
	}

	string ans;
	while (n > 0 || m > 0) {
		if (n == 0) {
			ans += 'z';
			m--;
		} else {
			if (K <= dp[n-1][m]) {
				ans += 'a';
				n--;
			} else {
				ans += 'z';
				K -= dp[n-1][m];
				m--;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
