#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
int a[1001][1001];
int dp[1002][1002][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = INF;
	cin >> n >> m;
	fill_n(&dp[0][0][0], 1002*1002*3, INF);

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			cin >> a[i][j];
	for (i=1;i<=m;i++) {
		for (j=0;j<3;j++) {
			dp[1][i][j] = a[1][i];
		}
	}

	for (i=2;i<=n;i++) {
		for (j=1;j<=m;j++) {
			dp[i][j][0] = min(dp[i-1][j-1][1], dp[i-1][j-1][2]) + a[i][j];
			dp[i][j][1] = min(dp[i-1][j][0], dp[i-1][j][2]) + a[i][j];
			dp[i][j][2] = min(dp[i-1][j+1][0], dp[i-1][j+1][1]) + a[i][j];
		}
	}
	for (i=1;i<=m;i++)
		for (j=0;j<3;j++)
			ans = min(ans, dp[n][i][j]);

	cout << ans << endl;

	return 0;
}
