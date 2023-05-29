#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
#define endl "\n"
vector<pa> a;
ll ans;
ll dp[10001];

ll dfs(ll money) {
	ll cal, price, mx = 0;
	if (money <= 0) return 0;
	if (dp[money] != -1)
		return dp[money];
	for (pa &p : a) {
		tie(cal, price) = p;
		if (money < price) break;
		mx = max(mx, dfs(money-price)+cal);
	}
	dp[money] = mx;
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, mm, i, c, p, pp;
	char ch;
	float d;
	while (1) {
		cin >> n >> m >> ch >> mm;
		m = m * 100 + mm;
		if (n == 0 && m == 0) {
			break;
		}

		a.clear();
		fill(dp, dp+10001, -1);

		for (i=0;i<n;i++) {
			cin >> c >> p >> ch >> pp;
			p = p * 100 + pp;
			a.push_back(pa(c, p));
		}
		sort(a.begin(), a.end(), [&](const pa &lhs, const pa &rhs) {
			return lhs.second < rhs.second;
		});

		ans = dfs(m);

		cout << ans << endl;
	}

	return 0;
}
