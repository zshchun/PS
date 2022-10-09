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
	ll TC, i, j, k, d;
	cin >> TC;
	while(TC--) {
		cin >> n >> k;
		ans = 0;
		vector<ll> a(k);
		for (i=0;i<k;i++)
			cin >> a[i];
		ll d = INF;
		bool ok = true;
		if (k == 1) {
			cout << "Yes\n";
			continue;
		}
		for (i=k-1;i>0;i--) {
			if (a[i] - a[i-1] > d)
				ok = false;
			d = a[i] - a[i-1];
		}
		j = n - k + 1;
		if (a[0] > d * j)
			ok = false;
		if (ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
