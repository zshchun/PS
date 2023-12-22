#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[1001][1001];
#define VERT 0
#define HORI 1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j, k, x, y, ans = 0;
	char c;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			cin >> c;
			if (c == '1') {
				dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << (ans * ans) << endl;
	return 0;
}
