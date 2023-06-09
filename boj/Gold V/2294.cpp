#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, k, ans = INF;
vector<int> coin;

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, v;
	cin >> n >> k;
	for (i=0;i<n;i++) {
		cin >> v;
		if (v > 10000) continue;
		coin.push_back(v);
	}
	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end());

	fill(dp+1, dp+10001, INF);

	for (int c : coin) {
		for (i=c;i<=k;i++) {
			dp[i] = min(dp[i], dp[i-c] + 1);
		}
	}

	if (dp[k] == INF)
		cout << "-1\n";
	else
		cout << dp[k] << endl;

	return 0;
}
