#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll dp[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, B, i; 
	cin >> N >> B;
	dp[B] = dp[1] = 1;

	for (i=2;i<=N;i++) {
		dp[i] += dp[i-1];
		if (i >= B)
			dp[i] += dp[i-B];
		dp[i] %= 1'000'000'007;
	}
	cout << dp[N] << endl;
	return 0;
}
