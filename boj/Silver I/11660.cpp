#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j, x, y, x1, y1, v;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		for (j=1;j<=N;j++) {
			cin >> v;
				dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + v;
		}
	}

	for (i=0;i<M;i++) {
		int ans;
		cin >> y >> x >> y1 >> x1;
		ans = dp[y1][x1] - dp[y-1][x1] - dp[y1][x-1] + dp[y-1][x-1];
		cout << ans << '\n';
	}

	return 0;
}

