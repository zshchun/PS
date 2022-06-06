#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, x, v, ans;
	vector<ll> a, c;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		a.resize(n);
		c.resize(m);
		vector<bool> used(m, 0);
		ans = 0;
		for (i=0;i<n;i++)
			cin >> a[i];
		for (i=0;i<m;i++)
			cin >> c[i];

		sort(a.begin(), a.end(), [&](const ll &lhs, const ll &rhs) {
			return c[lhs-1] > c[rhs-1];
		});
		j = 0;
		for (i=0;i<n;i++) {
			ll present = c[j];
			ll money = c[a[i]-1];
			if (present < money) {
				ans += present;
				j++;
			} else {
				ans += money;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
