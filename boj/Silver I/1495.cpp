#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll N, S, M, ans = -1;
ll a[51];
bool dp[51][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> N >> S >> M;

	dp[0][S] = 1;

	for (i=1;i<=N;i++) {
		cin >> a[i];
		for (j=0;j<=M;j++) {
			if (!dp[i-1][j])
				continue;
			if (j - a[i] >= 0)
				dp[i][j-a[i]] = 1;
			if (j + a[i] <= M)
				dp[i][j+a[i]] = 1;
		}
	}
	for (i=M;i>=0;i--) {
		if (dp[N][i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}
