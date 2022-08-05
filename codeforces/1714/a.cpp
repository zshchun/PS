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
		ll h;
		cin >> n >> h >> m;
		ans = 10000;
		ll now = h * 60 + m;
		vector<ll> s(n);
		for (i=0;i<n;i++) {
			cin >> l >> r;
			k = l * 60 + r;
			if (k < now) {
				ans = min(ans, k + 1440 - now);
			} else {
				ans = min(ans, k-now);
			}
		}
		cout << (ans/60) << ' ' << (ans%60) << endl;
	}
	return 0;
}
