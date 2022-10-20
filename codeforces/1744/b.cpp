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
		cin >> n >> k;
		ll sum[2] = { 0, };
		ll cnt[2] = { 0, };
		for (i=1;i<=n;i++) {
			cin >> j;
			if (j%2 == 0) {
				sum[0] += j;
				cnt[0]++;
			} else {
				sum[1] += j;
				cnt[1]++;
			}
		}
		for (i=0;i<k;i++) {
			ll x, y;
			cin >> x >> y;
			if (y % 2) {
				sum[!x] += sum[x] + cnt[x] * y;
				cnt[!x] += cnt[x];
				cnt[x] = 0;
				sum[x] = 0;

			} else {
				sum[x] += cnt[x] * y;
			}
			cout << sum[0] + sum[1] << endl;;
		}
	}
	return 0;
}
