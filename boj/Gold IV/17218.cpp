#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
string dp[41][41];
string ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	string s, t;
	// Longest Common Substring
	cin >> s >> t;
	for (i=1;i<=s.size();i++) {
		for (j=1;j<=t.size();j++) {
			if (s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1] + s[i-1];
				if (dp[i][j].size() > ans.size())
					ans = dp[i][j];
			} else {
				if (dp[i-1][j].size() > dp[i][j-1].size())
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i][j-1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
