#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[21][21];
int dp[21][21][2][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = 0, c;

	for (i=1;i<=19;i++) {
		for (j=1;j<=19;j++) {
			cin >> a[i][j];
		}
	}

	for (i=1;i<=19;i++) {
		for (j=1;j<=19;j++) {
			c = a[i][j];
			// 0=-, 1=|, 2=\, 3 = /
			if (c >= 1) {
				c--;
				dp[i][j][c][0] = dp[i][j-1][c][0] + 1;
				dp[i][j][c][1] = dp[i-1][j][c][1] + 1;
				dp[i][j][c][2] = dp[i-1][j-1][c][2] + 1;
				dp[i][j][c][3] = dp[i-1][j+1][c][3] + 1;
			}
		}
	}

	for (i=1;i<=19;i++) {
		for (j=1;j<=19;j++) {
			for (c=0;c<2;c++) {
				if (dp[i][j][c][0] == 5 && dp[i][j+1][c][0] != 6) { j -= 4; ans = c + 1; break; }
				if (dp[i][j][c][1] == 5 && dp[i+1][j][c][1] != 6) { i -= 4; ans = c + 1; break; }
				if (dp[i][j][c][2] == 5 && dp[i+1][j+1][c][2] != 6) { i -= 4; j -= 4; ans = c + 1; break; }
				if (dp[i][j][c][3] == 5 && dp[i+1][j-1][c][3] != 6) { ans = c + 1; break; }
			}
			if (ans) break;
		}
		if (ans) break;
	}

	cout << ans << endl;
	if (ans) {
		cout << i << " " << j << endl;
	}
	return 0;
}
