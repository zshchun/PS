#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll dp[31];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll D, K, i, j, k;
	cin >> D >> K;
	for (i=1;i<=K;i++) {
		dp[1] = i;
		for (j=i;j<=K;j++) {
			dp[2] = j;
			if (i + j > K)
				break;
			for (k=3;k<=D;k++) {
				dp[k] = dp[k-2] + dp[k-1];
			}
			if (K == dp[D]) {
				cout << i << endl;
				cout << j << endl;
				return 0;
			}
		}
	}

	return 0;
}
