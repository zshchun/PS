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
		for (i=0;i<n;i++)
			cin >> a[i];
		ll l, r;
		for (i=1;i<n;i<<=1) {
			for (j=0;j<n;j+=i<<1) {
				if (a[j] > a[j+i]) {
					ans++;
					for (k=0;k<i;k++)
						swap(a[j+k], a[j+i+k]);
				}
			}
		}
		if (is_sorted(a.begin(), a.end()))
			cout << ans << endl;
		else
			cout << "-1\n";
	}
	return 0;
}
