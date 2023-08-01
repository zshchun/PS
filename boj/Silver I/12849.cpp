#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll D;
ll dp[8];

void go() {
	ll t[8];
	t[0] = (dp[1] + dp[2]) % 1'000'000'007;
	t[1] = (dp[0] + dp[2] + dp[3]) % 1'000'000'007;
	t[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % 1'000'000'007;
	t[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % 1'000'000'007;
	t[4] = (dp[2] + dp[3] + dp[5] + dp[7]) % 1'000'000'007;
	t[5] = (dp[3] + dp[4] + dp[6]) % 1'000'000'007;
	t[6] = (dp[5] + dp[7]) % 1'000'000'007;
	t[7] = (dp[4] + dp[6]) % 1'000'000'007;
	memcpy(dp, t, sizeof(dp));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> D;
	ll i;
	dp[0] = 1;
	for (i=0;i<D;i++) {
		go();
	}
	cout << dp[0] << endl;
	return 0;
}
