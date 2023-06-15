#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll N, ans;
ll dp[1001][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k;
	cin >> N;
	for (i=0;i<10;i++)
		dp[0][i] = 1;

	for (i=1;i<=N;i++) {
		for (j=0;j<10;j++) {
			for (k=j;k<10;k++) {
				dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
			}
		}

	}

	cout << dp[N][0] << endl;

	return 0;
}
