#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll ans, x;
ll dp[100001][4];

ll dfs(ll x, ll last) {
	ll ret = 0;
	if (x == 0)
		return 1;
	if (dp[x][last])
		return dp[x][last];

	for (ll i=1;i<=3;i++) {
		if (last == i) continue;
		if (i > x) break;
		ret = (ret + dfs(x-i, i)) % 1000000009;
	}
	dp[x][last] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	while (T--) {
		cin >> x;
		ans = dfs(x, 0);
		cout << ans << endl;
	}
	return 0;
}
