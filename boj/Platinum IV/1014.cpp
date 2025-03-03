#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, m, ans;
bool a[11][11];
int dp[11][(1<<10)+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, p, T, mask;
	char c;
	cin >> T;

	while (T--) {
		memset(dp, 0, sizeof(dp));
		ans = 0;

		cin >> n >> m;
		for (i=0;i<n;i++) {
			for (j=0;j<m;j++) {
				cin >> c;
				if (c == 'x')
					a[i][j] = 1;
				else if (c == '.')
					a[i][j] = 0;
			}
		}

		for (i=0;i<n;i++) {
			for (j=0;j<(1<<m);j++) {
				k = j;
				mask = 0;
				while (k) {
					p = __builtin_ffs(k) - 1;
					mask |= (1 << (p)) | (1 << (p+2));
					if (a[i][p]) break;
					k &= k - 1;
				}
				mask = (mask >> 1) & ((1<<m) - 1);
				if (k || j & mask) continue;

				if (i == 0) {
					dp[i][j] = __builtin_popcount(j);
					ans = max(ans, dp[i][j]);
					continue;
				}

				for (k=0;k<(1<<m);k++) {
					if (!dp[i-1][k]) continue;
					if (k & mask) continue;
					dp[i][j] = max(dp[i][j], dp[i-1][k] + __builtin_popcount(j));
					ans = max(ans, dp[i][j]);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
