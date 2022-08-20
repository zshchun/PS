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
	ll T, i, j, k, z, l, r;
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		vector<ll> a(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		if (a[n-1] < n-1) {
			cout << "-1\n";
			continue;
		}
		bool ok = true;
		for (i=n-2;i>=0;i--) {
			while (a[i] >= a[i+1]) {
				a[i] /= 2;
				ans++;
			}
			if (a[i] >= a[i+1] || a[i] < i) {
				ok = false;
				break;
			}
		}
		if (ok)
			cout << ans << endl;
		else
			cout << "-1\n";
	}
	return 0;
}
