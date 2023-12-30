#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, T, j, N;
	dp[1] = 1;
	for (i=2;i<=1000000;i++) {
		for (j=i;j<=1000000;j+=i) {
			dp[j] += i;
		}
		dp[i] += dp[i-1] + 1;
	}

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << endl;
	}
	return 0;
}
