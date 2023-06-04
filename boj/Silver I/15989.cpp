#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
int n, ans;
int dp[10001][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> n;
	dp[1][1] = 1;

	dp[2][1] = 1;
	dp[2][2] = 1;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (i=4;i<=10000;i++) {
		dp[i][1] = dp[i-1][1];
		dp[i][2] = dp[i-2][1] + dp[i-2][2];
		dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
	}
	for (i=0;i<n;i++) {
		cin >> v;
		cout << dp[v][1] + dp[v][2] + dp[v][3] << endl;
	}

	return 0;
}
