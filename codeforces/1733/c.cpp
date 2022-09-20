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

void op(ll &l, ll &r, ll a, ll b) {
	if ((l+r) % 2 == 0) {
		l = r;
	} else {
		r = l;
	}
	cout << a << " " << b << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k;
	cin >> TC;
	while(TC--) {
		cin >> n;
		vector<ll> a(n);
		bool ok = true;
		for (i=0;i<n;i++) {
			cin >> a[i];
			if (i && a[i-1] > a[i])
				ok = false;
		}
		cout << n-1 << endl;
		if (n-1 == 0) continue;
		op(a[0], a[n-1], 1, n);
		for (i=1;i<n-1;i++) {
			if ((a[i] + a[j]) % 2 == 0)
				op(a[i], a[n-1], i+1, n);
			else
				op(a[0], a[i], 1, i+1);
		}
	}
	return 0;
}
