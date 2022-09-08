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
		if (n&1) { // odd
			for (i=1;i<=3;i++)
				cout << i << ' ';
			for (;i<=n-2;i++) {
				if (i&1) cout << i-1 << ' ';
				else cout << i+1 << ' ';
			}
			for (;i<=n;i++)
				cout << i << ' ';
		} else {
			for (i=1;i<=n-2;i++) {
				if (i&1) cout << i+1 << ' ';
				else cout << i-1 << ' ';
			}
			for (;i<=n;i++)
				cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}
