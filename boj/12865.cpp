#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N, K, ans;
int dp[101][100001];
int W[101];
int V[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> N >> K;
	for (i=1;i<=N;i++)
		cin >> W[i] >> V[i];
	for (i=1;i<=N;i++) {
		for (j=1;j<=K;j++) {
			if (j - W[i] >= 0) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]]+V[i]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	cout << dp[N][K] << '\n';
	return 0;
}
