#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, R, C, m, r, c, i, x, ans=0;
	cin >> N >> R >> C;
	for (x=1, i=0;i<N;i++)
		x *= 2;
	r = R;
	c = C;
	m = (x * x) >>1;
	for (i=x>>1;i;i>>=1,m>>=2) {
		if (r >= i) {
			ans += m;
			r -= i;
		}
	}

	m = (x * x) >> 2;
	for (i=x>>1;i;i>>=1,m>>=2) {
		if (c >= i) {
			ans += m;
			c -= i;
		}
	}
	cout << ans << '\n';

	return 0;
}
