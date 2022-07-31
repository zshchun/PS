#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

ll solve(ll s, ll e, vector<ll> &dp) {
	ll l, r;
	ll sum = 0;
	if (s < 3) l = 0;
	else l = dp[s-2];
	r = dp[e];
	return r - l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		vector<ll> dp(n);
		vector<ll> d(n);
		ans = 2e6;
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		dp[1] = max(0ll, max(a[0], a[2]) + 1 - a[1]);
		dp[2] = max(0ll, max(a[1], a[3]) + 1 - a[2]);
		for (i=3;i<n-1;i++) {
			dp[i] = dp[i-2] + max(0ll, max(a[i-1], a[i+1]) + 1 - a[i]);
		}
		bool even = !(n % 2);
		if (even) {
			ans = min(solve(1, n-3, dp), solve(2, n-2, dp));
			for (j=1;j<n-4;j+=2) {
				k = solve(1, j, dp) + solve(j+3, n-2, dp);
				ans = min(ans, k);
			}
		} else {
			ans = solve(1, n-2, dp);
		}
		cout << ans << endl;
	}
	return 0;
}
