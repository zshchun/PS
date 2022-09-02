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
		ll last = 0;
		vector<ll> a(n);
		vector<ll> idx(n);
		ans = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
			a[i]--;
		}
		for (i=0;i<n;i++)
			idx[a[i]] = i;
		r = n - 1;
		while (r>0 && a[r-1] <= a[r]) r--;
		if (r <= 0) {
			cout << "0\n";
			continue;
		}
		l = 0;
		set<ll> s;
		for (i=0;i<n;i++) {
			s.insert(a[i]);
			r = max(r, idx[a[i]]);
			if (i+1 >= r) break;
		}
		cout << s.size() << endl;
	}
	return 0;
}
