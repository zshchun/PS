#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
#define endl "\n"
#define MOD 1000000007
#define INF 1234567890
ll n, m, ans;

bool v[2][200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> m;
		ans = INF;
		vector<vector<ll>> a(2, vector<ll>(m));
		vector<vector<ll>> dp(2, vector<ll>(m+1, -INF));
		for (i=0;i<2;i++)
			for (j=0;j<m;j++)
				cin >> a[i][j];
		for (i=0;i<2;i++)
			for (j=m-1;j>=0;j--)
				dp[i][j] = max({dp[i][j+1]-1, a[i][j], a[i^1][j] - ((m-j)*2-1)});
		z = a[0][0]-1;
		for (j=0;j<m;j++) {
			ll s = j&1;
			ans = min(ans, max({z, dp[s][j+1] - 2*j-1, a[s^1][j] - 2*m+1})); //
			z = max(z, a[s^1][j] - j*2 - 1);
			ans = min(ans, max(z, dp[s^1][j+1] - 2*j - 2));
			if (j < m-1)
				z = max(z, a[s^1][j+1] - j*2 - 2);
		}
		cout << (ans+2*m) << endl;
	}
	return 0;
}
