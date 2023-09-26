#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int a[100001];
int dp[100001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, N, ans;
	cin >> N;

	for (i=0;i<N;i++)
		cin >> a[i];

	dp[0][0] = dp[0][1] = a[0];
	ans = a[0];

	for (i=1;i<N;i++) {
		dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][1] + a[i]);
		ans = max({ans, dp[i][0], dp[i][1]});
	}

	cout << ans << endl;

	return 0;
}
