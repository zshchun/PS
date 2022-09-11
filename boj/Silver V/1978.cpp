#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i, n, a, j, c;
	bool f;
	cin >> n;
	c = 0;
	for (i=0;i<n;i++) {
		f = true;
		cin >> a;
		if (a <= 1) continue;
		for (j=2;j<=(a>>1);j++) {
			if (a % j == 0) {
				f = false;
				break;
			}
		}
		if (f) c++;
	}
	cout << c << '\n';

	return 0;
}

