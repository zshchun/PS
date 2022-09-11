#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, i, v, v2=0, v5=0;
	cin >> x;
	for (i=2;i<=x;i++) {
		v = i;
		while (v % 2 == 0) {
			v /= 2;
			v2++;
		}
		v = i;
		while (v % 5 == 0) {
			v /= 5;
			v5++;
		}
	}
	cout << min(v2, v5) << "\n";
	return 0;
}
