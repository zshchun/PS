#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N;
ll a[101][101];
ll dp[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k;
	cin >> N;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> a[i][j];
		}
	}

	dp[1][1] = 1;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			for (k=1;k<=9;k++) {
				if (k < j && a[i][j-k] == k)
					dp[i][j] += dp[i][j-k];
				if (k < i && a[i-k][j] == k)
					dp[i][j] += dp[i-k][j];
			}
		}
	}
	cout << dp[N][N] << endl;

	return 0;
}
