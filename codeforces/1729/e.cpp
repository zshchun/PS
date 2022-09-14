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
ll query(ll start, ll end) {
	cout << "? " << start << " " << end << endl << flush;
	ll q;
	cin >> q;
	return q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, l, r;
	ans = 4;
	while(1) {
		i = query(1, ans);
		if (i == -1) {
			cout << "! " << ans -1 << endl;
			return 0;
		}
		j = query(ans,  1);
		if (i != j) {
			cout << "! " << i + j << endl;
			return 0;
		}
		ans++;
	}
	return 0;
}
