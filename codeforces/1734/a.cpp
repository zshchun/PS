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
		ans = INF;
		vector<ll> a(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		for (i=0;i<n-2;i++) {
			ll x = a[i];
			ll y = a[i+1];
			ll z = a[i+2];
			ans = min(ans, abs(y-z)+abs(y-x));
		}
		cout << ans << endl;
	}
	return 0;
}
