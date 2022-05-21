#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n[30];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, j, x, o, mn=1LL<<50;
	cin >> N;
	for(i=0;i<N;i++) cin >>n[i];

	for(i=0;i< 1LL <<(N-1);i++) {
		x = 0; o = 0;
		for (j=0;j<N;j++) {
			o |= n[j];
			if (j==N-1 || i & 1<<j) {
				x ^= o;
				o = 0;
			}
		}
		mn = min(mn, x);
	}

	cout << mn << '\n';
	return 0;
}
