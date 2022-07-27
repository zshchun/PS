#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, l, i, c;
	cin >> T;
	string a, b;
	while (T--) {
		cin >> l >> a >> b;
		a += '1';
		b += '1';
		c = 0;
		for (i=0;i<l;i++) {
			c += a[i]-'0' + a[i]-'1';
			if ((a[i] == b[i]) != (a[i+1] == b[i+1]) && c) {
				cout << "NO\n";
				break;
			}
		}
		if (i == l)
			cout << "YES\n";
	}

	return 0;
}

