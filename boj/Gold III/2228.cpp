#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int N, M, ans;
int a[101];
int dp[101][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	cin >> N >> M;
	for (i=1;i<=N;i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	
	for (i=1;i<=M;i++) {
		dp[0][i] = -INF;
	}
	
	for (i=1;i<=N;i++) {
		for (j=1;j<=M;j++) {
			dp[i][j] = dp[i-1][j];
			if (j == 1)
				dp[i][j] = max(dp[i][j], a[i]);
			for (k=2;k<=i;k++) {
				dp[i][j] = max(dp[i][j], dp[k-2][j-1] + a[i] - a[k-1]);
			}
		}
	}

	cout << dp[N][M] << endl;

	return 0;
}
