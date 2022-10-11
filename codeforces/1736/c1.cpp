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
		vector<ll> a(n+1);
		vector<ll> b(n+1);
		for (i=1;i<=n;i++) {
			cin >> a[i];
		}
		ll l, r;
		for (l=1,r=1;l<=n;l++) {
			while (r<=n && a[r] >= r-l+1) r++;
			ans += r - l;
		}
		cout << ans << endl;
	}
	return 0;
}
