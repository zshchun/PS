#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, N, i, j;
	dp[0] = dp[2] = 1;
	for (i=4;i<=5000;i+=2) {
		for (j=0;j<i;j+=2) {
			dp[i] += (dp[j] * dp[i-2-j]); 
			dp[i] %= 1000000007;
		}
	}
	cin >> T;
	while (T--) {
		cin >> N;
		if (N % 2) {
			cout << "0\n";
		} else {
			cout << dp[N] << endl;
		}
	}
	return 0;
}
