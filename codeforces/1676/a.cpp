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
		cin >> l;
		j = 0; k = 0;
		for (i=0;i<3;i++) {
			j += l % 10;
			l /= 10;
		}
		for (i=0;i<3;i++) {
			k += l % 10;
			l /= 10;
		}
		if (j == k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
