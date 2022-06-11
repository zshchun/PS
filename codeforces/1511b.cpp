#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll r[] = { 0, 1, 10 ,100 ,1000 ,10000 ,100000 ,1000000 ,10000000 ,100000000 ,1000000000 ,10000000000, 100000000000 };
ll e[] = { 0, 9, 99 ,999 ,9999 ,99999 ,999999 ,9999999 ,99999999 ,999999999 ,9999999999 ,99999999999, 999999999999 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, a, b, c, j;
	cin >> T;
	while(T--) {
		cin >> a >> b >>c ;
//		bool found = false;
		ll ra, rb;
		ra = r[a];
		rb = r[b];
		if (r[b] > r[a])
			rb += r[c];
		else
			ra += r[c];
		cout << ra << ' '<< rb << '\n';
///		for (i=r[a];i<=e[a] && !found;i++) {
//			for (j=r[b];j<=e[b] && !found;j++) {
//				int g = __gcd(i, j);
////				cout << i<<":"<<j<<":"<<g << '\n' << flush;
//				if (g >= r[c] && g <= e[c]) {
//					cout << i << " " << j << '\n';
//					found = true;
//				}
//			}
//		}
	}
	return 0;
}
