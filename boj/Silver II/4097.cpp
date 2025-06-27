#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890123ULL

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, n, ans;
	while (1) {
		cin >> n;
		if (n == 0) break;
		vector<ll> a(n+1);
		vector<ll> dp(n+1);
		ans = -INF;
		ans = dp[0] = -INF;
		for (i=1;i<=n;i++) {
			cin >> a[i];
			dp[i] = max(dp[i-1] + a[i], a[i]);
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
