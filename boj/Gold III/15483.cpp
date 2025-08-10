#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	// edit distance
	string s, t;
	cin >> s >> t;
	for (i=0;i<=s.size();i++) {
		for (j=0;j<=t.size();j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
		}
	}
	cout << dp[s.size()][t.size()] << endl;
	return 0;
}
