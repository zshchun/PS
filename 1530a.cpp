#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N, n, ans, m;
	cin >> T;
	while(T--) {
		cin >> N;
		n = 0;
		m = 0;
		i = N;
		while (i) {
			if (i % 10 > m) m = i % 10;
			i /= 10;
			n++;
		}
//		ans = m > n ? m : n;
		ans = m;
		cout << ans << '\n';
	}
	return 0;
}
