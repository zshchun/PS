#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
#define INF 123456789
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		ll x;
		cin >> n >> x;
		ans = 0;
		vector<ll> a(n);
		cin >> a[0];
		ll mn = a[0]-x, mx = a[0]+x;
		for (i=1;i<n;i++) {
			cin >> a[i];
			l = a[i] - x;
			r = a[i] + x;
			if (max(mn, l) <= min(mx, r)) {
				mn = max(mn, l);
				mx = min(mx, r);
			} else {
				ans++;
				mn = a[i]-x;
				mx = a[i]+x;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
