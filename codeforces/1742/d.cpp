#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
ll n, m, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		ans = -1;
		vector<ll> a(1001, -1);
		for (i=1;i<=n;i++) {
			cin >> j;
			a[j] = i;
		}
		for (i=1;i<=1000;i++) {
			for (j=1;j<=1000;j++) {
				if (a[i] == -1 || a[j] == -1) continue;
				if (__gcd(i, j) == 1) {
					ans = max(ans, a[i] + a[j]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
