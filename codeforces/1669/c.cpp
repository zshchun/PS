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
		ans = 0;
		vector<ll> a(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		bool ok = true;
		ll parity = a[0] % 2;
		for (i=0;i<n;i+=2)
			if (a[i] % 2 != parity) ok = false;
		parity = a[1] % 2;
		for (i=1;i<n;i+=2)
			if (a[i] % 2 != parity) ok = false;
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
