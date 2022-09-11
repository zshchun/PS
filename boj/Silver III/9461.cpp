#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i;
	cin >> T;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (i=4;i<=100;i++)
		dp[i] = dp[i-2] + dp[i-3];
	while (T--) {
		cin >> i;
		cout << dp[i] << '\n';
	}
	return 0;
}
