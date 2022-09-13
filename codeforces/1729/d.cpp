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
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		ans = 0;
		vector<ll> a(n);
		vector<ll> b(n);
		vector<ll> c(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		for (i=0;i<n;i++) {
			cin >> b[i];
			c[i] = b[i] - a[i];
		}
		sort(c.begin(), c.end());
		ll l, r;
		for (l=0;l<n-1;l++) {
			r = n-1;
			ll limit = (r - l+1) / 2;
			k = 0;
			ll x = 0;
			ll nr = 0;
			while (l < r) {
				if (k + c[l] + c[r] >= 0) {
					x++;
					k = 0;
					l++; r--;
					nr = 0;
				} else {
					l++;
				}
			}
			ans = max(ans, x);
			if (ans >= limit) break;
		}
		cout << ans << endl;
	}
	return 0;
}
