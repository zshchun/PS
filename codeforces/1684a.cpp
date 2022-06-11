#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, n, m;
	cin >> T;
	while(T--) {
		cin >> n;
		m = 10;
		if (n<100) {
			cout << n%10 << '\n';
			continue;
		}
		while (n) {
			if (m > n%10)
				m = n % 10;
			n /= 10;
		}
		cout << m << '\n';;
	}
	return 0;
}
