#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MOD (1'000'000'007)

ll n, ans;
ll dp[300001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, mx = 0, mn = 0;
	cin >> n;
	vector<ll> a(n);
	for (i=0;i<n;i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	for (i=1;i<=n;i++) {
		dp[i] = (dp[i-1] + 1) * 2 - 1;
		dp[i] %= MOD;
	}

	for (i=0;i<n;i++) {
		mx += a[i] * dp[i];
		mx %= MOD;
		mn += a[i] * dp[n-i-1];
		mn %= MOD;
	}
	ans = mx - mn + MOD;
	ans %= MOD;
	cout << ans << endl;

	return 0;
}
