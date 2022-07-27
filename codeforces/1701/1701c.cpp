#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pl;
#define endl "\n"
#define MOD 1000000007
ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, j, k, x, l, r, ans;
	cin >> T;
	while(T--) {
		ll w;
		cin >> w >> n;
		vector<ll> a(w, 0);
		for (i=0;i<n;i++) {
			cin >> x;
			a[--x]++;
		}
		l = 0;
		r = 2 * n;
		while (l <= r) {
			m = (l+r)/2;
			ll rem=0, e=0;
			for (i=0;i<w;i++) {
				if (a[i] < m) {
					rem += (m-a[i])/2;
				} else {
					e += a[i]-m;
				}
			}
			if (rem < e)
				l = m+1;
			else
				r = m-1;
		}
		cout << l << endl;
	}
	return 0;
}
