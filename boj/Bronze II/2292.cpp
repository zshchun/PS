#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, r, s, e;
	cin >> n;
	e = 1;
	r = 1;
	while (n > e) {
		e += 6 * r;
		r++;
	}
	cout << r << "\n";
	return 0;
}
