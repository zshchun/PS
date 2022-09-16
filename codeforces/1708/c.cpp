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
	ll TC, i, j, k, q, l;
	cin >> TC;
	while(TC--) {
		cin >> n >> q;
		ans = 0;
		vector<ll> a(n);
		vector<ll> b(n+1);
		string s;
		k = 0;
		for (i=0;i<n;i++) {
			cin >> a[i];
			if (a[i] <= q)
				s += "1";
			else
				s += "0";
		}

		ll k = 0;
		for (i=n-1;i>=0;i--) {
			if (a[i] > k && k < q) {
				s[i] = '1';
				k++;
			}
		}
		cout << s << endl;
	}
	return 0;
}
