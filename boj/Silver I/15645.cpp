#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, mn, mx;
int a[100002][5];
int dp[2][100002][5];
#define MAX 0
#define MIN 1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	mn = INF;
	cin >> n;

	for (i=1;i<=n;i++) {
		dp[MIN][i-1][0] = dp[MIN][i-1][4] = INF;
		for (j=1;j<=3;j++)
			cin >> a[i][j];
		for (j=1;j<=3;j++) {
			dp[MAX][i][j] = max({dp[MAX][i-1][j-1], dp[MAX][i-1][j], dp[MAX][i-1][j+1]}) + a[i][j];
			dp[MIN][i][j] = min({dp[MIN][i-1][j-1], dp[MIN][i-1][j], dp[MIN][i-1][j+1]}) + a[i][j];
		}
	}
	for (j=1;j<=3;j++) {
		mx = max(dp[MAX][n][j], mx);
		mn = min(dp[MIN][n][j], mn);
	}
	cout << mx << ' ' << mn << endl;
	return 0;
}
