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
		vector<ll> b(n);
		vector<ll> c(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		for (i=0;i<n;i++)
			cin >> b[i];
		for (i=0;i<n;i++) {
			cout << *lower_bound(b.begin(), b.end(), a[i])-a[i] << ' ';
		}
		cout << endl;
		r = n-1;
		for (i=n-1;i>=0;i--) {
			c[i] = b[r] - a[i];
			if (i && a[i] > b[i-1])
				r = i - 1;
		}
		for (i=0;i<n;i++)
			cout << c[i] << ' ';
		cout << endl;
	}
	return 0;
}
