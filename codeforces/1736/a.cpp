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
		vector<ll> a(n);
		vector<ll> b(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		ll zero=0, one=0;
		for (i=0;i<n;i++) {
			cin >> b[i];
			if (a[i] != b[i]) {
				if (a[i] == 0)
					zero++;
				else
					one++;
			}
		}
		if (zero+one == 0) {
			cout << 0 << endl;
		} else if (zero == one) {
			cout << 1 << endl;
		} else {
			if (zero > 0 && one > 0)
				ans = 1;
			ans += abs(zero-one);
			cout << ans << endl;
		}
	}
	return 0;
}
