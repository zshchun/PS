#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789
ll M, max_n;
ll dp[4000001];
ll ans[100001];

// pascal's triangle
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k, i, j, idx;
	cin >> M;
	vector<tup> q;
	for (i=0;i<M;i++) {
		cin >> n >> k;
		q.push_back(tup(n, k, i));
		if (k == 0 || n == k)
			ans[i] = 1;
		max_n = max(n, max_n);
	}

	sort(q.begin(), q.end());

	idx = 0;
	dp[0] = 1;

	for (i=1;i<=max_n;i++) {
		for (j=i;j>0;j--) {
			dp[j] = (dp[j] + dp[j-1]) % 1000000007;
		}
		while (idx < q.size() && get<0>(q[idx]) == i) {
			tie(n, k, j) = q[idx];
			ans[j] = dp[k];
			idx++;
		}
	}

	for (i=0;i<q.size();i++)
		cout << ans[i] << endl;

	return 0;
}
