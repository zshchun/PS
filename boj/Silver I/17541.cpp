#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, C, T, i, c, l, r, mid, acc;
	cin >> N >> C >> T;
	vector<ll> popcorn(N);
	ll total = 0;
	for (i=0;i<N;i++) {
		cin >> popcorn[i];
		total += popcorn[i];
	}
	l = 0;
	r = total;
	while (r-l > 1) {
		mid = (l + r) / 2;
		c = 1;
		acc = 0;
		for (i=0;i<N;i++) {
			if (popcorn[i] > mid*T) {
				c = C + 1;
				break;
			}
			acc += popcorn[i];
			if (acc > mid*T) {
				acc = popcorn[i];
				c++;
			}

		}
		if (c > C)
			l = mid;
		else
			r = mid;
	}
	cout << r << endl;
	return 0;
}
