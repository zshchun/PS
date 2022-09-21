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
	ll TC, i, j, k, x;
	cin >> TC;
	while(TC--) {
		cin >> n >> m;
		string s[n];
		ans = INF;
		for (i=0;i<n;i++) {
			cin >> s[i];
		}
		for (i=0;i<n;i++) {
			for (j=i+1;j<n;j++) {
				x = 0;
				for (k=0;k<m;k++) {
					x += abs(s[i][k] - s[j][k]);
				}
				ans = min(x, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
