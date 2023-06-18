#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll S, K, ans;
ll dp[21][101];

ll dfs(ll c, ll n) {
	ll i, ret = 0;
	if (c >= K) return 1;
	if (dp[c][n])
		return dp[c][n];
	for (i=1;i<=n;i++) {
		ret = max(ret, dfs(c+1, n-i) * i);
	}
	dp[c][n] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> K;
	ans = dfs(0, S);
	cout << ans << endl;

	return 0;
}
