#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, d, ans, s;
	cin >> n;
	for (d=0,i=n;i;i/=10, d++) {}

	for (i=n-(d*9);i<=n;i++) {
		for (s=i,d=i;d;d/=10) {
			s += d % 10;
		}
		if (s == n) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}
