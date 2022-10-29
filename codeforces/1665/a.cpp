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
		ll a, b, c, d;
		d = 1;
		c = 1;
		a = 1;
		b = n - a -  c - d;
		cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	}
	return 0;
}
