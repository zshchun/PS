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
		vector<ll> a(n);
		for (i=0;i<n;i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		bool ok = true;
		for (i=1;i<n;i++) {
			if (a[i-1] >= a[i]) ok = false;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
