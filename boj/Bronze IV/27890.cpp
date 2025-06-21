#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, x;
	cin >> x >> n;;
	for (i=1;i<=n;i++) {
		if (x % 2) {
			x = (x * 2) ^ 6;
		} else {
			x = (x / 2) ^ 6;
		}
	}
	cout << x << endl;
	return 0;
}
