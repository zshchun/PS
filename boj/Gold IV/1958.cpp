#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[101][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k;
	string s, t, r;
	cin >> s >> t >> r;
	for (i=1;i<=s.size();i++) {
		for (j=1;j<=t.size();j++) {
			for (k=1;k<=r.size();k++) {
				if (s[i-1] == t[j-1] && t[j-1] == r[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				else
					dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
			}
		}
	}

	cout << dp[s.size()][t.size()][r.size()] << endl;
	return 0;
}
