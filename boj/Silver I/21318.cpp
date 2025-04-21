#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, q, x, y;
	cin >> n;
	for (i=1;i<=n;i++)
		cin >> a[i];
	for (i=1;i<=n;i++) {
		dp[i] = dp[i-1];
		if (a[i-1] > a[i])
			dp[i]++;
	}

	cin >> q;
	for (i=0;i<q;i++) {
		cin >> x >> y;
		cout << dp[y] - dp[x] << endl;
	}
	return 0;
}
