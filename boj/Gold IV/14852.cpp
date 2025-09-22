#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MOD 1'000'000'007
ll dp[1000001];
ll sum[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n;
	cin >> n;
	sum[0] = dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;
	sum[1] = sum[0] + dp[1];
	sum[2] = sum[1] + dp[2];
	sum[3] = sum[2] + dp[3];
	for (i=3;i<=n;i++) {
		dp[i] = dp[i-1] * 2 + dp[i-2] * 3 + sum[i-3] * 2;
		dp[i] %= MOD;
		sum[i] = sum[i-1] + dp[i] % MOD;
	}
	cout << dp[n] << endl;
	return 0;
}
