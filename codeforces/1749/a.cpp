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
		cin >> n >> m;
		vector<ll> r(9);
		vector<ll> c(9);
		bool ok = false;
		for (i=0;i<m;i++) {
			cin >> x >> y;
			c[x]++;
			r[y]++;
		}
		for (i=1;i<=n;i++) {
			if (!c[i] || !r[i])
				ok = true;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
