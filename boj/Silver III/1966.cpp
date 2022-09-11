#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, nn, m, i, j, s;
	int q[10001];
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (i=0;i<n;i++)
			cin >> q[i];
		s = 0;
		for (i=0;i<n;i++) {
			nn = n;
			for (j=i;j<n;j++) {
				if (q[j] > q[i]) {
					if (i == m)
						m = n;
					q[n] = q[i];
					n++;
					break;
				}
			}
			if (n == nn)
				s++;
			if (i == m)
				break;
		}
		cout << s << "\n";
	}

	return 0;
}
