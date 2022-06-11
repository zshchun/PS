#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, a, b, c, aa, bb, cc, m, i;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		cc = 0;
		m = 1<<30;
		aa = a;
		bb = b;
		if (bb == 1) {
			bb++;
			cc++;
		}
		if (bb == a) {
			bb++;
			cc++;
		}
		if (aa < bb) {
			cout << cc+1 <<'\n';
			continue;
		}
		for(b=bb;b<=aa;b++) {
			a = aa;
			c = cc;
			while (a) {
				a /= b;
				c++;
			}
			if (m < c)
				break;
			m = c;
			cc++;
		}
		cout << m << '\n';
	}
	return 0;
}
