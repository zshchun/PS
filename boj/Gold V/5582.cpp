#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int dp[4001][4001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	int i, j, ans = 0;
	cin >> s >> t;
	// LCS Longest Common Substring
	for (i=1;i<=s.size();i++) {
		for (j=1;j<=t.size();j++) {
			if (s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				ans = max(ans, dp[i][j]);
			} else {
				dp[i][j] = 0;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
