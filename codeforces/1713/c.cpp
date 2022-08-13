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

ll b[100001];
int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	ll T, i, j, k, z, l, r;
	l = 0;
	j = 0;
	for (i=0;i<100001;i++) {
		if (i > l) {
			j++;
			l = j * j;
		}
		b[i] = l;
	}
	cin >> T;
	while(T--) {
		cin >> n;
		ans = 0;
		vector<ll> a(n+1, -1);
		for (l=n-1;l>=0;l=r-1) {
			m = b[l];
			r = m - l;
			for (i=l;i>=r;i--) {
				j = m - i;
				a[j] = i;
				a[i] = j;
			}
		}
		for (i=0;i<n;i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
