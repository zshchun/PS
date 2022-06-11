#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, ans = 0;
	string a, b;
	cin >> a >> b;
	for (i=1;i<=a.size();i++) {
		for (j=1;j<=b.size();j++) {
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			if (ans < dp[i][j])
				ans = dp[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}
