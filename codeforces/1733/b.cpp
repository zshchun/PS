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
	ll TC, i, j, k, x, y;
	cin >> TC;
	while(TC--) {
		cin >> n >> x >> y;
		if ((x && y) || (!x && !y)) {
			cout << "-1\n";
			continue;
		}
		if (x == 0) swap(x, y);
		if (((n-1) % x) != 0) {
			cout << "-1\n";
			continue;
		}
		k = 1;
		for (i=1;i<n;i++) {
			if ((i-1) % x == 0) {
				k = i + 1;
			}
			cout << k << ' ';
		}
		cout << endl;
	}
	return 0;
}
