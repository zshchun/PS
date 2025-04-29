#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, m, k, x, y;
int dp[16][16];

bool is_same_row(int r) {
	if (r == y)
		return true;
	return false;
}
bool is_same_col(int c) {
	if (c == x)
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n >> m >> k;
	if (k > 0) {
		y = ((k - 1) / m) + 1;
		x = ((k - 1) % m) + 1;
	}

	dp[1][1] = 1;
	for (i=1;i<=n;i++) {
		for (j=1;j<=m;j++) {
			if (k == 0 || !is_same_row(i) || j <= x)
				dp[i][j] += dp[i-1][j];
			if (k == 0 || !is_same_col(j) || i <= y)
				dp[i][j] += dp[i][j-1];
		}
	}

	cout << dp[n][m] << endl;

	return 0;
}
