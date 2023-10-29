#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
#define MOD 1'000'000'000
#define BITS_ALL ((1<<10) - 1)

ll N, ans;
ll dp[101][10][BITS_ALL+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k;
	cin >> N;

	for (i=1;i<=9;i++)
		dp[1][i][1<<i] = 1;

	for (i=2;i<=N;i++) {
		for (j=0;j<=9;j++) {
			for (k=0;k<=BITS_ALL;k++) {
				ll bits = k | (1 << j);
				if (j > 0)
					dp[i][j][bits] = (dp[i][j][bits] + dp[i-1][j-1][k]) % MOD;
				if (j < 9)
					dp[i][j][bits] = (dp[i][j][bits] + dp[i-1][j+1][k]) % MOD;
			}
		}
	}

	ll ans = 0;
	for (i=0;i<=9;i++) {
		ans = (ans + dp[N][i][BITS_ALL]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
