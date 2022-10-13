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
		vector<ll> a(n);
		vector<ll> s(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
			if (i)
				s[i] = s[i-1] + a[i];
			else
				s[i] = a[i];
		}
		ll ans = INF;
		ll sum, prev;
		bool ok;
		for (i=0;i<n;i++) {
			prev = i;
			sum = 0;
			ok = true;
			k = i+1;
			for (j=i+1;j<n;j++) {
				sum += a[j];
				if (sum == s[i]) {
					sum = 0;
					k = max(k, j-prev);
					prev = j;
				} else if (sum > s[i]) {
					ok = false;
					break;
				}
			}
			if (!sum && ok) {
				ans = min(k, ans);
			} else {
				ans = min(n, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
