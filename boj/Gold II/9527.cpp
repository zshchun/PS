#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll ones[55];
ll ans;

ll get_bit_one(ll x) {
	ll ret = x & 1;
	for (ll i = 54; i >= 1; i--) {
		ll bit = (1LL << i);
		if (x & bit) {
			ret += ones[i-1] + (x - bit + 1);
			x &= ~bit;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, a, b, ans = 0;
	cin >> a >> b;

	ones[0] = 1;
	for (i=1;i<55;i++)
		ones[i] = 2 * ones[i-1] + (1LL << i);

	ans = get_bit_one(b) - get_bit_one(a - 1);
	cout << ans << endl;
	return 0;
}
