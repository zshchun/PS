#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	double ans;
	cin >> TC;
	while(TC--) {
		cin >> n;
		ans = 0;
		vector<ll> a(n);
		vector<ll> t(n);
		for (i=0;i<n;i++)
			cin >> a[i];

		ll mx = -INF;
		ll mn = INF;
		for (i=0;i<n;i++) {
			cin >> t[i];
			mx = max(a[i]+t[i], mx);
			mx = max(a[i]-t[i], mx);
			mn = min(a[i]-t[i], mn);
			mn = min(a[i]+t[i], mn);
		}
		cout << fixed << setprecision(10) << (mx+mn)/2.0 << endl;

	}
	return 0;
}
