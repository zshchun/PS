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
		ans = 0;
		ll d = n + (n&1);
		ll u = n*2;
		vector<ll> a(n);
		for (i=0;i<(n & ~3);i++) {
			if (i%2 == 0) {
				a[i] = u;
				u++;
			} else {
				a[i] = d;
				d++;
			}
		}
		if (n % 4 == 1) {
			a[n-1] = 0;
		} else if (n % 4 == 2) {
			a[n-3]++;
			a[n-2] = 0;
			a[n-1] = a[n-3] ^ (a[n-3]-1) | 1;
		} else if (n % 4 == 3) {
			a[n-3] = 2;
			a[n-2] = 1;
			a[n-1] = 3;
		}
		for (i=0;i<n;i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
