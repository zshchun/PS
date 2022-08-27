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
		if ((n == 1 || m == 1) && abs(n-m) > 1) {
			cout << "-1\n";
			continue;
		}
		ans = min(n, m)*2 - 2;
		r = abs(n-m);
		if (r)
			ans += (r/2)*4 + (r%2);
		cout << ans << endl;
	}
	return 0;
}
