#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
typedef tuple<int,int,int> tup;
#define endl "\n"
#define INF 123456789

vector<pa> a[1500001];
int dp[1500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, n, ans = 0;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> j >> k;
		if (j+i > n) continue;
		a[j+i].push_back(pa(j, k));
	}

	for (i=1;i<1500001;i++) {
		dp[i] = dp[i-1];
		for (auto [x, y] : a[i]) {
			dp[i] = max(dp[i], dp[i-x]+y);
			ans = max(ans, dp[i]);
		}
	}
	cout << ans << endl;
	return 0;
}
