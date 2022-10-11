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
		vector<ll> a(n);
		vector<ll> s(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
			if (i)
				s[i] = s[i-1] + a[i];
			else
				s[i] = a[i];
		}
		ll ans = INF;
		for (i=0;i<n;i++) {
			ll mx = s.back();
			if (mx % s[i] != 0) continue;
			bool ok = true;
			ll idx = i;
			k = i + 1;
			for (j=2;j<=mx/s[i];j++) {
				auto p = lower_bound(s.begin(), s.end(), s[i] * j);
				if (p == s.end() || *p != s[i] * j) {
					ok = false;
					break;
				}
				ll x = p - s.begin();
				k = max(k, x-idx);
				idx = x;
			}
			if (ok) {
				ans = min(k, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
