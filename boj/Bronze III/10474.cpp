#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	while (1) {
		cin >> x >> y;
		if (!x && !y) break;
		cout << (x / y) << ' ' << (x % y) << " / " << y << endl;
	}
	return 0;
}
