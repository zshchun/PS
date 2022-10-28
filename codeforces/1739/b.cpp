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
		vector<ll> b;
		for (i=0;i<n;i++)
			cin >> a[i];
		ans = a[0];
		b.push_back(ans);
		for (i=1;i<n;i++) {
			if (a[i] && ans >= a[i]) {
				ans = -1;
				break;
			}
			ans += a[i];
			b.push_back(ans);
		}
		if (ans == -1)
			cout << ans << endl;
		else {
			for (i=0;i<n;i++)
				cout << b[i] << ' ';
			cout << endl;
		}

	}
	return 0;
}
