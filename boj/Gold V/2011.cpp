#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int dp[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, x;
	string s, t;
	cin >> s;
	t = '0' + s;
	n = s.size();
	dp[0] = 1;

	for (i=1;i<=n;i++) {
		x = (t[i-1] - '0') * 10;
		x += t[i] - '0';
		bool found = false;
		if (x >= 10 && x <= 26) {
			dp[i] += dp[i-2];
			found = true;
		}
		if (t[i] >= '1' && t[i] <= '9') {
			dp[i] += dp[i-1];
			found = true;
		}
		if (!found) {
			cout << "0\n";
			return 0;
		}
		dp[i] %= 1000000;
	}
	cout << dp[n] << endl;
	return 0;
}
