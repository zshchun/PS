#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF INT_MAX
ll N;
ll a[100001][3];
ll dp[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T = 1, i;
	while (1) {
		memset(a, 0, sizeof(a));
		cin >> N;
		if (N == 0) break;
		cin >> a[1][0] >> a[1][1] >> a[1][2];
		dp[1][0] = INF;
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][1] + a[1][2];

		for (i=2;i<=N;i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i][0];
			dp[i][1] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]}) + a[i][1];
			dp[i][2] = min({dp[i-1][1], dp[i-1][2], dp[i][1]}) + a[i][2];
		}
		cout << T << ". " << dp[N][1] << endl;
		T++;
	}
	return 0;
}
