#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int N, ans;
int a[33][33];
ll dp[33][33][3];

int main() {
	int i, j;
	cin >> N;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> a[i][j];
		}
	}
	dp[1][2][0] = 1;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			if (!a[i][j]) {
				dp[i][j][0] += dp[i][j-1][2];
				dp[i][j][0] += dp[i][j-1][0];
			}
			if (!a[i][j]) {
				dp[i][j][1] += dp[i-1][j][2];
				dp[i][j][1] += dp[i-1][j][1];
			}
			if (!a[i][j] && !a[i-1][j] && !a[i][j-1]) {
				dp[i][j][2] += dp[i-1][j-1][2];
				dp[i][j][2] += dp[i-1][j-1][0];
				dp[i][j][2] += dp[i-1][j-1][1];
			}
		}
	}

	cout << (dp[N][N][0] + dp[N][N][1] + dp[N][N][2]) << endl;

	return 0;
}
