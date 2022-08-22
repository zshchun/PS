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
	ll a, b, c, d;
	while(T--) {
		cin >> a >> b >> c >> d;
		ll x = a * d;
		ll y = b * c;
		if (x == y) {
			cout << 0 << endl;
		} else if (x == 0 || y == 0 || x%y == 0 || y%x == 0) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
	return 0;
}
