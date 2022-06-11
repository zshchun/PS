#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll a[5], i, s = 0;
	for (i=0;i<5;i++) {
		cin >> a[i];
		s += a[i] * a[i];
	}
	cout << s%10 << "\n";
	return 0;
}
