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
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		ans = 0;
		ll mx = max(n, m);
		ll mn = min(n, m);
		if (n == 1 && m == 1) {
			cout << max(n, m)-1 << endl;
			continue;
		} else if (n == 1 || m == 1) {
			cout << max(n, m) << endl;
			continue;
		}
		ans = (mn-1) * 2 + mx;
		cout << ans << endl;
	}
	return 0;
}
