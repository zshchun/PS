#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[1000001], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, a, b, d, N;
	cin >> a >> b >> d >> N;
	dp[0] = 1;
	for (i=1;i<=N;i++) {
		dp[i] = dp[i-1];
		if (i >= a)
			dp[i] += dp[i-a];
		if (i >= b)
			dp[i] -= dp[i-b];
		dp[i] += 1000;
		dp[i] %= 1000;
	}
	ans = dp[N] + 1000 - dp[N-d];
	ans %= 1000;
	cout << ans << endl;
	return 0;
}
