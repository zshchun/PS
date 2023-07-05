#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[65][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll ans, i, j, k, N, T;
	cin >> T;
	for (i=0;i<10;i++) {
		dp[1][i] = 1;
	}
	for (i=2;i<65;i++) {
		for (j=0;j<10;j++) {
			for (k=j;k<10;k++) {
				dp[i][j] += dp[i-1][k];
			}
		}
	}
	for (j=0;j<T;j++) {
		cin >> N;
		ans = 0;
		for (i=0;i<10;i++) {
			ans += dp[N][i];
		}
		cout << ans << endl;

	}
	return 0;
}
