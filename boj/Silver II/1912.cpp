#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, ans = -INF;
int a[100001];
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		dp[i] = max(dp[i-1] + a[i], a[i]);
		if (ans < dp[i])
			ans = dp[i];
	}

	cout << ans << endl;
	return 0;
}
