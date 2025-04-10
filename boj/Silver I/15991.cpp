#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;
	for (i=7;i<=100001;i++)
		dp[i] += (dp[i-2] + dp[i-4] + dp[i-6]) % 1000000009;

	while (t--) {
		cin >> i;
		cout << dp[i] << endl;
	}
	return 0;
}
