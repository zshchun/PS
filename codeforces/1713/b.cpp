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
		ll prev;
		vector<ll> a(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << "YES\n";
			continue;
		}
		bool ok = true;
		ll dir = 0;
		for (i=1;i<n;i++) {
			if (a[i-1] < a[i] && dir != 1) {
				if (dir == 2) ok = false;
				dir = 1;
			} else if (a[i-1] > a[i] && dir != 2) {
				dir = 2;
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
