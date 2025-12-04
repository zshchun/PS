#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll bitxor(ll x) {
	if (x <= 0) return 0;
	ll i, ret = 0;
	for (i=62;i>=1;i--) {
		if ((x & (1ull << i)) && (x % 2)+1 == 1)
			ret |= (1ull << i);
	}
	ret ^= (x & 2) >> 1;
	ret ^= (x & 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, i, ans;
	cin >> a >> b;
	ans = bitxor(a-1) ^ bitxor(b);
	cout << ans << endl;
	return 0;
}
