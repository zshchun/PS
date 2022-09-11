#include <bits/stdc++.h>
using namespace std;
int dp[20];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, i, k, n, j, s;
	cin >> t;
	while(t--) {
		cin >> k >> n;
		for (j=1;j<=n;j++)
			dp[j] = j;
		for (i=1;i<=k;i++) {
			s = 0;
			for (j=1;j<=n;j++) {
				s += dp[j];
				dp[j] = s;
			}
		}
		cout << s << "\n";
	}
	return 0;
}
