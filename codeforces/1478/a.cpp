#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, i, j, c, p, s, ms;
	cin >> t;
	for (i=0;i<t;i++) {
		cin >> n;
		p = 0;
		s = 1;
		ms = 1;
		for (j=0;j<n;j++) {
			cin >> c;
			if (p == c) {
				s++;
				if (s > ms)
					ms = s;
			} else {
				s = 1;
			}
			p = c;
		}
		cout << ms << "\n";
	}
	return 0;
}
