#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll N, ans;
ll dp[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	ll i, j;

	fill(&dp[1][0], &dp[1][0]+9, 1);

	for (i=2;i<=N;i++) {
		for (j=0;j<10;j++) {
			if (j == 0)
				dp[i][j] = dp[i-1][j+1];
			else if (j == 9)
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % 1000000000;

		}
	}
	for (i=0;i<10;i++)
		ans = (ans + dp[N][i]) % 1000000000;

	cout << (ans % 1000000000) << endl;

	return 0;
}
