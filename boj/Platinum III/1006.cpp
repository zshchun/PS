#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[10001];
int b[10001];
int dp[10001][3];
int N, W;

void solve() {
	int i;
	dp[1][0] = dp[1][1] = 1;
	if (a[1] + b[1] <= W)
		dp[1][2] = 1;
	else
		dp[1][2] = 2;

	for (i=2;i<=N;i++) {
		dp[i][2] = dp[i-1][2] + 2;
		dp[i][0] = dp[i][1] = dp[i-1][2] + 1;

		if (a[i-1] + a[i] <= W)
			dp[i][0] = min(dp[i][0], dp[i-1][1]+1);
		if (b[i-1] + b[i] <= W)
			dp[i][1] = min(dp[i][1], dp[i-1][0]+1);
		if (a[i] + b[i] <= W)
			dp[i][2] = min(dp[i][2], dp[i-1][2] + 1);

		dp[i][2] = min({dp[i][2], dp[i][0]+1, dp[i][1]+1});


		if (i >= 2 && a[i-1] + a[i] <= W && b[i-1] + b[i] <= W)
			dp[i][2] = min(dp[i][2], dp[i-2][2] + 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, j, ans;
	cin >> T;
	while (T--) {
		cin >> N >> W;
		for (i=1;i<=N;i++)
			cin >> a[i];
		for (i=1;i<=N;i++)
			cin >> b[i];

		solve();
		ans = dp[N][2];

		if (N == 1) {
			cout << ans << endl;
			continue;
		}

		if (a[1] + a[N] <= W && b[1] + b[N] <= W) {
			a[1] += W; a[N] += W; b[1] += W; b[N] += W;
			solve();
			ans = min(ans, dp[N-1][2]);
			a[1] -= W; a[N] -= W; b[1] -= W; b[N] -= W;
		}

		if (a[1] + a[N] <= W) {
			a[1] += W; a[N] += W;
			solve();
			ans = min(ans, dp[N][1]);
			a[1] -= W; a[N] -= W;
		}

		if (b[1] + b[N] <= W) {
			b[1] += W; b[N] += W;
			solve();
			ans = min(ans, dp[N][0]);
			b[1] -= W; b[N] -= W;
		}

		cout << ans << endl;
	}
	return 0;
}
