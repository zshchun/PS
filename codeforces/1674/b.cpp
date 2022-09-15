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
		char c, d;
		cin >> c >> d;
		ll ans = (c-'a')*25;
		if (d > c)
			ans += d-'a';
		else
			ans += d-'a'+1;
		cout << ans << endl;
	}
	return 0;
}
