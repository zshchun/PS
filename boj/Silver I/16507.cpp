#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int R, C, Q;
int a[1001][1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> Q;
	int i, j, r, c, x, ans, r1, c1, r2, c2;
	for (i=1;i<=R;i++) {
		for (j=1;j<=C;j++) {
			cin >> a[i][j];
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + a[i][j];
		}
	}
	for (i=0;i<Q;i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		r = r2 - r1 + 1;
		c = c2 - c1 + 1;
		x = r * c;
		ans = (dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1]) / x;
		cout << ans << endl;
	}

	return 0;
}
