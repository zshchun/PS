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
		cin >> n;
		ans = 0;
		ll xu=0, xd=0;
		ll yu=0, yd=0;
		ll x, y;
		for (i=0;i<n;i++) {
			cin >> x >> y;
			xu = max(xu, x);
			yu = max(yu, y);
			xd = min(xd, x);
			yd = min(yd, y);
		}
		ans = abs(xu-xd)*2 + abs(yu-yd)*2;
		cout << ans << endl;
	}
	return 0;
}
