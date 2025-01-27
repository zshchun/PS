#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
int dp[201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int i, j, d, p;
	for (i=1;i<=m;i++) {
		cin >> d >> p;
		for (j=n;j>=d;j--)
			dp[j] = max(dp[j], dp[j-d] + p);
	}
	cout << dp[n] << endl;

	return 0;
}
