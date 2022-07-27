#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k, b;
	cin>>t;
	while (t--) {
		cin>>n>>k;
		if (n % 2 == 0) {
			b = k%n;
		} else {
			b = (k+(k-1)/(n/2))%n;
		}
		if (b == 0)
			b = n;
		cout << b << '\n';
	}
	return 0;
}
