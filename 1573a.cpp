#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, d, n, ret;
	char c;
	cin >> T;
	while (T--) {
		ret = 0;
		cin >> d;
		for (i=1;i<=d;i++) {
			cin >> c;
			if (i == d) {
				ret += c-'0';
			} else {
				if (c != '0')
					ret += c-'0' + 1;
			}
		}
		cout << ret << '\n';
	}
	return 0;
}
