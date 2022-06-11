#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[11];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, n, k;
	cin >> n >> k;
	dp[0] = 1LL;
	dp[1] = 1LL;
	for (i=2LL;i<11;i++)
		dp[i] = dp[i-1] * i;
	cout << dp[n] / (dp[k] * (dp[n-k])) << "\n";
	return 0;
}
