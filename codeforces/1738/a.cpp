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
		vector<ll> a[2];
		vector<ll> b(n);
		for (i=0;i<n;i++)
			cin >> b[i];
		for (i=0;i<n;i++) {
			cin >> k;
			a[b[i]].push_back(k);
		}
		sort(a[0].begin(), a[0].end());
		sort(a[1].begin(), a[1].end());
		ll last = 0;
		if (a[0].size() == a[1].size()) {
			if (a[0].front() < a[1].front()) {
				ans += a[0].front();
				a[0].front() = 0;
				last = 0;
			} else {
				ans += a[1].front();
				a[1].front() = 0;
				last = 1;
			}
		} else {
			last = a[0].size() < a[1].size();
		}
		while (!a[0].empty() && !a[1].empty()) {
			ans += a[0].back() * 2;
			ans += a[1].back() * 2;
			a[0].pop_back();
			a[1].pop_back();
		}
		for (ll &x : a[0]) ans += x;
		for (ll &x : a[1]) ans += x;
		cout << ans << endl;
	}
	return 0;
}
