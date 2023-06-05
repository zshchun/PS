#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans = INF, N;

int a[1001];
int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int i, j;
	for (i=1;i<=N;i++) {
		cin >> a[i];
	}

	for (i=1;i<=N;i++) {
		dp[i] = a[i];
		for (j=1;j<=i;j++) {
			dp[i] = min(dp[i], dp[j] + a[i-j]);
		}
	}

	cout << dp[N] << endl;
	return 0;
}
