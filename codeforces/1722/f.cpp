#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k, v2, v3;
	cin >> TC;
	while(TC--) {
		cin >> n >> m;
		ans = 0;
		string s;
		vector<vector<ll>> a(n+2, vector<ll>(m+2));
		
		for (i=1;i<=n;i++) {
			cin >> s;
			for (j=1;j<=m;j++) {
				if (s[j-1] == '*')
					a[i][j] = 1;
			}
		}
		bool ok = 1;
		for (i=1;i<=n;i++) {
			for (j=1;j<=m;j++) {
				if (a[i][j]) {
					if (a[i-1][j-1] + a[i-1][j] + a[i+0][j-1] + a[i+0][j] < 3 && \
					    a[i-1][j] + a[i-1][j+1] + a[i+0][j] + a[i+0][j+1] < 3 && \
					    a[i+0][j-1] + a[i+0][j] + a[i+1][j-1] + a[i+1][j] < 3 && \
					    a[i+0][j] + a[i+0][j+1] + a[i+1][j] + a[i+1][j+1] < 3)
						ok = false;

					k = a[i-1][j-1] + a[i-1][j] + a[i-1][j+1] + \
					     a[i+0][j-1] + a[i+0][j] + a[i+0][j+1] + \
					     a[i+1][j-1] + a[i+1][j] + a[i+1][j+1];
					if (k > 3) ok = false;
				}
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
