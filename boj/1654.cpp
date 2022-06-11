#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
ll d[10001];

ll get_n(ll m) {
	ll i, n = 0;
	if (m == 0) return 0;
	for (i=0;i<k;i++) {
		n += d[i] / m;
	}
	return n;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, j, s=0, l, r, m, ans=0, nn;
	cin>>k>>n;
	for (i=0;i<k;i++) {
		cin >> d[i];
		s = max(s, d[i]);
	}
	r = s;
	l = 1;
	s = 0;

	while (l<= r) {
		m = (r+l) /2;
		nn = get_n(m);
		if (nn >= n) {
			if (get_n(m+1) < n)
				break;
			else
				l = m+1;
		} else if (nn < n) {
			r = m-1;
		}
	}
	cout << m << "\n";
	return 0;
}
