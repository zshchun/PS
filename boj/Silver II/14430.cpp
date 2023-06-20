#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll N, M;

ll a[301][301];
ll dp[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> N >> M;

	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			cin >> a[i][j];
			dp[i][j] = max(dp[i-1][j]+a[i][j], dp[i][j-1]+a[i][j]);
		}
	}
	cout << dp[N][M] << endl;

	return 0;
}
