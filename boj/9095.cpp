#include <bits/stdc++.h>
using namespace std;
int calc(int s, int m) {
	if (s == m) {
		return 1;
	} else if (s > m) {
		return 0;
	}
	return calc(s+1, m) + calc(s+2, m) + calc(s+3, m);
}
int main() {
	int n, i, a, r;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a;
		r = calc(0, a);
		cout << r << '\n';
	}
	return 0;
}
