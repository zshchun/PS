#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll dp[100001];

ll dfs(ll r) {
	ll i, cnt = INF;
	if (r == 0)
		return 0;
	if (dp[r])
		return dp[r];
	for (i=1;i<=sqrt(r);i++) {
		cnt = min(cnt, dfs(r-i*i) + 1);
	}
	dp[r] = cnt;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, ans = 0;
	cin >> N;
	ans = dfs(N);

	cout << ans << endl;

	return 0;
}
