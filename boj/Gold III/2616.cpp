#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int psum[50001]; // prefix sum
int dp[4][50001];
int a[50001];
int n, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, k, mx;
	cin >> n;
	for (i=1;i<=n;i++) {
		cin >> a[i];
		psum[i] = psum[i-1] + a[i];
	}
	cin >> mx;
	for (i=1;i<=3;i++) {
		for (j=i*mx;j<=n;j++) {
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-mx] + psum[j] - psum[j-mx]);
		}
	}
	cout << dp[3][n] << endl;
	return 0;
}
