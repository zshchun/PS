#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, a[3], p, x, m, i;
	cin>>t;
	while(t--) {
		cin>>p;
		m = 1LL<<62;
		for (i=0;i<3;i++) {
			cin>>a[i];
			if (p < a[i])
				m = min(a[i] - p, m);
			else if (p >= a[i] && p % a[i] == 0)
				m = 0;
			else
				m = min(m, a[i]-p%a[i]);
		}
		cout << m << "\n";
	}
	return 0;
}
