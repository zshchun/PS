#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[1001][1001];

int ncr(int n, int r) {
	if (r == 0 || n == r)
		return 1;
	if (!dp[n][r])
		dp[n][r] = (ncr(n-1, r-1) + ncr(n-1, r)) % 10007;
	return dp[n][r];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, R, ans;
	cin >> N >> R;
	ans = ncr(N, R);
	cout << ans << endl;
	return 0;
}
