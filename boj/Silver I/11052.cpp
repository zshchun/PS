#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[10001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j;
	cin >> n;
	for (i=1;i<=n;i++)
		cin >> a[i];
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if (i >= j)
				dp[i] = max(dp[i-j] + a[j], dp[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
