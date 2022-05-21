#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, w, h, p, l;
	cin >> T;
	while(T--) {
		cin >> w >> h;
		l = w*(h+1) + h*(w+1);
		p = (w+1) * (h+1);
		cout << l - (p - 1) << "\n";
	}
	return 0;
}
