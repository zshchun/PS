#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool m[18][18];
int dp[3][18][18];
#define H 0
#define V 1
#define D 2
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j;
	cin >> N;
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			cin >> m[i][j];

	dp[H][1][2] = 1;
	for (i=1;i<=N;i++) {
		for (j=2;j<=N;j++) {
			if (!m[i][j+1]) {
				dp[H][i][j+1] = dp[D][i][j] + dp[H][i][j];
			}
			if (!m[i+1][j]) {
				dp[V][i+1][j] = dp[D][i][j] + dp[V][i][j];
			}
			if (!m[i+1][j] && !m[i][j+1] && !m[i+1][j+1]) {
				dp[D][i+1][j+1] = dp[D][i][j] + dp[V][i][j] + dp[H][i][j];
			}
		}
	}
	cout << dp[D][N][N] + dp[V][N][N] + dp[H][N][N] << '\n';

	return 0;
}

