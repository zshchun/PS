#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, step;
	cin >> n;
	step = 0;
	for (i=1;i<=n;i+=step) {
		step++;
		if (i <= n && n < i+step) {
			ll x = n - i;
			cout << step-x  << " " << x+1 << endl;
			break;
		}
	}
	return 0;
}
