#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll a[1001];
ll dp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, N;
	cin >> N;
	for (i=1;i<=N;i++)
		cin >> a[i];
	for (i=1;i<=N;i++) {
		for (j=0;j<i;j++) {
			if (a[i] > a[j] && dp[j] + a[i] > dp[i])
				dp[i] = dp[j] + a[i];
		}
	}

	cout << *max_element(dp+1, dp+N+1) << endl;
	return 0;
}
