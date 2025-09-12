#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MOD 1'000'000'000

int dp[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n, k;
	cin >> n >> k;

	for (i=0;i<=k;i++)
		dp[i][0] = 1;

	for (i=1;i<=k;i++)
		for (j=1;j<=n;j++)
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;

	cout << dp[k][n] << endl;

	return 0;
}
