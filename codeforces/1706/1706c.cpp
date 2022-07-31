#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<ll> a(n);
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		for (i=1;i<=n-2;i+=2) {
			ans += max(0ll, max(a[i-1], a[i+1]) + 1 - a[i]);
		}
		bool even = !(n % 2);
		if (even) {
			ll t = ans;
			for (i=n-2;i>=1;i-=2) {
				t -= max(0ll, max(a[i-2], a[i]) + 1 - a[i-1]);
				t += max(0ll, max(a[i-1], a[i+1]) + 1 - a[i]);
				ans = min(t, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
