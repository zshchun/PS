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
	ll T, i, j, k, z, l, r, x, y, d;
	cin >> T;
	while(T--) {
		cin >> n >> m >> x >> y >> d;
		if ((m <= y + d || x - d <= 1) && (y-d <= 1 || x+d >= n)) {
			cout << "-1\n";
			continue;
		}
		cout << n+m-2 << endl;
	}
	return 0;
}
