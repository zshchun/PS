#include <bits/stdc++.h>
using namespace std;

int coin[20];
int dp[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, N, M, i, j;
	cin >> T;
	while (T--) {
		cin >> N;
		for (i=0;i<N;i++) {
			cin >> coin[i];
		}
		cin >> M;
		fill(dp, dp+M+1, 0);

		dp[0] = 1;
		for (j=0;j<N;j++) {
			for (i=1;i<=M;i++) {
				if (i >= coin[j])
					dp[i] += dp[i-coin[j]];
			}
		}
		cout << dp[M] << endl;
	}
	return 0;
}
