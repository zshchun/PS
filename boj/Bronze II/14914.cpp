#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, a, b;
	cin >> a >> b;
	for (i=1;i<=min(a,b);i++) {
		if (a % i == 0 && b % i == 0) {
			cout << i << ' ' << a / i << ' ' << b / i << endl;
		}
	}
	return 0;
}
