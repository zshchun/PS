#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll dp[1516];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i;
	cin >> N;
	dp[2] = 1;
	for (i=3;i<=N;i++) {
		dp[i] = (dp[i-1] + dp[i-2] * 2) % 1000000007;
	}
	cout << dp[N] << endl;

	return 0;
}
