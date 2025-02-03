#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n, ans = 0;
	cin >> n;

	for (i=1;i<=n;i++)
		cin >> a[i];

	for (i=1;i<=n;i++) {
		for (j=0;j<i;j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(dp[i], ans);
			}
		}
	}
	cout << ans << endl;

	return 0;
}
