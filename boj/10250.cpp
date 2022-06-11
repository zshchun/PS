#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, w, h, n, r;
	cin >> t;
	while (t--) {
		cin >>h>>w>>n;
		r = n % h;
		if (r == 0)
			r = h*100 + (n/h);
		else
			r = r*100 + (n/h+1);
		cout << r <<"\n";
	}
	return 0;
}
