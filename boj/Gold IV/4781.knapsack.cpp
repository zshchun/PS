#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

ll dp[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char ch;
	ll n, p, pp, i, m, mm, c;
	while (1) {
		cin >> n >> m >> ch >> mm;
		m = m * 100 + mm;
		if (n == 0 && m == 0)
			break;

		fill(dp, dp+m+1, 0);
		vector<pa> a;

		for (i=0;i<n;i++) {
			cin >> c >> p >> ch >> pp;
			p = p * 100 + pp;
			a.push_back(pa(c, p));
		}
		sort(a.begin(), a.end(), [&](const pa &lhs, const pa &rhs) {
			return lhs.second < rhs.second;
		});

		// knapsack
		for (i=1;i<=m;i++) {
			for (pa &x : a) {
				ll cal = x.first;
				ll price = x.second;
				if (i < price)
					break;
				dp[i] = max(dp[i], dp[i-price]+cal);
			}
		}
		cout << dp[m] << endl;
	}

	return 0;
}
