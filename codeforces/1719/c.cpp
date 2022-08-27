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
	ll T, i, j, k, z, l, r, q;
	cin >> T;
	while(T--) {
		ll mx = 0;
		cin >> n >> q;
		vector<ll> a(n);
		vector<vector<ll>> w(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
			if (i > 0) {
				if (a[i] > a[mx]) mx = i;
				w[mx].push_back(i);
			}
		}
		for (i=0;i<q;i++) {
			cin >> l >> k;
			l--;
			ans = lower_bound(w[l].begin(), w[l].end(), k+1) - w[l].begin();
			if (mx == l) {
				ans += max(0ll, k - n + 1);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
