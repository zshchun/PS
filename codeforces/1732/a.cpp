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
		for (i=0;i<n;i++)
			cin >> a[i];
		for (j=0,i=0;i<n;i++) j = __gcd(j, a[i]);
		if (j == 1) {
			cout << 0 << endl;
			continue;
		}
		k = a[n-1];
		a[n-1] = __gcd(a[n-1], n);
		for (j=0,i=0;i<n;i++) j = __gcd(j, a[i]);
		if (j == 1) {
			cout << 1 << endl;
			continue;
		}
		a[n-1] = k;
		a[n-2] = __gcd(a[n-2], n-1);
		for (j=0,i=0;i<n;i++) j = __gcd(j, a[i]);
		if (j == 1) {
			cout << 2 << endl;
			continue;
		}
		cout << 3 << endl;
	}
	return 0;
}
