#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	cin >> n;
	while (n > 1) {
		for (i=2;i<=n;i++) {
			if (n % i == 0) {
				cout << i << endl;
				n /= i;
				break;
			}
		}
	}
	return 0;
}
