#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i;
	cin>>n;
	ll *dp = new ll[n];
	dp[0] = 0;
	dp[1] = 1;
	for(i=2;i<=n;i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n] << "\n";
	return 0;
}
