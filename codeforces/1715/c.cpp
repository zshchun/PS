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
	cin >> n >> m;
	ans = 0;
	vector<ll> a(n+1);
	for (i=1;i<=n;i++) {
		cin >> a[i];
		ans += n-i+1;
		if (a[i-1] != a[i])
			ans += (i-1) * (n - i + 1);
//			ans += i;
//		else
//			ans += i + i * (n-i);
	}
	for (i=0;i<m;i++) {
		cin >> l >> r;
		if (a[l] != r) {
			if (l > 0 && a[l-1] == r && a[l-1] != a[l]) {
				ans -= (l-1) * (n - l + 1);
			} else if (l > 0 && a[l-1] != r && a[l-1] == a[l]) {
				ans += (l-1) * (n - l + 1);
			}
			if (l < n && a[l+1] == r && a[l] != a[l+1]) {
				ans -= (l) * (n - l);
			} else if (l < n && a[l+1] != r && a[l] == a[l+1]) {
				ans += (l) * (n - l);
			}
			a[l] = r;
		}
		cout << ans << endl;
	}
	return 0;
}
