#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, K;
int dp[1001][1001];
#define MOD (1'000'000'003)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> K;
	for (i=0;i<=N;i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (i=2;i<N;i++) {
		for (j=2;j<=K;j++) {
			dp[i][j] = dp[i-2][j-1] + dp[i-1][j];
			dp[i][j] %= MOD;
		}
	}

	dp[N][K] = dp[N-3][K-1] + dp[N-1][K];
	dp[N][K] %= MOD;

	cout << dp[N][K] << endl;
		
	return 0;
}
