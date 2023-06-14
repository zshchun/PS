#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll N, ans;
ll a[1001];
ll dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;

	cin >> N;
	for (i=0;i<N;i++)
		cin >> a[i];
	
	for (i=0;i<N;i++) {
		dp[i] = 1;
		for (j=0;j<i;j++) {
			if (a[i] < a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}
