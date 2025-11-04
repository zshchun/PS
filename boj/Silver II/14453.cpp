#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[100002];
int dp[100002][3];
enum {
	HOOF,
	PAPER,
	SCISSORS,
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j, ans = 0;
	char c;
	cin >> n;
	for (i=1;i<=n;i++) {
		cin >> c;
		if (c == 'P') a[i] = PAPER;
		else if (c == 'H') a[i] = HOOF;
		else if (c == 'S') a[i] = SCISSORS;

		dp[i][HOOF] = dp[i-1][HOOF] + (a[i] == SCISSORS ? 1 : 0);
		dp[i][PAPER] = dp[i-1][PAPER] + (a[i] == HOOF ? 1 : 0);
		dp[i][SCISSORS] = dp[i-1][SCISSORS] + (a[i] == PAPER ? 1 : 0);
	}
	for (i=1;i<=n;i++) {
		ans = max(ans, dp[i][HOOF]);
		ans = max(ans, dp[i][SCISSORS]);
		ans = max(ans, dp[i][PAPER]);
		ans = max(ans, dp[i-1][HOOF]+dp[n][SCISSORS]-dp[i-1][SCISSORS]);
		ans = max(ans, dp[i-1][HOOF]+dp[n][PAPER]-dp[i-1][PAPER]);
		ans = max(ans, dp[i-1][SCISSORS]+dp[n][PAPER]-dp[i-1][PAPER]);
		ans = max(ans, dp[i-1][SCISSORS]+dp[n][HOOF]-dp[i-1][HOOF]);
		ans = max(ans, dp[i-1][PAPER]+dp[n][HOOF]-dp[i-1][HOOF]);
		ans = max(ans, dp[i-1][PAPER]+dp[n][SCISSORS]-dp[i-1][SCISSORS]);
	}
	cout << ans << endl;
	return 0;
}
