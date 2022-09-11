#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long map = 0;
	int n[10], i, r, cnt = 0;
	for (i=0;i<10;i++) {
		cin >> n[i];
		r = n[i] % 42;
		if (!(map & (1UL << r))) {
			cnt++;
			map |= (1UL << r);
		}
	}
	cout << cnt << "\n";
	return 0;
}
