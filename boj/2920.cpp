#include <bits/stdc++.h>
using namespace std;
int main() {
	int p, i, n, d;
	p = 0;
	d = 0;
	for (i=0;i<8;i++) {
		cin >> n;
		if (p) {
			if (d) {
				if ((d > 0 && p - n < 0) || (d < 0 && p - n > 0)) {
					cout << "mixed\n";
					return 0;
				}
			}
			d = p - n;
		}
		p = n;
	}
	if (d < 0) {
		cout << "ascending\n";
	} else if ( d > 0 ) {
		cout << "descending\n";
	}

	return 0;
}
