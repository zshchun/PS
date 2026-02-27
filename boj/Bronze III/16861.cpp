#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, n;
	cin >> n;
	for (i=n;i<=1234567890;i++) {
		j = i;
		k = 0;
		while (j) {
			k += j % 10;
			j /= 10;
		}
		if (i % k == 0) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
