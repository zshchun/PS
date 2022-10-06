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
		ll mn = INF;
		for (i=0;i<n;i++) {
			cin >> a[i];
			if (mn > a[i])
				mn = a[i];
		}
		for (i=1;i<n;i++) {
			k = mn * 2 - 1;
			ans += (a[i] - 1) / k;
		}

		cout << ans << endl;
	}
	return 0;
}
