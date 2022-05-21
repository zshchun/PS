#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, a, p, x, m = 1LL<<60;
	cin>>n;
	while(n--) {
		cin>>a>>p>>x;
		if (x-a > 0) {
			m = min(p, m);
		}
	}
	if (m == 1LL<<60)
		cout << "-1\n";
	else
		cout << m << "\n";
	return 0;
}
