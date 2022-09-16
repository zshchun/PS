#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __uint128_t u128;
typedef pair<ll,ll> pa;
#define endl "\n"
#define MOD 1000000007
#define INF (1LL<<60)
ll n, m, q;

bool check(vector<ll> &a, vector<ll> &ans, ll m) {
	ll i, nq = q;
	for (i=0;i<n;i++)
		ans[i] = 0;
	for (i=0;i<m;i++) {
		if (a[i] <= nq) 
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	for (i=m;i<n;i++) {
		if (a[i] <= nq) {
			ans[i] = 1;
		} else {
			ans[i] = 1;
			nq--;
		}
	}
	if (nq >= 0)
		return true;
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll TC, i, j, k, l, r;
	cin >> TC;
	while(TC--) {
		cin >> n >> q;
		vector<ll> a(n);
		vector<ll> ans(n);
		for (i=0;i<n;i++)
			cin >> a[i];
		l = 0;
		r = n-1;
		while (l<=r) {
			m = (l + r) / 2;
			if (check(a, ans, m)) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		check(a, ans, l);
		for (i=0;i<n;i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
