#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int dp[1001];
int a[1001];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		for (j=0;j<=i;j++) {
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
	return 0;
}
