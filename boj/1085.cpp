#include <bits/stdc++.h>
using namespace std;
int main() {
	int x, y, w, h, m, n;
	cin >> x >> y >> w >> h;
	m = min(w-x, x);
	n = min(h-y, y);
	m = min(m, n);
	cout << m << "\n";
	return 0;
}
