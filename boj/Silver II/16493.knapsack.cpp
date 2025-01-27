#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
int dp[21][201];
int days[21];
int pages[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int i, j;
	for (i=1;i<=m;i++)
		cin >> days[i] >> pages[i];

	for (i=1;i<=m;i++) {
		for (j=1;j<=n;j++) {
			int d = days[i];
			int p = pages[i];
			if (d <= j)
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-d] + p);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[m][n] << endl;

	return 0;
}
