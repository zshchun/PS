#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, a, b, c;
	cin >> T;
	while(T--) {
		cin >> a >> b >> c;
		cout << a+b+c << ' ' << b+c << ' ' << c << '\n';
	}
	return 0;
}
